#ifndef SQL_H
#define SQL_H

#include <QtSql>
#include <QMessageBox>
#include <QListWidget>
#include <QTableWidget>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QDateTime>
#include <QtXml>
#include <QDomDocument>
#include <QDir>

QString sqlString (QString& str)
{
    QString res = str;
    res.replace("'", "''");
    return res;
}

static bool createConnection(QString name, QString user, QString pass, QString host, QString port)
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL");
    database.setDatabaseName(name);
    database.setUserName(user);
    database.setHostName(host);
    database.setPort(port.toInt());
    database.setPassword(pass);
    if (!database.open())
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Warning, "Connect error", "Database connection failed\nCheck your connection settings and try again", QMessageBox::Ok);
        popup->exec();
        return false;
    }
    return true;
}

int authorizationQuery(QString login, QString pass)
{
    if ((login=="admin")&&(pass=="admin")) return -1;
    QString str = "SELECT user_id, is_banned FROM users WHERE login='"+sqlString(login)+"' AND password='"+sqlString(pass)+"';";
    QSqlQuery query;
    if (!query.exec(str))
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", ("Some unexpected error during query execution"), QMessageBox::Ok);
        popup->exec();
        return 0;
    }
    if (query.size()==1)
    {
        query.next();
        if (query.value(1).toString()=="true")
        {
            QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Ban", ("Your account has been banned. Connection refused."), QMessageBox::Ok);
            popup->exec();
            return 0;
        }
        return query.value(0).toInt();//в случае успеха возвращаем id
    }
    QMessageBox* popup = new QMessageBox(QMessageBox::NoIcon, "Incorrect login-password combination", "Unrecognized combination of login and password\nVerify accuracy of login and retype your password again", QMessageBox::Ok);
    popup->exec();
    return 0;
}

bool registrationQuery(QString login, QString password, QString email, QString name, int lang_id)
{
    QString lang, user_name;
    if (!lang_id) lang = "NULL";
    else lang = QString::number(lang_id);
    if (name=="") user_name = "NULL";
    else user_name = "'"+sqlString(name)+"'";
    QString str = "INSERT INTO users (login, password, email, language_id, user_name, fund, is_banned) VALUES ('"+sqlString(login)+"', '"+sqlString(password)+"', '"+sqlString(email)+"', "+sqlString(lang)+", "+user_name+", 0, FALSE);";
    QSqlQuery query;
    if (!query.exec(str))
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", ("Some unexpected error during query execution"), QMessageBox::Ok);
        popup->exec();
        return false;
    }
    return true;
}

QStringList getUserInfo(int userId)
{
    QStringList info;
    info<<QString::number(userId);
    QString str = "SELECT login, password, email, language_id, user_name, fund FROM users WHERE user_id="+QString::number(userId)+";";
    QSqlQuery query;
    if (!query.exec(str))
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution", QMessageBox::Ok);
        popup->exec();
        return QStringList();
    }
    query.next();
    info<<query.value(0).toString()<<query.value(1).toString()<<query.value(2).toString();
    if (query.value(3).isNull()) info<<"NULL";
    else info<<QString::number(query.value(3).toInt());
    info<<query.value(4).toString()<<QString::number(query.value(5).toDouble());
    return info;
}

QString getTitle(QString book_id)
{
    QString title = "";
    QString str = "SELECT title FROM books WHERE book_id="+book_id+";";
    QSqlQuery query;
    if (!query.exec(str))
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution", QMessageBox::Ok);
        popup->exec();
        return title;
    }
    query.next();
    title = query.value(0).toString();
    return title;
}

QString getAuthors(QString book_id)
{
    QString authors = "";
    QString str = "SELECT authors.author_name FROM authors, books_authors WHERE books_authors.book_id="+book_id+" AND authors.author_id=books_authors.author_id;";
    QSqlQuery query;
    if (!query.exec(str))
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution", QMessageBox::Ok);
        popup->exec();
        return authors;
    }
    for(int i = 0; i<query.size(); ++i)
    {
        query.next();
        authors += query.value(0).toString();
        if (i!=(query.size()-1)) authors += ", ";
    }
    return authors;
}

