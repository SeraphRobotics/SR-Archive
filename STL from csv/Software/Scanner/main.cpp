#include <stdio.h>
#include <QCoreApplication>
#include "test/tests.h"



int main(int argc, char *argv[]) {
    printf("\nStarting..");
    QCoreApplication app(argc,argv);


    testBoundaryLoopFromGrid();
//    STLfromCSVTest();


    printf("\n Done");
    return 0;//app.exec();//return 0;
}
