#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>

namespace Ui {
class LoginPage;
}

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = 0);
    ~LoginPage();

public slots:
    void on_PwdEdit_editingFinished();
    void on_StartButton_clicked();
    void on_SRButton_clicked();

signals:
    void password(QString pwd);


private:
    Ui::LoginPage *ui;
};

#endif // PAGE_H
