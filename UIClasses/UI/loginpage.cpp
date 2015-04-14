#include "loginpage.h"
#include "ui_loginpage.h"

LoginPage::LoginPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_PwdEdit_editingFinished(){
    emit password(ui->PwdEdit->text());
    ui->stackedWidget->setCurrentIndex(0);
}

void LoginPage::on_StartButton_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
}

void LoginPage::on_SRButton_clicked(){}
