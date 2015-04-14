#include <stdio.h>
#include <QCoreApplication>
#include "test/tests.h"

#include "scannerfunctions.h"

int main(int argc, char *argv[]) {
    printf("\nStarting..");
    QCoreApplication app(argc,argv);


    if(argc<3){
        qDebug()<<"Not enough arguments. Give csv file, an angle in degrees and threshold in mm";
        qDebug()<<"eg: dump.csv 40 1";
        return 0;
    }

    QString filename,angle, threshold;
    filename = argv[1];
    angle = argv[2];
    angle.replace(" ","");
    threshold = argv[3];
    threshold.replace(" ","");

    qDebug()<<"angle: "<<angle.toFloat()<<" threshold: "<<threshold.toFloat();
    testBoundaryLoopFromGrid(filename, angle.toFloat(), threshold.toFloat());



    printf("\n Done");
    return 0;//app.exec();//return 0;
}
