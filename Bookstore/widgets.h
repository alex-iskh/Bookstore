#ifndef WIDGETS_H
#define WIDGETS_H

#include <QMainWindow>
#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QListWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QInputDialog>
#include <QHeaderView>


namespace bs {

class LoginWindow : public QDialog
{
    Q_OBJECT
public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();
private:
    bool isConnected;
    QLineEdit* logine;
    QLineEdit* passe;
    QLineEdit* emaile;
    QLineEdit* reppasse;
    QLineEdit* namee;
    QLineEdit* dbnamee;
    QLineEdit* dbusere;
    QLineEdit* dbhoste;
    QLineEdit* dbporte;
    QLineEdit* dbpasse;
    QComboBox* langc;
    QLabel* loginl;
    QLabel* passl;
    QLabel* regl;
    QLabel* emaill;
    QLabel* reppassl;
    QLabel* namel;
    QLabel* langl;
    QLabel* dbnamel;
    QLabel* dbuserl;
    QLabel* dbhostl;
    QLabel* dbportl;
    QLabel* dbpassl;
    QPushButton* loginb;
    QPushButton* regb;
    QPushButton* regokb;
    QPushButton* regbackb;
    QPushButton* setb;
    QWidget* loginWidget;
    QWidget* registerWidget;
    QWidget* settingsWidget;

private slots:
    void logIn();
    void reg();
    void transformToRegisterForm();
    void transformToLogInForm();
    void showSettings();
};

class MainWindow : public QTabWidget
{
    Q_OBJECT
public:
    explicit MainWindow(int loginid, QWidget *parent = 0);
    ~MainWindow();
private:
    int curBookId;
    QStringList userInfo;
    QWidget* store;
    QWidget* library;
    QWidget* profile;
    QWidget* bookbase;
    QWidget* userbase;
    QLineEdit* storeSearche;
    QPushButton* storeSearchb;
    QPushButton* storeMainb;
    QListWidget* storeRecomendlist;
    QWidget* storeBookw;
    QTableWidget* storeTable;
    QLabel* storeInfl;
    QLabel* storePricel;
    QPushButton* storeBuyb;
    QLabel* storeBoughtl;
    QLineEdit* librarySearche;
    QPushButton* libraryClearb;
    QButtonGroup* libraryReadbg;
    QListWidget* libraryContentlist;
    QLabel* profileInfol;
    QLabel* profileOldpassl;
    QLabel* profileNewpassl;
    QLabel* profileReppassl;
    QLabel* profileEmaill;
    QLabel* profileNamel;
    QLabel* profileLangl;
    QLineEdit* profileOldpasse;
    QLineEdit* profileNewpasse;
    QLineEdit* profileReppasse;
    QLineEdit* profileEmaile;
    QLineEdit* profileNamee;
    QComboBox* profileLangc;
    QPushButton* profileEditb;
    QPushButton* profileOkb;
    QPushButton* profileCancelb;
    QPushButton* profileLogoffb;
    QPushButton* profileXmlb;
    QPushButton* profileSupplyb;
    QLabel* profileFundl;
    QWidget* profileEditw;
    QWidget* profileInfow;
    QInputDialog* profileSupplyd;
private slots:
    void showMainPage();
    void showBookPage(int index);
    void emitShowBookPage(QTableWidgetItem* item)
    {
        emit showBookPage(item->row());
    }
    void emitShowBookPage(QListWidgetItem* item)
    {
        emit showBookPage(item->listWidget()->row(item));
    }
    void showSearchResults();
    void purchase();
    void showFullLibrary();
    void showFiltredLibrary();
    void openFile(int book_id);
    void showProfileInfo();
    void showEditForm();
    void updateProfile();
    void saveLibraryToXml();
    void openSupplyDialog();
    void supplyFund();
    void logOff();
};

}
#endif // WIDGETS_H
