#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QMessageBox>
#include <QDialog>
#include <QInputDialog>
#include <QProcess>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QCloseEvent>
#include <QByteArray>

#include <configdialog.h>
#include <include/cryptools.h>
#include <Qt-AES-master/qaesencryption.h>

namespace Ui {
// Ui is used to link the XML created in designer with C++ code
class MainWindow;
// Declares a MainWindow class used by both Ui (XML) and C++ classes
}

class MainWindow : public QMainWindow
        // Main Window class herits from QMainWindow
{
    Q_OBJECT // #defined by default in Qt, used for slots and signals

public:
    explicit MainWindow(QWidget *parent = NULL); // Constructor
    ~MainWindow(); // Destructor

private:
    Ui::MainWindow *ui; // ui is a pointer to XML class MainWindow

    void checkRegistryKey();
    bool LogIn();
    void configureSoftware();

    QAESEncryption AESObject;

    int attempts;

    QString softwarePassword;

    QSettings settings;

    QPropertyAnimation *exitAnimation;

    configDialog *configInstance;
protected:
    void closeEvent(QCloseEvent *event);
public slots:
    // void on_pushButton_clicked();
    void on_compareCheckBox_clicked();
    // Slots linked with XML (on_instanceName_signal)
    void on_favoriteFilesButton_clicked();
    // Another slot used for when a button is clicked
    void on_resetButton_clicked(); // Soft reset.
    void on_hResetButton_clicked();// Hard reset.
    void connectionTest();
signals:
};

#endif // MAINWINDOW_H
