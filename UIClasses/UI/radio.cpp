#include "radio.h"
#include "ui_verticleradio.h"
#include "ui_horizontalradio.h"


Radio::Radio(QWidget *parent) :
    QWidget(parent){}

Radio::~Radio(){}

scanfeet Radio::getScanType(){
    if(ui->Right->isChecked()){
        return kRight;
    }else if(ui->Left->isChecked()){
        return kLeft;
    }
    return kBoth;
}

void Radio::setScanType(scanfeet sf ){
    if(kBoth==sf){
        ui->Both->setChecked(true);
    }else if(kRight==sf){
        ui->Right->setChecked(true);
    }else if(kLeft ==sf){
        ui->Left->setChecked(true);
    }
}

void Radio::on_Both_clicked(){emit ScanType(kBoth);}
void Radio::on_Right_clicked(){emit ScanType(kRight);}
void Radio::on_Left_clicked(){emit ScanType(kLeft);}



VerticalRadio::VerticalRadio(QWidget *parent) :
    Radio(parent),
    ui(new Ui::VerticleRadio)
{
    ui->setupUi(this);
}

VerticalRadio::~VerticalRadio()
{
    delete ui;
}

HorizontalRadio::HorizontalRadio(QWidget *parent) :
    Radio(parent),
    ui(new Ui::HorizontalRadio)
{
    ui->setupUi(this);
}

HorizontalRadio::~HorizontalRadio()
{
    delete ui;
}

