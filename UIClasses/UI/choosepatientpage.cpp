#include "choosepatientpage.h"
#include "ui_choosepatientpage.h"

ChoosePatientPage::ChoosePatientPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChoosePatientPage)
{
    ui->setupUi(this);
}

ChoosePatientPage::~ChoosePatientPage()
{
    delete ui;
}

void ChoosePatientPage::on_SRButton_clicked(){}
void ChoosePatientPage::on_NewPatientButton_clicked(){}
