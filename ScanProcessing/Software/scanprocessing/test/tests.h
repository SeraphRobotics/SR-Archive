#ifndef TESTS_H
#define TESTS_H
#include "xygrid.h"
#include <QDomDocument>
#include <QFile>
#include <QTextStream>
#include "stl/stlfile.h"




bool XYGridTest();
bool XYGridReadTest();
bool STLfromCSVTest();
bool IncreaseResolutionTest();


bool testPointsInGrid();

bool testSTLFromXYGridWithLoops();

bool testPointIdentification();
bool testduplicateremover();

bool testBoundaryLoopFromGrid(QString filename, float angle, float angle_threshold);

bool testSorting();

#endif // TESTS_H
