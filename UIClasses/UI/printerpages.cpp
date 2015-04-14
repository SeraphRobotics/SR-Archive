#include "printerpages.h"
#include "ui_printerpage.h"


PrinterPage::PrinterPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrinterPage)
{
    ui->setupUi(this);
    ui->stackedWidget->widget(0)->layout()->addWidget(new VerticalRadio());
}

PrinterPage::~PrinterPage()
{
    delete ui;
}


void PrinterPage::on_StartButton_clicked(){
    ui->timeLabel->setText("Time Remaining");
        ui->stackedWidget->setCurrentIndex(1);
    emit start();
}

void PrinterPage::on_pauseButton_clicked(){
    emit pause();
}

void PrinterPage::on_cancelButton_clicked(){
    emit cancel();
}
void PrinterPage::setTimes(float left, float right, float total){
    ui->leftDoubleSpinBox->setValue(left);
    ui->rightDoubleSpinBox->setValue(right);
    ui->totalDoubleSpinBox->setValue(total);
}

void PrinterPage::completed(){
    ui->timeLabel->setText("Estimated Time");
    ui->leftDoubleSpinBox->setValue(0);
    ui->rightDoubleSpinBox->setValue(0);
    ui->totalDoubleSpinBox->setValue(0);
    ui->stackedWidget->setCurrentIndex(0);
}


ScanPage::ScanPage(QWidget *parent) :
   PrinterPage(parent)
{
}

ScanPage::~ScanPage()
{
    delete ui;
}


CreatePage::CreatePage(QWidget *parent) :
   PrinterPage(parent)
{

}

CreatePage::~CreatePage()
{
    delete ui;
}
