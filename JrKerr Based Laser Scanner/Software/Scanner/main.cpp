#include <stdio.h>
#include <QCoreApplication>
//#include "test/tests.h"

#include "xygrid.h"
#include <QDomDocument>
#include <QFile>
#include <QTextStream>
#include "FabConLib/virtualmachines.h"
#include <QDebug>

int main(int argc, char *argv[]) {
    printf("\nStarting..");
    QCoreApplication app(argc,argv);


    if (argc<5){
        printf("\nneed more arguments: config file, lx, ly, delta, speed");
        return 1;
    }

    QStringList args = QCoreApplication::arguments();
    QString configFilePath= args.at(1);
    float lx= args.at(2).toFloat();
    float ly= args.at(3).toFloat();
    float delta = args.at(4).toFloat();
    float v= args.at(5).toFloat();
    float x,y;

    QString writename = QDate::currentDate().toString(Qt::ISODate) + " "+
            args.at(2)+ "-"+args.at(3)+ "-"+args.at(4)+ "-"+args.at(5)+".csv";

    /// MAKE THE VM
    VirtualPrinter vm;
    //load the config file into the DOM document
    QDomDocument document;
    QFile configFile(configFilePath);
    if (!configFile.open(QFile::ReadOnly)) {
        printf("\nFAILED TO OPEN CONFIG FILE\n");
        return 1;
    }
    document.setContent(&configFile);
    configFile.close();

    vm.loadConfig(document);// Load the config into the VM to create the electronics
    if (vm.isInitialized()){
        printf("\nVM initialized");
    }else{
        printf("\n Failed to initialize VM");
        qDebug()<<vm.getErrors();
        return 1;
    }


    /// GET DATA
    XYGrid<int> xy(lx,ly,delta);
    for(int i=0;i<xy.nx();i++){
        x=i*delta;
        vm.moveTo(x,0,0,v);
        vm.eInterface.waitOnMove();
        for(int j=0; j<xy.ny();j++){
            y = j*delta;
            vm.moveTo(x,y,0,v);
            vm.eInterface.waitOnMove();
            xy(i,j)=vm.eInterface.getIOs()[0]->readAnalog()[0];
        }
    }
    vm.moveTo(0,0,0,10);
    vm.eInterface.waitOnMove();
    vm.resetPosition();

    /// DUMP DATA
    QFile f(writename);
    if (!f.open(QFile::WriteOnly)) {
        printf("\nFAILED TO OPEN WRITE FILE\n");
        return false;
    }
    QTextStream out(&f);
    out<<xy.toCSV();
    f.close();




    printf("\n Done");
    return 0;//app.exec();//return 0;
}
