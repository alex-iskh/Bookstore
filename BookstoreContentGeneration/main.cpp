#include <QCoreApplication>
#include <QtSql>
#include <QTextStream>
#include "generators.h"

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
        qDebug()<<"Database connection failed: "<<database.lastError();
        return false;
    }
    return true;
}

bool executeQuery(QString& str)
{
    QSqlQuery query;
    if (!query.exec(str)) {
        qDebug()<<"Query execution failed";
        return false;
    }
    return true;
}

bool languagesCreationQuery()
{
    QString content = "INSERT INTO languages (language) "
            "VALUES ('English'), ('Russian'), ('German'), ('French'), ('Spanish');";
    return (executeQuery(content));
}

bool categoriesCreationQuery()
{
    QString content = "INSERT INTO categories (category_name) "
            "VALUES ('Arts & Photography'), ('Biographies & Memoirs'), ('Business & Money'), ('Children''s Books'), "
            "('Comics & Graphic Novels'), ('Computers & Technology'), ('Cookbooks, Food & Wine'), "
            "('Crafts, Hobbies & Home'), ('Education & Teaching'), ('Engineering & Transportation'), "
            "('Health, Fitness & Dieting'), ('History'), ('Humor & Entertainment'), ('Law'), ('Literature & Fiction'), "
            "('Medical Books'), ('Mystery, Thriller & Suspense'), ('Parenting & Relationships'), "
            "('Politics & Social Sciences'), ('Reference'), ('Religion & Spirituality'), ('Romance'), ('Science & Math'), "
            "('Science Fiction & Fantasy'), ('Self-Help'), ('Sports & Outdoors'), ('Travel');";
    return (executeQuery(content));
}

bool publishersCreationQuery()
{
    int num = 20+random(20);
    QString content = "INSERT INTO publishers (publisher_name) VALUES";
    for(int i = 1; i<num; ++i)
    {
        content += (" ('"+generatePublisherName()+"'),");
    }
    content += (" ('"+generatePublisherName()+"');");
    return (executeQuery(content));
}

bool booksCreationQuery()
{
    int x;
    int num = 2900+random(200);
    QSqlQuery query;
    //распределим вероятность языка книги как 10:7:1:1:1 (eng, rus, ger, fre, spa)
    int lang[num];
    for(int i = 0; i<num; ++i)
    {
        x = random(20);
        if (x<10) lang[i] = 1;
        else
            if (x<17) lang[i] = 2;
            else switch(x)
            {
                case 17: lang[i] = 3; break;
                case 18: lang[i] = 4; break;
                default: lang[i] = 5;
            }
    }
    QString content;
    for(unsigned int i = 0; i<num; ++i)
    {
        content = "INSERT INTO books (title, ISBN, release_year, description, publisher_id, category_id, language_id, original_id, price, in_stock, filename, cover_filename) VALUES";
        //title
        switch (lang[i])
        {
        case 1:
            content += (" ('"+generateEnglishTitle()+"', "); break;
        case 2:
            content += (" ('"+generateRussianTitle()+"', "); break;
        case 3:
            content += (" ('"+generateGermanTitle()+"', "); break;
        case 4:
            content += (" ('"+generateFrenchTitle()+"', "); break;
        default:
            content += (" ('"+generateSpanishTitle()+"', "); break;
        }
        //ISBN
        content += ("'"+generateISBN(i)+"', ");
        //release_year
        content += (QString::number(1800+random(215))+", ");
        //description
        content += ("'"+generateDescription()+"', ");
        //publisher_id
        if (!query.exec("SELECT * FROM publishers;")) return false;
        x = 1+random(query.size());
        content+= (QString::number(x)+", ");
        //category_id
        content += (QString::number(1+random(27))+", ");
        //language_id
        content += (QString::number(lang[i])+", ");
        //original_id
        //сначала заполним этот столбец значением NULL, после формирования таблицы создадим связи
        content += "NULL, ";
        //price
        content += (QString::number((100+random(20000))/100)+", ");
        //in_stock
        x = random(10);
        if (x<9) content += "TRUE, ";
        else content += "FALSE, ";
        //filename
        content += "'books\\\\test.txt', ";
        //cover_img
        x = random(8);
        content += "'covers\\\\cover"+QString::number(x)+".jpg');";
        if (!executeQuery(content)) return false;
    }
    //original_id
    for(int i = 0; i<num; ++i)
    {
        x = random(10);
        if (x<3)
        {//с вер. 30% книга будет явл. переводом
            do x = random(num);
            while ((x==i)||(lang[x]==lang[i]));
            content = "UPDATE books SET original_id="+QString::number(x+1)+" WHERE book_id="+QString::number(i+1)+";";
            if (!executeQuery(content)) return false;
        }
    }
    return true;
}