QString getCover(QString book_id)
{
    QString cover = "covers\\default_cover.jpg";
    QString str = "SELECT cover_filename FROM books WHERE book_id="+book_id+";";
    QSqlQuery query;
    if (!query.exec(str))
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution", QMessageBox::Ok);
        popup->exec();
        return cover;
    }
    query.next();
    cover = query.value(0).toString();
    return cover;
}

void getPopular(QTableWidget* top, QListWidget* recomend, QString lang)
{
    while (top->rowCount() > 0)
        top->removeRow(0);
    recomend->clear();
    QString langRestrict = "";
    if (lang!="NULL") langRestrict = "books.language_id="+lang+" and ";
    QString str = "SELECT books.book_id, books.title, books.release_year, count(users_library.user_id) as popularity, categories.category_name, books.price, books.original_id FROM books, users_library, categories WHERE "+langRestrict+"books.in_stock=TRUE AND books.book_id=users_library.book_id AND books.category_id=categories.category_id GROUP BY books.book_id ORDER BY popularity DESC LIMIT 50;";
    QSqlQuery query;
    if (!query.exec(str))
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution", QMessageBox::Ok);
        popup->exec();
        return;
    }
    QString authors;
    QTableWidgetItem* newItem = new QTableWidgetItem;
    QListWidgetItem* newElement;
    QLabel* richText;
    top->setRowCount(query.size());
    for(int i = 0; i<query.size(); ++i)
    {
        query.next();
        //book_id
        newItem->setText(query.value(0).toString());
        top->setItem(i, 0, newItem);
        newItem = new QTableWidgetItem;
        //title
        newItem->setText(query.value(1).toString());
        top->setItem(i, 1, newItem);
        newItem = new QTableWidgetItem;
        //authors
        if (query.value(6).isNull()) authors = getAuthors(query.value(0).toString());
        else authors = getAuthors(query.value(6).toString());
        newItem->setText(authors);
        top->setItem(i, 2, newItem);
        newItem = new QTableWidgetItem;
        //остальное
        for(int j = 2; j<6; ++j)
        {
            newItem->setText(query.value(j).toString());
            top->setItem(i, j+1, newItem);
            newItem = new QTableWidgetItem;
        }
        //заполнение листа
        if (i<10)
        {
            newElement = new QListWidgetItem;
            richText = new QLabel("<p align=\"center\"><img src=\""+getCover(query.value(0).toString())+"\" height=\"125\"><br/><b>"+query.value(1).toString()+"</b><br/>"+authors+"</p>");
            recomend->addItem(newElement);
            newElement->setSizeHint(richText->sizeHint()+QSize(20,20));
            recomend->setItemWidget(newElement,richText);
        }
    }
    top->setColumnHidden(0, true);
}

bool getBookInfo(QLabel* info, QLabel* price, QString book_id, QString user_id)
{
    QString str = "SELECT books.title, books.ISBN, books.release_year, books.description, publishers.publisher_name, categories.category_name, books.original_id, books.price, books.cover_filename FROM books, publishers, categories WHERE books.book_id="+book_id+" AND books.publisher_id=publishers.publisher_id AND books.category_id=categories.category_id;";
    QSqlQuery query;
    if (!query.exec(str))
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution", QMessageBox::Ok);
        popup->exec();
        info->setText("Error");
        price->setText("Error");
        return false;
    }
    query.next();
    QString subTitle;
    if (query.value(6).isNull()) subTitle = "<i>"+query.value(2).toString()+"</i><p>by "+getAuthors(book_id)+"</p>";
    else subTitle = "<i><a href=\""+QString::number(query.value(6).toInt())+"\">"+getTitle(QString::number(query.value(6).toInt()))+"</a>, "+QString::number(query.value(2).toInt())+"</i><p>by "+getAuthors(QString::number(query.value(6).toInt()))+"<br>translated by "+getAuthors(book_id)+"</p>";
    info->setText("<table><tr><td><img src=\""+query.value(8).toString()+"\"></td><td><h1>"+query.value(0).toString()+"</h1><big>"+subTitle+"<p>"+query.value(3).toString()+"</p><p>Category: "+query.value(5).toString()+"<br>ISBN: "+query.value(1).toString()+"<br>Publisher: "+query.value(4).toString()+"</p><p>(Other) translations of this book:</p></big></td></tr></table>");
    price->setText("<h1>$"+QString::number(query.value(7).toDouble())+"</h1>");
    str = "SELECT * FROM users_library WHERE book_id="+book_id+" AND user_id="+user_id+";";
    if (!query.exec(str))
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution", QMessageBox::Ok);
        popup->exec();
        return false;
    }
    if (query.size()) return true;
    return false;
}

