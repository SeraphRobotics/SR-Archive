#ifndef TESTS_H
#define TESTS_H
#include "xygrid.h"
#include <QDomDocument>
#include <QFile>
#include <QTextStream>
#include "stl/stlfile.h"

/**
 * These Functions Test the XYGrid Class and LoopInXYPlane Class functionality.
 * The class has passed all of these tests
 */

/**
 * Generates a XYGrid object and writes to dump.csv
 */
bool XYGridTest();

/**
 * Reads an XYGrid from a csv file
 */
bool XYGridReadTest();

bool LoopLoadTest();
bool testSTLFromXYGridWithLoopFromXDFL();

/**
 * Reads a CSV file and makes and STL that fills the entire rectangular grid
 */
bool STLfromCSVTest();

/**
 * Interpolates points in the grid of an XYGrid to make one of higher point density
 */
bool IncreaseResolutionTest();

/**
 * Makes a loop, writes loop to XDFL for visualization
 * Finds points in the loop along gridlines
 */
bool testPointsInGrid();

/**
 * Loads dump.csv into a xygrid
 * Thresholds,scales,and smooths the grid
 * Makes inner loops and an outer loop
 * Returns an STL cut from the XYGrid from the outerloop and inner loop
 * Writes STL to CutSTL.stl
 */
bool testSTLFromXYGridWithLoops();

/**
 * Tests the identification of a gridp points as have 0,1,2,3 or 4 points inside a loop
 */
bool testPointIdentification();

/**
 * Tests the loop point duplication cleanup system
 */
bool testduplicateremover();

/**
 * Automatically generates a boundary and from a XYGrid and writes a series of STL files for cross refrence
 */
bool testBoundaryLoopFromGrid();


#endif // TESTS_H
