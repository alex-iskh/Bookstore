#include "widgets.h"
#include "sql.h"

namespace bs{

QString getLangName(int id)
{
    switch (id)
    {
        case 1: return "English";
        case 2: return "Russian";
        case 3: return "German";
        case 4: return "French";
        case 5: return "Spanish";
        default: return "None";
    }
}

LoginWindow::LoginWindow(QWidget *parent): QDialog(parent)
{
    setWindowTitle("Login Window");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    isConnected = false;
    loginl = new QLabel("Login:");
    passl = new QLabel("Password:");
    regl = new QLabel("<hr/>Haven't account yet?<br/>Click below to register");
    regl->setAlignment(Qt::AlignHCenter);
    emaill = new QLabel("E-mail:");
    reppassl = new QLabel("Repeat your password:");
    namel = new QLabel("Your real name and surname:");
    langl = new QLabel("Preferred language:");
    dbnamel = new QLabel("Database name:");
    dbuserl = new QLabel("Database user:");
    dbhostl = new QLabel("Host:");
    dbportl = new QLabel("Port:");
    dbpassl = new QLabel("Password:");
    logine = new QLineEdit;
    logine->setMaxLength(45);
    passe = new QLineEdit;
    passe->setMaxLength(45);
    passe->setEchoMode(QLineEdit::Password);
    emaile = new QLineEdit;
    emaile->setMaxLength(45);
    reppasse = new QLineEdit;
    reppasse->setMaxLength(45);
    reppasse->setEchoMode(QLineEdit::Password);
    namee = new QLineEdit;
    namee->setMaxLength(45);
    dbnamee = new QLineEdit("bookstore");
    dbusere = new QLineEdit("admin");
    dbhoste = new QLineEdit("localhost");
    dbporte = new QLineEdit("3306");
    dbpasse = new QLineEdit("admin");
    dbpasse->setEchoMode(QLineEdit::Password);
    loginb = new QPushButton("Log In");
    regb = new QPushButton("Register");
    regokb = new QPushButton("OK");
    regbackb = new QPushButton("Back");
    setb = new QPushButton("Advanced settings");
    langc = new QComboBox;
    QStringList lang = (QStringList()<<"None"<<"English"<<"Russian"<<"German"<<"French"<<"Spanish");
    langc->addItems(lang);

    QRegExpValidator* loginv = new QRegExpValidator(QRegExp("[a-zA-Z0-9_]*"));
    logine->setValidator(loginv);
    QRegExpValidator* emailv = new QRegExpValidator(QRegExp("[a-zA-Z0-9_]*@[a-zA-Z0-9_\\-\\.]*\\.[a-zA-Z]*"));
    emaile->setValidator(emailv);

    QVBoxLayout* loginLayout = new QVBoxLayout;
    loginLayout->setContentsMargins(0,0,0,10);
    loginLayout->addWidget(loginb);
    loginLayout->addWidget(regl);
    loginLayout->addWidget(regb);
    loginLayout->addWidget(setb);
    QVBoxLayout* registerLayout = new QVBoxLayout;
    registerLayout->setContentsMargins(0,0,0,10);
    registerLayout->addWidget(reppassl);
    registerLayout->addWidget(reppasse);
    registerLayout->addWidget(emaill);
    registerLayout->addWidget(emaile);
    registerLayout->addWidget(namel);
    registerLayout->addWidget(namee);
    registerLayout->addWidget(langl);
    registerLayout->addWidget(langc);
    registerLayout->addWidget(regokb);
    registerLayout->addWidget(regbackb);
    QVBoxLayout* settingsLayout = new QVBoxLayout;
    settingsLayout->addWidget(dbnamel);
    settingsLayout->addWidget(dbnamee);
    settingsLayout->addWidget(dbhostl);
    settingsLayout->addWidget(dbhoste);
    settingsLayout->addWidget(dbportl);
    settingsLayout->addWidget(dbporte);
    settingsLayout->addWidget(dbuserl);
    settingsLayout->addWidget(dbusere);
    settingsLayout->addWidget(dbpassl);
    settingsLayout->addWidget(dbpasse);

    loginWidget = new QWidget;
    loginWidget->setLayout(loginLayout);
    registerWidget = new QWidget;
    registerWidget->setLayout(registerLayout);
    settingsWidget = new QWidget;
    settingsWidget->setLayout(settingsLayout);
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(loginl);
    mainLayout->addWidget(logine);
    mainLayout->addWidget(passl);
    mainLayout->addWidget(passe);
    mainLayout->addWidget(loginWidget);
    mainLayout->addWidget(registerWidget);
    mainLayout->addWidget(setb);
    mainLayout->addWidget(settingsWidget);
    this->setLayout(mainLayout);
    emit transformToLogInForm();
    settingsWidget->hide();
    adjustSize();

    connect(setb, SIGNAL(clicked()), this, SLOT(showSettings()));
    connect(regb, SIGNAL(clicked()), this, SLOT(transformToRegisterForm()));
    connect(regbackb, SIGNAL(clicked()), this, SLOT(transformToLogInForm()));
    connect(loginb, SIGNAL(clicked()), this, SLOT(logIn()));
    connect(regokb, SIGNAL(clicked()), this, SLOT(reg()));
}

void LoginWindow::showSettings()
{
    if (settingsWidget->isVisible())
    {
        settingsWidget->hide();
        adjustSize();
    }
    else
    {
        settingsWidget->show();
        adjustSize();
    }
}

void LoginWindow::transformToLogInForm()
{
    loginWidget->show();
    registerWidget->hide();
    loginl->setText("Login:");
    adjustSize();
}

void LoginWindow::transformToRegisterForm()
{
    loginWidget->hide();
    registerWidget->show();
    loginl->setText("Login:\nAllowed latin characters, digits and underlines");
    adjustSize();
}

void LoginWindow::logIn()
{
    if (!isConnected)
    {
        if (createConnection(dbnamee->text(), dbusere->text(), dbpasse->text(), dbhoste->text(), dbporte->text()))
            isConnected = true;
        else
            return;
    }
    int id = authorizationQuery(logine->text(), passe->text());
    if ((id>0)||(id==-1))
    {
        this->done(id);
    }
    else
        passe->setText("");
}

void LoginWindow::reg()
{
    if (passe->text()!=reppasse->text())
    {
        passe->setText("");
        reppasse->setText("");
        QMessageBox* popup = new QMessageBox(QMessageBox::Information, "Reenter your password", "Password and repeated password should be equal", QMessageBox::Ok);
        popup->exec();
        return;
    }
    if (!isConnected)
    {
        if (createConnection(dbnamee->text(), dbusere->text(), dbpasse->text(), dbhoste->text(), dbporte->text()))
            isConnected = true;
        else
            return;
    }
    if (registrationQuery(logine->text(), passe->text(), emaile->text(), namee->text(), langc->currentIndex()))
        emit logIn();
}

MainWindow::MainWindow(int loginid, QWidget *parent) : QTabWidget(parent)
{
    userInfo = getUserInfo(loginid);

    store = new QWidget;
    storeSearche = new QLineEdit;
    storeSearchb = new QPushButton("Search");
    storeMainb = new QPushButton("Main page");
    storeRecomendlist = new QListWidget;
    storeRecomendlist->setResizeMode(QListView::Adjust);
    storeRecomendlist->setFlow(QListView::LeftToRight);
    storeBookw = new QWidget;
    storeTable = new QTableWidget;
    storeTable->setColumnCount(7);
    storeTable->setHorizontalHeaderLabels(QStringList()<<"id"<<"Title"<<"Authors"<<"Release year"<<"Popularity"<<"Category"<<"Price");
    storeTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    storeTable->verticalHeader()->hide();
    storeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    storeTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    storeInfl = new QLabel;
    storeInfl->setWordWrap(true);
    storePricel = new QLabel;
    storePricel->setAlignment(Qt::AlignHCenter);
    storeBuyb = new QPushButton("Buy");
    storeBoughtl = new QLabel("In your library");
    QHBoxLayout* storeToolbarLayout = new QHBoxLayout;
    storeToolbarLayout->addWidget(storeMainb);
    storeToolbarLayout->addStretch(1);
    storeToolbarLayout->addWidget(storeSearche);
    storeToolbarLayout->addWidget(storeSearchb);
    QWidget* storeToolbar = new QWidget;
    storeToolbar->setLayout(storeToolbarLayout);
    QVBoxLayout* right = new QVBoxLayout;
    right->setAlignment(Qt::AlignVCenter);
    right->addWidget(storePricel);
    right->addWidget(storeBuyb);
    right->addWidget(storeBoughtl);
    QWidget* rightw = new QWidget;
    rightw->setLayout(right);
    QHBoxLayout* storeBookLayout = new QHBoxLayout;
    storeBookLayout->addWidget(storeInfl,1);
    storeBookLayout->addWidget(rightw);
    storeBookw->setLayout(storeBookLayout);
    QVBoxLayout* storeLayout = new QVBoxLayout;
    storeLayout->addWidget(storeToolbar);
    storeLayout->addWidget(storeRecomendlist);
    storeLayout->addWidget(storeBookw);
    storeLayout->addWidget(storeTable);
    store->setLayout(storeLayout);
    emit showMainPage();
    addTab(store, "Store");

    library = new QWidget;
    librarySearche = new QLineEdit;
    libraryClearb = new QPushButton("Clear filter");
    libraryReadbg = new QButtonGroup;
    libraryContentlist = new QListWidget;
    libraryContentlist->setResizeMode(QListView::Adjust);
    libraryContentlist->setFlow(QListView::LeftToRight);
    libraryContentlist->setWrapping(true);
    libraryContentlist->setUniformItemSizes(true);
    QHBoxLayout* libraryToolbarLayout = new QHBoxLayout;
    libraryToolbarLayout->addStretch(1);
    libraryToolbarLayout->addWidget(librarySearche);
    libraryToolbarLayout->addWidget(libraryClearb);
    QWidget* libraryToolbar = new QWidget;
    libraryToolbar->setLayout(libraryToolbarLayout);
    QVBoxLayout* libraryLayout = new QVBoxLayout;
    libraryLayout->addWidget(libraryToolbar);
    libraryLayout->addWidget(libraryContentlist);
    library->setLayout(libraryLayout);
    emit showFullLibrary();
    addTab(library, "Library");

    profile = new QWidget;
    profileInfol = new QLabel;
    profileOldpassl = new QLabel("Enter current password to apply changes:");
    profileNewpassl = new QLabel("Change password:");
    profileReppassl = new QLabel("Repeat new password:");
    profileEmaill = new QLabel("Change e-mail:");
    profileNamel = new QLabel("Change name:");
    profileLangl = new QLabel("Change preferred language:");
    profileOldpasse = new QLineEdit;
    profileOldpasse->setEchoMode(QLineEdit::Password);
    profileNewpasse = new QLineEdit;
    profileNewpasse->setEchoMode(QLineEdit::Password);
    profileReppasse = new QLineEdit;
    profileReppasse->setEchoMode(QLineEdit::Password);
    profileEmaile = new QLineEdit;
    profileNamee = new QLineEdit;
    profileLangc = new QComboBox;
    profileLangc->addItems(QStringList()<<"None"<<"English"<<"Russian"<<"German"<<"French"<<"Spanish");
    profileEditb = new QPushButton("Edit profile");
    profileOkb = new QPushButton("Apply");
    profileCancelb = new QPushButton("Cancel");
    profileLogoffb = new QPushButton("Log Off");
    profileXmlb = new QPushButton("Save library to XML file");
    profileSupplyb = new QPushButton("Supply fund");
    profileFundl = new QLabel;
    QVBoxLayout* infoLayout = new QVBoxLayout;
    infoLayout->addWidget(profileInfol);
    infoLayout->addWidget(profileEditb);
    infoLayout->addStretch(1);
    profileInfow = new QWidget;
    profileInfow->setLayout(infoLayout);
    QVBoxLayout* editLayout = new QVBoxLayout;
    editLayout->addWidget(profileNewpassl);
    editLayout->addWidget(profileNewpasse);
    editLayout->addWidget(profileReppassl);
    editLayout->addWidget(profileReppasse);
    editLayout->addWidget(profileEmaill);
    editLayout->addWidget(profileEmaile);
    editLayout->addWidget(profileNamel);
    editLayout->addWidget(profileNamee);
    editLayout->addWidget(profileLangl);
    editLayout->addWidget(profileLangc);
    editLayout->addWidget(profileOldpassl);
    editLayout->addWidget(profileOldpasse);
    QHBoxLayout* editButtonBarLayout = new QHBoxLayout;
    editButtonBarLayout->addStretch(1);
    editButtonBarLayout->addWidget(profileOkb);
    editButtonBarLayout->addWidget(profileCancelb);
    QWidget* editButtonBar = new QWidget;
    editButtonBar->setLayout(editButtonBarLayout);
    editLayout->addWidget(editButtonBar);
    editLayout->addStretch(1);
    profileEditw = new QWidget;
    profileEditw->setLayout(editLayout);
    QVBoxLayout* funcLayout = new QVBoxLayout;
    funcLayout->addWidget(profileLogoffb);
    funcLayout->addWidget(profileXmlb);
    funcLayout->addWidget(profileFundl);
    funcLayout->addWidget(profileSupplyb);
    funcLayout->addStretch(1);
    QWidget* profileFuncbar = new QWidget;
    profileFuncbar->setLayout(funcLayout);
    QHBoxLayout* profileLayout = new QHBoxLayout;
    profileLayout->addWidget(profileInfow);
    profileLayout->addWidget(profileEditw);
    profileLayout->addWidget(profileFuncbar);
    profileLayout->addStretch(1);
    profile->setLayout(profileLayout);
    emit showProfileInfo();
    addTab(profile, "Profile");

    emit showMaximized();

    connect(storeMainb, SIGNAL(clicked()), this, SLOT(showMainPage()));
    connect(storeRecomendlist, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(emitShowBookPage(QListWidgetItem*)));
    connect(storeTable, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(emitShowBookPage(QTableWidgetItem*)));
    connect(storeSearchb, SIGNAL(clicked()), this, SLOT(showSearchResults()));
    connect(storeSearche, SIGNAL(returnPressed()), this, SLOT(showSearchResults()));
    connect(storeBuyb, SIGNAL(clicked()), this, SLOT(purchase()));
    connect(libraryReadbg, SIGNAL(buttonClicked(int)), this, SLOT(openFile(int)));
    connect(librarySearche, SIGNAL(returnPressed()), this, SLOT(showFiltredLibrary()));
    connect(libraryClearb, SIGNAL(clicked()), this, SLOT(showFullLibrary()));
    connect(profileEditb, SIGNAL(clicked()), this, SLOT(showEditForm()));
    connect(profileCancelb, SIGNAL(clicked()),this, SLOT(showProfileInfo()));
    connect(profileOkb, SIGNAL(clicked()),this, SLOT(updateProfile()));
    connect(profileLogoffb, SIGNAL(clicked()),this, SLOT(logOff()));
    connect(profileXmlb, SIGNAL(clicked()),this, SLOT(saveLibraryToXml()));
    connect(profileSupplyb, SIGNAL(clicked()),this, SLOT(openSupplyDialog()));
}

void MainWindow::showMainPage()
{
    getPopular(storeTable, storeRecomendlist, userInfo[4]);
    storeBookw->hide();
    storeRecomendlist->show();
}

void MainWindow::showBookPage(int index)
{
    curBookId = (storeTable->item(index, 0)->text()).toInt();
    if (getBookInfo(storeInfl, storePricel, storeTable->item(index, 0)->text(), userInfo[0]))
    {
        storeBuyb->hide();
        storeBoughtl->show();
    }
    else
    {
        storeBuyb->show();
        storeBoughtl->hide();
    }
    getTranslations(storeTable, userInfo[4], storeTable->item(index, 0)->text());
    storeBookw->show();
    storeRecomendlist->hide();
}

void MainWindow::showSearchResults()
{
    storeBookw->hide();
    storeRecomendlist->hide();
    getSearchResults(storeTable, userInfo[4], storeSearche->text());
}

void MainWindow::showFullLibrary()
{
    getLibrary(libraryContentlist, libraryReadbg, userInfo[0]);
}

void MainWindow::showFiltredLibrary()
{
    getLibrary(libraryContentlist, libraryReadbg, userInfo[0], librarySearche->text());
}

void MainWindow::openFile(int book_id)
{
    QMessageBox* popup = new QMessageBox(QMessageBox::Information, "Temp", "Book opened", QMessageBox::Ok);
    popup->exec();
}

void MainWindow::purchase()
{
    QString price = storePricel->text();
    price.remove(0,5);
    price.chop(5);
    if (userInfo[6].toDouble()>=price.toDouble())
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Information, "Book purchase", "You have $"+userInfo[6]+" on your account\nClick OK to buy this $"+price+" book", QMessageBox::Ok|QMessageBox::Cancel);
        if (popup->exec())
        {
            purchaseTransaction(QString::number(curBookId), userInfo[0]);
            this->showMainPage();
            this->showFullLibrary();
        }
    }
    else
    {
        QMessageBox* popup = new QMessageBox(QMessageBox::Information, "Book purchase", "You have $"+userInfo[6]+" on your account\nYou don't have enough money to make this purchase\nSupply your fund and try operation again", QMessageBox::Ok);
        popup->exec();
    }
}

