// Shows the start page, with start button
#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QWidget>
#include <QtGui>

class StartPage : public QWidget
{
    Q_OBJECT
public:
    explicit StartPage(QWidget *parent = 0);
    

signals:
    // Sends password off somewhere to validate, call " void SetCurrentDoctor(QString doctor);" slot in MainWindow to set Doctor's name
    // and call " void loadPage(MainWindow::pagelist::lPatientOverviewPage);" to go to next screen
    // Otherwise call invalid login slot here
    void login(QString password);
    void pinForgotten();

public slots:
    // When user submits password for validation
    void startPressed();
    void passwordEntered();
    void loggedOut(); // Reset
    void invalidLogin();
private:
    QGridLayout *layout;
    QPushButton *startButton;
    QLineEdit *editPassword;

};

#endif // STARTPAGE_H
