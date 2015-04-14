#ifndef ORTHO_H
#define ORTHO_H

#include "stl/stlmesh.h"
#include "xygrid.h"
#include <stdio.h>
#include "math/float.h"
#include <QDomDocument>
#include <math.h>
#include "shared/stl/stlfile.h"
#include "scannerfunctions.h"


/**
 * returns the loop translated proprotional to the height of the loop ds = z*tan(theta)
 * theta is measured in degrees
 * if z<threshold no translation
 **/
FAHLoopInXYPlane angledBase(float theta, float threshold, FAHLoopInXYPlane loop);


/**
 * returns the CM of the loop based onthe assumption that all points are weighted equally
 **/
FAHVector3 CMfromLoop(FAHLoopInXYPlane loop);

/**
 * Adds facets to mesh by drawing connections between outerboarder and trimmed boarder
 **/
void makeSides(STLMesh* mesh, FAHLoopInXYPlane outerboarder, FAHLoopInXYPlane trimmed);




#endif // ORTHO_H
