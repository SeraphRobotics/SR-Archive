// Loads a 3D Model from a file and renders it to the screen
/************************************
 * TODO:
 *  - Set viewing angle.
 *
 ************************************/
#pragma once
#ifndef OPENGLMODEL_H
#define OPENGLMODEL_H

#include <QString>
#include <QColor>
#include <QMultiMap>

#include "shared/fabathome-constants.h"
#include "shared/math/quaternion.h"

class AMFFile;
class AMFRegion;

class OpenGLModel
{

    struct Transform {
        FAHVector3 translation, scaling;
        Math::Quaternion rotation;
        FAHMatrix4x4 transform;
        void identity();
        void updateMatrix();
    };

    enum BoundingCubeFace {
        kPositiveX,
        kNegativeX,
        kPositiveY,
        kNegativeY,
        kPositiveZ,
        kNegativeZ
      };

    static FAHVector3 getRotationToPutFaceDown(BoundingCubeFace face);

public:
    ~OpenGLModel();
    OpenGLModel(AMFFile* amf);


    static OpenGLModel* fromSTLFile(const QString& file);
    static void destroy(OpenGLModel* object);

    FAHVector3 translation() const;
    FAHVector3 rotation() const;
    FAHVector3 scaling() const;

    void rotateEuler(const FAHVector3& rotation);

    void scale(const FAHVector3& scaling);

    void draw();


    // When the 3D model gets updated, we need to reload the data
    void updateModel(AMFFile* amf);
    void updateBoundingSphere();

    void getTransform(FAHMatrix4x4* transform);
private:
    void findMinMaxOfScaledRotatedMesh(FAHVector3* min, FAHVector3* max);
    void moveCenterToOrigin();
    void changed();

    AMFFile* amf_;
    AMFFile* printable_amf_;

    int display_list_;
    Transform current_;
    Transform manipulation_;
    bool manipulating_;

    FAHSphere bounding_sphere_;

};

#endif // OPENGLMODEL_H