void getTranslations(QTableWidget* transl, QString prefLang, QString book_id)
{
    while (transl->rowCount() > 0)
        transl->removeRow(0);
    QString origBook_id;
    QSqlQuery query;
    QString str = "SELECT original_id from books WHERE book_id="+book_id+";";
    if (!query.exec(str))
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution", QMessageBox::Ok);
        popup->exec();
        return;
    }
    if (query.value(0).isNull()) origBook_id = book_id;
    else origBook_id = QString::number(query.value(0).toInt());
    query.finish();
    QString orderChange = "";
    if (prefLang!="NULL") orderChange = "CASE WHEN books.language_id="+prefLang+" THEN 1 ELSE 2 END, ";
    str = "SELECT books.book_id, books.title, books.release_year, count(users_library.user_id) as popularity, categories.category_name, books.price, books.original_id FROM books, users_library, categories WHERE books.original_id="+origBook_id+" AND books.in_stock=TRUE AND books.book_id=users_library.book_id AND books.category_id=categories.category_id GROUP BY books.book_id ORDER BY "+orderChange+"popularity DESC;";
    if (!query.exec(str))
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution", QMessageBox::Ok);
        popup->exec();
        return;
    }
    QString authors;
    QTableWidgetItem* newItem = new QTableWidgetItem;
    transl->setRowCount(query.size());
    for(int i = 0; i<query.size(); ++i)
    {
        query.next();
        //book_id
        newItem->setText(query.value(0).toString());
        transl->setItem(i, 0, newItem);
        newItem = new QTableWidgetItem;
        //title
        newItem->setText(query.value(1).toString());
        transl->setItem(i, 1, newItem);
        newItem = new QTableWidgetItem;
        //переводчики
        authors = getAuthors(query.value(0).toString());
        newItem->setText(authors);
        transl->setItem(i, 2, newItem);
        newItem = new QTableWidgetItem;
        //остальное
        for(int j = 2; j<6; ++j)
        {
            newItem->setText(query.value(j).toString());
            transl->setItem(i, j+1, newItem);
            newItem = new QTableWidgetItem;
        }
    }
    transl->setColumnHidden(0, true);
}

void getSearchResults(QTableWidget* res, QString prefLang, QString key)
{
    while (res->rowCount() > 0)
        res->removeRow(0);
    QString orderChange = "";
    if (prefLang!="NULL") orderChange = "CASE WHEN books.language_id="+prefLang+" THEN 1 ELSE 2 END, ";
    QString str = "SELECT books.book_id, books.title, books.release_year, count(users_library.user_id) as popularity, categories.category_name, books.price, books.original_id FROM books, users_library, categories, books_authors, authors WHERE (books.title LIKE '%"+sqlString(key)+"%' OR books.ISBN LIKE '%"+sqlString(key)+"%' OR authors.author_name LIKE '%"+sqlString(key)+"%') AND books.in_stock=TRUE AND books.book_id=users_library.book_id AND books.category_id=categories.category_id AND books.book_id=books_authors.book_id AND authors.author_id=books_authors.author_id GROUP BY books.book_id ORDER BY "+orderChange+"popularity DESC;";
    QSqlQuery query;
    if (!query.exec(str))
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution", QMessageBox::Ok);
        popup->exec();
        return;
    }
    QString authors;
    QTableWidgetItem* newItem = new QTableWidgetItem;
    res->setRowCount(query.size());
    for(int i = 0; i<query.size(); ++i)
    {
        query.next();
        //book_id
        newItem->setText(query.value(0).toString());
        res->setItem(i, 0, newItem);
        newItem = new QTableWidgetItem;
        //title
        newItem->setText(query.value(1).toString());
        res->setItem(i, 1, newItem);
        newItem = new QTableWidgetItem;
        //авторы или переводчики
        authors = getAuthors(query.value(0).toString());
        newItem->setText(authors);
        res->setItem(i, 2, newItem);
        newItem = new QTableWidgetItem;
        //остальное
        for(int j = 2; j<6; ++j)
        {
            newItem->setText(query.value(j).toString());
            res->setItem(i, j+1, newItem);
            newItem = new QTableWidgetItem;
        }
    }
    res->setColumnHidden(0, true);
}