void MainWindow::showProfileInfo()
{
    profileInfol->setText("<p><big>Login: "+userInfo[1]+"</big></p><p><big>Email: "+userInfo[3]+"</big></p><p><big>Preferred language: "+getLangName(userInfo[4].toInt())+"</big></p><p><big>Name: "+userInfo[5]+"</big></p>");
    profileFundl->setText("<p>Money on account:</p><h2>$"+userInfo[6]+"</h2>");
    profileInfow->show();
    profileEditw->hide();
}

void MainWindow::showEditForm()
{
    profileOldpasse->setText("");
    profileNewpasse->setText("");
    profileReppasse->setText("");
    profileEmaile->setText("");
    profileNamee->setText("");
    profileLangc->setCurrentIndex(userInfo[4].toInt());
    profileInfow->hide();
    profileEditw->show();
}

void MainWindow::updateProfile()
{
    if ((profileOldpasse->text()==userInfo[2])&&((profileNewpasse->text()==profileOldpasse->text())||(profileNewpasse->text()=="")))
    {
        updateUserInfo(userInfo[0], profileNewpasse->text(), profileEmaile->text(), profileNamee->text(), profileLangc->currentIndex(), userInfo[4]);
        userInfo = getUserInfo(userInfo[0].toInt());
        emit showProfileInfo();
    }
    else
    {
        profileNewpasse->setText("");
        profileReppasse->setText("");
        profileOldpasse->setText("");
    }
}

