#include "srdialog.h"
#include "ui_srdialog.h"

SRDialog::SRDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SRDialog)
{
    ui->setupUi(this);
}

SRDialog::~SRDialog()
{
    delete ui;
}
