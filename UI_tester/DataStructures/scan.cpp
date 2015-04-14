#include "scan.h"
#include <QDomDocument>

Scan::Scan(QObject *parent) :
    QObject(parent)
{
    id_=QUuid::createUuid();
    filename_=id_.toString()+QString(".scan");
    raw_=new XYGrid<float>();
    processed_=new XYGrid<float>();
}

Scan::Scan(QString filename){
    filename_=filename;
    id_=QUuid::createUuid();

    QDomDocument d("ScanFile");

    QFile file(filename_);
    if (!file.open(QIODevice::ReadOnly)){return;}

    if (!d.setContent(&file)) {
        file.close();
        return;
    }
    file.close();

    QDomElement scan = d.documentElement();
    if(!("scan"==scan.nodeName().toLower())){return;}
    QString id = scan.attribute("id",id_.toString());
    id_=QUuid(id);

    QDomNodeList mchildren = scan.childNodes();
    for(unsigned int i=0;i<mchildren.length();i++){
        QDomNode mchild = mchildren.at(i);
        if(!mchild.isElement()){continue;}

        QDomElement el = mchild.toElement();
        QString name = mchild.nodeName().toLower();

        if("rawscan"==name){
            raw_= new XYGrid<float>(el.text());
        }else if("processedscan"==name){
            processed_=new XYGrid<float>(el.text());
        }
    }
}

void Scan::writeToDisk(){
    QDomDocument d("ScanFile");

    QFile file(filename_);
    if (!file.open(QIODevice::WriteOnly)){return;}


    QDomElement node = d.createElement("Scan");
    node.setAttribute(QString("id"),id_.toString());


    QDomElement rawEl = d.createElement("rawscan");
    rawEl.appendChild(d.createTextNode(raw_->toCSV()));
    node.appendChild(rawEl);

    QDomElement processedEl = d.createElement("processedscan");
    processedEl.appendChild(d.createTextNode(processed_->toCSV()));
    node.appendChild(processedEl);

    d.appendChild(node);
    QTextStream f(&file);
    f<<d.toString();
    file.close();
}




QString Scan::getID(){return id_.toString();}

XYGrid<float>* Scan::getXYGrid(){return processed_;}

void Scan::reset(){
    processed_ = new XYGrid<float>(raw_->asVector(),raw_->ny(),raw_->stepSize());
}

void Scan::setInitialData(XYGrid<float>* grid){// makes a copy of the data
    if(raw_->nx()<2){
        raw_ = new XYGrid<float>(grid->asVector(),grid->ny(),grid->stepSize());
        processed_ = new XYGrid<float>(grid->asVector(),grid->ny(),grid->stepSize());
    }
}
void Scan::setProcessedGrid(XYGrid<float>* grid){
    processed_=grid;
}