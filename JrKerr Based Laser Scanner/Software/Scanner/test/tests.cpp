#include "tests.h"
#include "scannerfunctions.h"
#include <math.h>

float pi=3.141592653589793238462643383279502884;

bool XYGridTest(){
    XYGrid<int> xy(2,2,1);
    for(int i=0;i<xy.nx();i++){
        for(int j=0; j<xy.ny();j++){
            printf("\n%i,%i",i,j);
            xy(i,j)=1;
            printf("=%i",xy(i,j));
        }
    }
    QFile f("dump.csv");
    if (!f.open(QFile::WriteOnly)) {
        printf("\nFAILED TO OPEN CONFIG FILE\n");
        return false;
    }
    QTextStream out(&f);
    out<<xy.toCSV();
    f.close();
    return true;
}

bool XYGridReadTest(){
    QString file = "dump.csv";
    XYGrid<float> xy(file);
    printf(xy.toCSV().toStdString().c_str());
    return true;
}


bool testPointsInGrid(){



    int i=6, j=4;
    float stepsize = 1.0;

    QVector<FAHVector3> points;

    // make loop
    float x= 5.5, y=5.5, r=3.1, theta=0;
    int nSides=10;
    FAHLoopInXYPlane loop;
    for(int i=0;i<nSides;i++){
        FAHVector3 pt;
        theta=((float)i)*2.0*pi/((float)nSides);
        pt.x=r*cos(theta)+x;
        pt.y=r*sin(theta)+y;
        pt.z=0;
        loop.add(pt);
        printf("\npt:\t%.1f\t%.1f\t%.1f\t\tr:%.1f\tTheta:%.1f",pt.x,pt.y,pt.z,r,theta*180.0/pi);

    }

    QList<FAHLoopInXYPlane> loops;
    writeLoopToXDFL(loop,"loop.xdfl");
    getPointsInGrid(i,j,stepsize,loop,loops,&points);





    printf("\n\nGrid:%i,%i\tX:%.1f - %.1f\tY:%.1f-%.1f",
           i,j,i*stepsize,(i+1)*stepsize,j*stepsize,(j+1)*stepsize);
    printf("\nretreived %i points",points.size());
    for(int k=0;k<points.size();k++){
        FAHVector3 pt = points.at(k);
        printf("\nPoint:\t%.1f\t%.1f\t%.1f",pt.x,pt.y,pt.z);
    }
    return true;
}

bool testduplicateremover(){
    QVector<FAHVector3> vector;
    FAHVector3 p1(1.0,2.0,0),p2(1.0,2.0,0),p3(2.0,0,0);
    vector.append(p1);
    vector.append(p2);
    vector.append(p3);
    vector.append(p3);
    removedDuplicatePoints(&vector);
    printf("\nsize: %i",vector.size());
    return true;
}

bool testPointIdentification(){
    int i=76, j=63;
    float stepsize=1;
    FAHVector3 p1,p2,p3,p4;
    bool b1,b2,b3,b4;
    p1 = vectorFromIJ(i,j,10,stepsize);
    p2 = vectorFromIJ(i+1,j,10,stepsize);
    p3 = vectorFromIJ(i,j+1,10,stepsize);
    p4 = vectorFromIJ(i+1,j+1,10,stepsize);
    float x= 50.5, y=50.5, r=30.1, theta=0;
    int nSides=100;
    FAHLoopInXYPlane loop;
    for(int i=0;i<nSides;i++){
        FAHVector3 pt;
        theta=((float)i)*2.0*pi/((float)nSides);
        pt.x=r*cos(theta)+x;
        pt.y=r*sin(theta)+y;
        pt.z=0;
        loop.add(pt);
    }

    float rx = (i+1)*stepsize-x;
    float ry = (j+1)*stepsize-y;
    float rr = sqrt(rx*rx+ry*ry);
    bool shouldwork = rr<r;

    QList<FAHLoopInXYPlane> loops;
    b1 = loopsContain(p1,loop,loops);
    b2 = loopsContain(p2,loop,loops);
    b3 = loopsContain(p3,loop,loops);
    b4 = loopsContain(p4,loop,loops);
    printf("\n R:%.3f\t should %s",rr,(shouldwork)?"DEFINATELY":"NOT");
    printf("\n %i,%i \tb1:%s\tb2:%s\tb3:%s\tb4:%s",i,j,
           (b1)?"true":"false",
           (b2)?"true":"false",
           (b3)?"true":"false",
           (b4)?"true":"false");

    return true;
}

