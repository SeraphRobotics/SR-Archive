#include "hslider.h"
#include "ui_hslider.h"
#include "QDebug"


HSlider::HSlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HSlider)
{
    ui->setupUi(this);
    connect(ui->plusButton,SIGNAL(clicked()),this,SLOT(on_plusButton_clicked()));
    connect(ui->minusButton,SIGNAL(clicked()),this,SLOT(on_minusButton_clicked()));
//    connect(ui->horizontalSlider,SIGNAL(sliderPressed()),this,SLOT(on_horizontalSlider_sliderPressed()));
}

HSlider::~HSlider()
{
    delete ui;
}


void HSlider::on_horizontalSlider_valueChanged(int i){
    ui->doubleSpinBox->setValue(i/10.0);
}

//void HSlider::on_horizontalSlider_sliderPressed(){
//    ui->doubleSpinBox->setValue(ui->horizontalSlider->value()/10.0);
//}

void HSlider::on_minusButton_clicked(){
    int step = ui->horizontalSlider->singleStep();
    int value = ui->horizontalSlider->value() - step;
    double val = (value+step)/10.0;
    ui->horizontalSlider->setValue(value);
    ui->doubleSpinBox->setValue(val);
    qDebug()<<"called minus";
}
void HSlider::on_plusButton_clicked(){
    int step = ui->horizontalSlider->singleStep();
    int value = ui->horizontalSlider->value() + step;
    double val = (value+step)/10.0;
    ui->horizontalSlider->setValue(value);
    ui->doubleSpinBox->setValue(val);
    qDebug()<<"called plus";
}
void HSlider::on_doubleSpinBox_editingFinished(){
    ui->horizontalSlider->setValue(ui->doubleSpinBox->value()*10);
}