void purchaseTransaction(QString book_id, QString user_id)
{
    double fund;
    QString str = "SET AUTOCOMMIT=0;";
    QSqlQuery query;
    if (!query.exec(str))
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution", QMessageBox::Ok);
        popup->exec();
        return;
    }
    str = "SELECT fund FROM users WHERE user_id="+user_id+";";
    if (!query.exec(str))
    {
        query.exec("SET AUTOCOMMIT=1;");
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution", QMessageBox::Ok);
        popup->exec();
        return;
    }
    query.next();
    fund = query.value(0).toDouble();
    str = "SELECT price FROM books WHERE book_id="+book_id+";";
    if (!query.exec(str))
    {
        query.exec("SET AUTOCOMMIT=1;");
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution", QMessageBox::Ok);
        popup->exec();
        return;
    }
    query.next();
    if (query.value(0).isNull())
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Error", "This book is not available for sale\nSorry for inconvinience", QMessageBox::Ok);
        popup->exec();
        return;
    }
    fund -= query.value(0).toDouble();
    if (fund<0)
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Error", "Check your fund", QMessageBox::Ok);
        popup->exec();
        return;
    }
    str = "START TRANSACTION;";
    if (!query.exec(str))
    {
        query.exec("ROLLBACK; SET AUTOCOMMIT=1;");
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution", QMessageBox::Ok);
        popup->exec();
        return;
    }
    str = "UPDATE users SET fund="+QString::number(fund)+" WHERE user_id="+user_id+";";
    if (!query.exec(str))
    {
        if (query.exec("ROLLBACK; SET AUTOCOMMIT=1;"))
        {
            QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Try purchase again", QMessageBox::Ok);
            popup->exec();
            return;
        }
        else
        {
            QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution\nAutocommit is off, it may occur problems with updating library and profile information\nPlease, restart the program", QMessageBox::Ok);
            popup->exec();
            return;
        }
    }
    str = "INSERT INTO users_library (user_id, book_id, purchase_date) VALUES ("+user_id+", "+book_id+", '"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+"');";
    if (!query.exec(str))
    {
        if (query.exec("ROLLBACK; SET AUTOCOMMIT=1;"))
        {
            QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Try purchase again", QMessageBox::Ok);
            popup->exec();
            return;
        }
        else
        {
            QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution\nAutocommit is off, it may occur problems with updating library and profile information\nPlease, restart the program", QMessageBox::Ok);
            popup->exec();
            return;
        }
    }
    if (!query.exec("COMMIT;"))
    {
        if (query.exec("ROLLBACK; SET AUTOCOMMIT=1;"))
        {
            QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Try purchase again", QMessageBox::Ok);
            popup->exec();
            return;
        }
        else
        {
            QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution\nAutocommit is off, it may occur problems with updating library and profile information\nPlease, restart the program", QMessageBox::Ok);
            popup->exec();
            return;
        }
    }
    str = "SET AUTOCOMMIT=1;";
    if (!query.exec(str))
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution\nAutocommit is off, it may occur problems with updating profile information\nPlease, restart the program", QMessageBox::Ok);
        popup->exec();
        return;
    }
}

void getLibrary(QListWidget* list, QButtonGroup* btns, QString user_id, QString key = "")
{
    QString filter;
    if (key=="") filter = "";
    else filter = "books.title = '%"+key+"%' AND ";
    QWidget* block;
    QVBoxLayout* blockLayout;
    QLabel* descr;
    QPushButton* button;
    QString authors;
    QListWidgetItem* item;
    list->clear();
    delete btns;
    btns = new QButtonGroup;
    QString str = "SELECT books.book_id, books.original_id, books.cover_filename, books.title, users_library.purchase_date FROM users_library, books WHERE user_id="+user_id+" AND "+filter+"books.book_id=users_library.book_id;";
    QSqlQuery query;
    if (!query.exec(str))
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution", QMessageBox::Ok);
        popup->exec();
        return;
    }
    while(query.next())
    {
        if (query.value(1).isNull()) authors = getAuthors(query.value(0).toString());
        else authors = getAuthors(query.value(1).toString());
        descr = new QLabel("<p align=\"center\"><img src=\""+query.value(2).toString()+"\" width=\"100\"><br><b>"+query.value(3).toString()+"</b><br>"+authors+"<br><small>Added "+query.value(4).toString()+"</small></p>");
        button = new QPushButton("Read");
        blockLayout = new QVBoxLayout;
        blockLayout->addWidget(descr);
        blockLayout->addWidget(button);
        btns->addButton(button, query.value(0).toInt());
        block = new QWidget;
        block->setLayout(blockLayout);
        item = new QListWidgetItem;
        list->addItem(item);
        item->setSizeHint(block->sizeHint()+QSize(20,20));
        list->setItemWidget(item,block);
    }
}