bool IncreaseResolutionTest(){
    QString file = "dump.csv";
    XYGrid<float> xy(file);
    XYGrid<float>* superxy;
    superxy = increaseResolution(&xy,2);
    thresholdGrid(superxy,120.0);
    scaleAndOffset(superxy,40.0/120.0,-50.0);
    //blurGrid(superxy,15);


    QFile f("dump3.csv");
    if (!f.open(QFile::WriteOnly)) {
        printf("\nFAILED TO OPEN CONFIG FILE\n");
        return false;
    }
    QTextStream out(&f);
    out<<superxy->toCSV();
    f.close();

    STLFile stl;
    STLMesh* m = makeSTLfromScan(superxy);
    stl.SetMesh(m);
    stl.WriteASCII("IncreasedResSTL-noblur.stl");
    return true;

}

bool STLfromCSVTest(){
    QString file = "dump.csv";
    XYGrid<float> xy(file);
    thresholdGrid(&xy,120.0);
    scaleAndOffset(&xy,40.0/120.0,-50.0);
    //blurGrid(&xy,5);
    STLFile stl;
    STLMesh* m = makeSTLfromScan(&xy);
    stl.SetMesh(m);
    stl.WriteASCII("STLFromCSV.stl");
    return true;
}

bool testSTLFromXYGridWithLoops(){
    QString file = "dump.csv";
    XYGrid<float> xy(file);
    thresholdGrid(&xy,120.0);
    scaleAndOffset(&xy,40.0/120.0,-50.0);
    blurGrid(&xy,5);
    // make loop
    float x= 50, y=50, r1=25.1,r2=10, theta=0;
    int nSides=100;
    FAHLoopInXYPlane loop1, loop2;
    for(int i=0;i<nSides;i++){
        FAHVector3 pt1, pt2;
        theta=((float)i)*2.0*pi/((float)nSides);
        pt1.x=r1*cos(theta)+x;
        pt1.y=r1*sin(theta)+y;
        pt1.z=0;
        loop1.add(pt1);

        pt2.x=r2*cos(theta)+x+5;
        pt2.y=r2*sin(theta)+y+5;
        pt2.z=0;
        loop2.add(pt2);
    }

    QList<FAHLoopInXYPlane> innerLoops;
    innerLoops.append(loop2);
    STLMesh* m = makeSTLfromScanSection(&xy,loop1,innerLoops);
    STLFile stl;
    stl.SetMesh(m);
    stl.WriteASCII("CutSTL.stl");
    printf("\nwriting");
    return true;

}

bool testBoundaryLoopFromGrid(){
    QString file = "dump.csv";
    XYGrid<float> xy(file);
    thresholdGrid(&xy,80.0);
    scaleAndOffset(&xy,40.0/120.0,-50.0);


    blurGrid(&xy,5);

    FAHLoopInXYPlane loop = boundaryLoopFromGrid(&xy);
    QVector<FAHLoopInXYPlane> expandedloops;
    FAHLoopInXYPlane newloop = smoothLoop(loop,50);
    writeLoopToXDFL(newloop, "rawloop.xdfl");

    newloop.simplifyAndExpand(-0.10,&expandedloops);


    QList<FAHLoopInXYPlane> innerLoops;
    STLMesh* m = makeSTLfromScanSection(&xy,expandedloops[0],innerLoops);
    STLFile stl;
    stl.SetMesh(m);
    stl.WriteASCII("CutSTL.stl");
    printf("\nwriting");
    return true;
}


bool VMPrinterTest(){
    VirtualPrinter vm;
    //load the config file into the DOM document
    QString configFilePath="../../media/Scanner.config";//JrKerr-Single-deposition.config";
    QDomDocument document;

    QFile configFile(configFilePath);
    if (!configFile.open(QFile::ReadOnly)) {
        printf("\nFAILED TO OPEN CONFIG FILE\n");
        return false;
    }
    document.setContent(&configFile);
    configFile.close();

    vm.loadConfig(document);// Load the config into the VM to create the electronics
    if (vm.isInitialized()){
        printf("\nVM initialized");
        vm.eInterface.getMotor(2)->moveRelative(-1,1,1);
        return true;
    }
    return false;
}

bool ScanTest(){
    QString configFilePath="../../media/Scanner.config";
    float lx=100.0;
    float ly=100.0;
    float delta = 1;
    float v=10.0;
    float x,y;

    /// MAKE THE VM
    VirtualPrinter vm;
    //load the config file into the DOM document
    QDomDocument document;
    QFile configFile(configFilePath);
    if (!configFile.open(QFile::ReadOnly)) {
        printf("\nFAILED TO OPEN CONFIG FILE\n");
        return false;
    }
    document.setContent(&configFile);
    configFile.close();

    vm.loadConfig(document);// Load the config into the VM to create the electronics
    if (vm.isInitialized()){
        printf("\nVM initialized");
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
    QFile f("dump.csv");
    if (!f.open(QFile::WriteOnly)) {
        printf("\nFAILED TO OPEN CONFIG FILE\n");
        return false;
    }
    QTextStream out(&f);
    out<<xy.toCSV();
    f.close();
    return true;

}
