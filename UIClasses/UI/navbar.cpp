#include "navbar.h"
#include "ui_navbar.h"

NavBar::NavBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NavBar)
{
    ui->setupUi(this);

    page_text_map[0]="";
    page_text_map[1]="Choose Patient";
    page_text_map[2]="Patient History";
    page_text_map[3]="Scan";
    page_text_map[4]="Settings";
    page_text_map[5]="Review";
    page_text_map[6]="Create";

    setPage(0);
}

NavBar::~NavBar()
{
    delete ui;
}



void NavBar::setPage(int page_number){
    if(page_number>page_text_map.size()){return;}
    QString current="";
    QString back="";
    QString next="";
    if(page_number==0){
        ui->NxtButton->hide();
        ui->NxtLabel->hide();
        ui->BackLabel->hide();
        ui->BackButton->hide();
        ui->CurrentLabel->hide();
        return;
    }else{
        ui->NxtButton->show();
        ui->NxtLabel->show();
        ui->BackLabel->show();
        ui->BackButton->show();
        ui->CurrentLabel->show();
    }
    current = QString::number(page_number)+QString(": ")+page_text_map[page_number];

    if(page_number==(page_text_map.size()-1) ){
        back = QString::number(page_number-1)+QString(": ")+page_text_map[page_number-1];
        ui->NxtButton->hide();
        ui->NxtLabel->hide();

    }else if(1==page_number){
        next = QString::number(page_number+1)+QString(": ")+page_text_map[page_number+1];
        ui->BackButton->hide();
        ui->BackLabel->hide();
    }else{
        back = QString::number(page_number-1)+QString(": ")+page_text_map[page_number-1];
        next = QString::number(page_number+1)+QString(": ")+page_text_map[page_number+1];
    }
    ui->CurrentLabel->setText(current);
    ui->NxtLabel->setText(next);
    ui->BackLabel->setText(back);



}

void NavBar::on_BackButton_clicked(){
    emit back();
}
void NavBar::on_NxtButton_clicked(){
    emit next();
}