bool authorsCreationQuery()
{
    bool exists = false;
    int i = 1;
    int x;
    int from;
    int to;
    int num = 50+random(100);
    int lang;
    QString content1 = "INSERT INTO authors (author_name) VALUES";
    QString content2 = "INSERT INTO books_authors (book_id, author_id) VALUES";
    QSqlQuery query;
    while (i<=num)
    {
        from = 1800+random(215);
        to = from+1+random(70);
        x = random(20);
        //определим язык и сделаем выборку по книгам на этом языке с данными временными рамками, затем выберем из них случайные и назначим автору
        if (x<10) lang = 1;
        else
            if (x<17) lang = 2;
            else switch(x)
            {
                case 17: lang = 3; break;
                case 18: lang = 4; break;
                default: lang = 5;
            }
        if (!query.exec("SELECT book_id, release_year, language_id FROM books WHERE language_id="+QString::number(lang)+" AND release_year BETWEEN "+QString::number(from)+" AND "+QString::number(to)+";")) return false;
        if (query.size()>0)
        {
            for (int j = 0; j < query.size(); ++j)
            {
                query.next();
                //мат. ожидание числа книжек у автора равно 30-ти (если в выборке по языку и годам 30 и более книг)
                x = random(query.size());
                if (x<30)
                {
                    content2 += (" ("+QString::number(query.value(0).toInt())+", "+QString::number(i)+"),");
                    exists = true;
                }
            }
        }
        if (exists) //если с автором связана хоть одна книга, он считается существующим, добавляем его в таблицу и записываем авторство за книгами
        {
            switch (lang)
            {
            case 1:
                content1 += (" ('"+generateEnglishName()+"');"); break;
            case 2:
                content1 += (" ('"+generateRussianName()+"');"); break;
            case 3:
                content1 += (" ('"+generateGermanName()+"');"); break;
            case 4:
                content1 += (" ('"+generateFrenchName()+"');"); break;
            default:
                content1 += (" ('"+generateSpanishName()+"');"); break;
            }
            if (!executeQuery(content1)) return false;
            content1 = "INSERT INTO authors (author_name) VALUES";
            content2.chop(1);    //удаляем лишнюю запятую
            content2 += ";";
            if (!executeQuery(content2)) return false;
            content2 = "INSERT INTO books_authors (book_id, author_id) VALUES";
            ++i;
            exists = false;
        }
    }
    //могут остаться книги, для которых не указан автор; создадим авторов для них
    for(lang = 1; lang<=5; ++lang)
    {
        if (!query.exec("SELECT book_id, release_year, language_id FROM books WHERE language_id="+QString::number(lang)+" AND book_id NOT IN (SELECT book_id FROM books_authors) ORDER BY release_year;")) return false;
        x = 0;
        for(int j = 0; j<query.size(); ++j)
        {
            query.next();
            if (x == 0)
            {
                num = 10+random(30); //здесь num - число книжек каждого нового автора
                switch (lang)
                {
                case 1:
                    content1 += (" ('"+generateEnglishName()+"');"); break;
                case 2:
                    content1 += (" ('"+generateRussianName()+"');"); break;
                case 3:
                    content1 += (" ('"+generateGermanName()+"');"); break;
                case 4:
                    content1 += (" ('"+generateFrenchName()+"');"); break;
                default:
                    content1 += (" ('"+generateSpanishName()+"');"); break;
                }
                if (!executeQuery(content1)) return false;
                content1 = "INSERT INTO authors (author_name) VALUES";
            }
            content2 = ("INSERT INTO books_authors (book_id, author_id) VALUES ("+QString::number(query.value(0).toInt())+", "+QString::number(i)+");");
            if (!executeQuery(content2)) return false;
            ++x;
            if (x>=num)
            {
                x = 0;
                ++i;
            }
        }
    }
    return true;
}