void updateUserInfo(QString user_id, QString password, QString email, QString user_name, int newlang, QString curlang)
{
    QString str = "UPDATE users SET ";
    if (password!="") str += ("password="+sqlString(password)+", ");
    if (email!="") str += ("email="+sqlString(email)+", ");
    if (user_name!="") str += ("user_name="+sqlString(user_name)+", ");
    QString language_id;
    if (newlang) language_id= QString::number(newlang);
    else language_id = "NULL";
    if (language_id!=curlang) str += ("language_id="+language_id+", ");
    str.chop(2);
    str += (" WHERE user_id="+user_id+";");
    QSqlQuery query;
    if (!query.exec(str))
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution", QMessageBox::Ok);
        popup->exec();
    }
}

bool updateUserFond(QString user_id, QString supply)
{
    QString str = "UPDATE users SET fund=fund+"+sqlString(supply)+" WHERE user_id="+user_id+";";
    QSqlQuery query;
    if (!query.exec(str))
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution", QMessageBox::Ok);
        popup->exec();
        return false;
    }
    return true;
}

void createXml(QString user_id)
{
    QString str = "SELECT books.book_id, books.title, books.ISBN, books.release_year, books.original_id FROM books, users_library WHERE users_library.user_id="+user_id+" AND books.book_id=users_library.book_id;";
    QSqlQuery query;
    if (!query.exec(str))
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Critical, "Unexpected error", "Some unexpected error during query execution", QMessageBox::Ok);
        popup->exec();
        return;
    }
    QDomDocument doc("library");
    QDomElement libEl = doc.createElement("library");
    doc.appendChild(libEl);
    QDomElement bookEl;
    QDomElement bookChildEl;
    QDomText text;
    while(query.next())
    {
        //book
        bookEl = doc.createElement("book");
        bookEl.setAttribute("id", query.value(0).toInt());
        if (query.value(4).isNull()) bookEl.setAttribute("is_original", 1);
        else bookEl.setAttribute("is_original", 0);
        libEl.appendChild(bookEl);
        //title
        bookChildEl = doc.createElement("title");
        text = doc.createTextNode(query.value(1).toString());
        bookChildEl.appendChild(text);
        bookEl.appendChild(bookChildEl);
        //ISBN
        bookChildEl = doc.createElement("ISBN");
        text = doc.createTextNode(query.value(2).toString());
        bookChildEl.appendChild(text);
        bookEl.appendChild(bookChildEl);
        //year
        bookChildEl = doc.createElement("year");
        text = doc.createTextNode(query.value(3).toString());
        bookChildEl.appendChild(text);
        bookEl.appendChild(bookChildEl);
        //authors
        bookChildEl = doc.createElement("authors");
        if (query.value(4).isNull()) text = doc.createTextNode(getAuthors(QString::number(query.value(0).toInt())));
        else text = doc.createTextNode(getAuthors(QString::number(query.value(4).toInt())));
        bookChildEl.appendChild(text);
        bookEl.appendChild(bookChildEl);
        //translators
        if (!query.value(4).isNull())
        {
            bookChildEl = doc.createElement("translators");
            text = doc.createTextNode(getAuthors(QString::number(query.value(0).toInt())));
            bookChildEl.appendChild(text);
            bookEl.appendChild(bookChildEl);
        }
    }
    QFile file("my_library.xml");
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream(&file)<<doc.toString();
        file.close();
        QMessageBox* popup = new QMessageBox(QMessageBox::Information, "Done", "File my_library.xml created in application directory", QMessageBox::Ok);
        popup->exec();
    }
}

#endif // SQL_H
