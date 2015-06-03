#ifndef TESTS_H
#define TESTS_H
#include "xygrid.h"
#include <QDomDocument>
#include <QFile>
#include <QTextStream>
#include "FabConLib/virtualmachines.h"
#include "stl/stlfile.h"




bool XYGridTest();
bool XYGridReadTest();
bool STLfromCSVTest();
bool IncreaseResolutionTest();
bool VMPrinterTest();
bool ScanTest();

bool testPointsInGrid();

bool testSTLFromXYGridWithLoops();

bool testPointIdentification();
bool testduplicateremover();

bool testBoundaryLoopFromGrid();


#endif // TESTS_H
