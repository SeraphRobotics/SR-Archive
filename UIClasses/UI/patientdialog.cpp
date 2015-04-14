#include "patientdialog.h"
#include "ui_patientdialog.h"

PatientDialog::PatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Popup);
}

PatientDialog::~PatientDialog()
{
    delete ui;
}


void PatientDialog::on_patientButton_clicked(){
    emit makePatient();
}
void PatientDialog::on_editButton_clicked(){
    emit editOnly();
}