bool usersCreationQuery()
{
    randomize();
    int x;
    int i;
    int num = 5900+random(200);
    int bookamt;
    int lang;
    QSqlQuery query;
    QString name;
    QString login;
    QString content1;
    QString content2;
    QStringList logins;
    for(i = 0; i<num; ++i)
    {
        content1 = "INSERT INTO users (login, password, email, language_id, user_name, fund, is_banned) VALUES";
        //распределим вероятность предпочитаемого языка пользователя как 9:6:1:1:1:2 (eng, rus, ger, fre, spa, NULL)
        x = random(20);
        if (x<9) lang = 1;
        else
            if (x<15) lang = 2;
            else switch(x)
            {
                case 16: lang = 3; break;
                case 17: lang = 4; break;
                case 18: lang = 5; break;
                default: lang = 0;
            }
        switch (lang)
        {
        case 0:
        case 1:
            name = generateEnglishName(); break;
        case 2:
            name = generateRussianName(); break;
        case 3:
            name = generateGermanName(); break;
        case 4:
            name = generateFrenchName(); break;
        default:
            name = generateSpanishName(); break;
        }
        //login
        login = generateLogin(name);
        while (logins.contains(login))
            login += "0";
        content1 += (" ('"+login+"',");
        logins<<login;
        //password
        content1 += (" '"+login+"',");
        //email
        content1 += (" '"+generateEmail(name)+"',");
        //language_id
        if (lang==0) content1 += " NULL,";
        else content1 += " "+QString::number(lang)+",";
        //user_name
        x = random(3);
        if (x==0) content1 += " NULL,";
        else content1 += " '"+name+"',";
        //fund
        x = random(201);
        content1 += " "+QString::number(x)+",";
        //is_banned
        x = random(60);
        if (x==0) content1 += " TRUE);";
        else content1 += " FALSE);";
        if (!executeQuery(content1)) return false;
        //заполним теперь библиотеку созданного пользователя
        if (lang==0)
            {if (!query.exec("SELECT book_id, language_id FROM books;")) return false;}
        else
            {if (!query.exec("SELECT book_id, language_id FROM books WHERE language_id="+QString::number(lang)+";")) return false;}
        if (query.size()>0)
        {
            bookamt = random(50);   //примерное число книг у пользователя
            for (int j = 0; j < query.size(); ++j)
            {
                query.next();
                x = random(query.size());
                if (x<bookamt)
                {
                    content2 = ("INSERT INTO users_library (user_id, book_id, purchase_date) VALUES ("+QString::number(i+1)+", "+QString::number(query.value(0).toInt())+", '"+generateDate()+"');");
                    if (!executeQuery(content2)) return false;
                }
            }
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream cout(stdout);
    QTextStream cin(stdin);
    QString dbname, dbuser, dbpass, dbhost, dbport;
    cout<<"Database name: ";
    cout.flush();
    dbname = cin.readLine();
    cout<<"\nDatabase user: ";
    cout.flush();
    dbuser = cin.readLine();
    cout<<"\nDatabase pass: ";
    cout.flush();
    dbpass = cin.readLine();
    cout<<"\nDatabase host: ";
    cout.flush();
    dbhost = cin.readLine();
    cout<<"\nDatabase port: ";
    cout.flush();
    dbport = cin.readLine();
    cout<<"\n";
    cout.flush();
    if (createConnection(dbname, dbuser, dbpass, dbhost, dbport))
    {
        randomize();
        if (languagesCreationQuery()&&categoriesCreationQuery()&&publishersCreationQuery()&&booksCreationQuery()&&authorsCreationQuery()&&usersCreationQuery())
            qDebug()<<"Database successfully filled with generated data;";
    }
    return a.exec();
}