void MainWindow::logOff()
{
    LoginWindow* loginw = new LoginWindow();
    this->hide();
    int id = loginw->exec();
    if (id>0)
    {
        userInfo = getUserInfo(id);
        emit showMainPage();
        emit showFullLibrary();
        emit showProfileInfo();
        this->show();
    }
    else this->close();
}

void MainWindow::saveLibraryToXml()
{
    createXml(userInfo[0]);
}

void MainWindow::openSupplyDialog()
{
    profileSupplyd = new QInputDialog;
    profileSupplyd->setWindowTitle("Supply fund");
    profileSupplyd->setLabelText("Enter the sum of supply:");
    profileSupplyd->setInputMode(QInputDialog::DoubleInput);
    connect(profileSupplyd, SIGNAL(accepted()), this, SLOT(supplyFund()));
    profileSupplyd->show();
}

void MainWindow::supplyFund()
{
    if (updateUserFond(userInfo[0], QString::number(profileSupplyd->doubleValue())))
    {
        userInfo[6] = QString::number(userInfo[6].toDouble()+profileSupplyd->doubleValue());
        profileFundl->setText("<p>Money on account:</p><h2>$"+userInfo[6]+"</h2>");
    }
}

MainWindow::~MainWindow() {}
LoginWindow::~LoginWindow() {}

}
