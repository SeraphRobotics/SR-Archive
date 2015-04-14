#include "openglmodel.h"
#include "shared/stl/stlfile.h"
#include "shared/amf/amffile.h"
#include "shared/amf/amfobject.h"
#include "shared/amf/amfregion.h"

#include <QtOpenGL/QtOpenGL>
#include <math.h>

void OpenGLModel::Transform::identity()
{
    translation.set(0, 0, 0);
    rotation.identity();
    scaling.set(1, 1, 1);
    transform.identity();
}

void OpenGLModel::Transform::updateMatrix()
{
    FAHMatrix4x4 r, t;
    r.rotationQuaternion(rotation);
    t.translation(translation);
    transform.scaling(scaling).mul(r).mul(t);
}

FAHVector3 OpenGLModel::getRotationToPutFaceDown(BoundingCubeFace face)
{
    static const float k90Degrees = (float)(3.1415926535 / 2.0);
    switch(face) {
    case kPositiveX: return FAHVector3::make(0.0f,  k90Degrees, 0.0f);
    case kNegativeX: return FAHVector3::make(0.0f, -k90Degrees, 0.0f);
    case kPositiveY: return FAHVector3::make(-k90Degrees, 0.0f, 0.0f);
    case kNegativeY: return FAHVector3::make(+k90Degrees, 0.0f, 0.0f);
    case kPositiveZ: return FAHVector3::make(2*k90Degrees, 0.0f, 0.0f);
    default: return FAHVector3::make(0.0f, 0.0f, 0.0f);
    }
}

OpenGLModel::OpenGLModel(AMFFile* amf) : amf_(amf), printable_amf_(0)
{
    current_.identity();
    manipulation_.identity();
    manipulating_ = false;

    display_list_ = -1;

    updateBoundingSphere();
    moveCenterToOrigin();
}

OpenGLModel::~OpenGLModel()
{
    if(display_list_ != -1 && glIsList(display_list_)) {
        glDeleteLists(display_list_, 1);
        display_list_ = -1;
    }
    delete amf_;
    delete printable_amf_;
}

OpenGLModel* OpenGLModel::fromSTLFile(const QString& file)
{
    STLFile stl;
    if(!stl.read(file)) return 0;
    AMFFile* amf = new AMFFile();
    stl.convertToAMF(amf);
    return new OpenGLModel(amf);
}

void OpenGLModel::destroy(OpenGLModel* object)
{
    delete object;
}

FAHVector3 OpenGLModel::translation() const {
  return manipulating_ ? current_.translation.copy().add(manipulation_.translation) : current_.translation;
}

FAHVector3 OpenGLModel::rotation() const {
  return manipulating_ ? current_.rotation.copy().mul(manipulation_.rotation).eulerAngles() : current_.rotation.eulerAngles();
}

FAHVector3 OpenGLModel::scaling() const {
  return manipulating_ ? current_.scaling.copy().scalePairwise(manipulation_.scaling) : current_.scaling;
}

void OpenGLModel::rotateEuler(const FAHVector3& rotation) { }

void OpenGLModel::scale(const FAHVector3& scaling)
{
    current_.scaling.set(scaling);
    updateBoundingSphere();
    changed();
}

void OpenGLModel::updateBoundingSphere()
{
    FAHVector3 min, max;
    findMinMaxOfScaledRotatedMesh(&min, &max);

    FAHFloat rmin = min.magnitude(), rmax = max.magnitude();
    FAHVector3 translation(current_.translation);
    if(manipulating_)
        translation.add(manipulation_.translation);
    bounding_sphere_.set(translation, rmin > rmax ? rmin : rmax);
}




// When the 3D model gets updated, we need to reload the data
void OpenGLModel::updateModel(AMFFile* amf)
{
    amf_ = amf;
    current_.identity();
    manipulation_.identity();
    manipulating_ = false;

    display_list_ = -1;

    updateBoundingSphere();
}

void OpenGLModel::moveCenterToOrigin()
{
    const QList<AMFVertex*>* vertices = amf_->GetObjects().at(0)->GetMesh()->GetVertices();
    FAHVector3 min(vertices->at(0)->getPoint());
    FAHVector3 max(min);
    foreach(AMFVertex* v, *vertices)
    {
        FAHVector3& point = v->getPoint();
        min.min(point);
        max.max(point);
    }
    FAHVector3 offset;
    offset.set(max).add(min).scale(-0.5f);
    foreach(AMFVertex* v, *vertices)
    {
        FAHVector3& point = v->getPoint();
        point.add(offset);
    }
    changed();
}

void OpenGLModel::changed()
{
    if (display_list_ != -1 && glIsList(display_list_)) glDeleteLists(display_list_, 1);
    display_list_ = -1;
}

void OpenGLModel::getTransform(FAHMatrix4x4* transform)
{
    current_.updateMatrix();

    Transform t;
    t.rotation.set(current_.rotation).mul(manipulation_.rotation).normalize();
    t.scaling.set(current_.scaling).scalePairwise(manipulation_.scaling);
    t.translation.set(current_.translation).add(manipulation_.translation);
    t.updateMatrix();
    manipulation_.transform.set(t.transform);

    // Select the matrix to return based on whether manipulation is active
    transform->set(manipulating_ ? &manipulation_.transform : &current_.transform);
}

void OpenGLModel::draw()
{
    FAHMatrix4x4 transform;
    getTransform(&transform);

    updateBoundingSphere();

    float ambient[] = { 0.0f, 0.0f, 0.0f, 0.0f };
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    float diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    float position[] = { 1.0f, 1.0f, 1.0f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

    float no_mat[] = {0.0f, 0.0f, 0.0f, 1.0f};
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialf(GL_FRONT, GL_SHININESS, 0.0f);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadMatrixd(transform.array());

    if (display_list_ != -1 && glIsList(display_list_))
    {
        glCallList(display_list_);
    }
    else
    {
        static const QColor kDefaultColor(128, 128, 128, 0);
        static const float kAlpha = 0.1f;

        display_list_ = glGenLists(1);
        glNewList(display_list_, GL_COMPILE_AND_EXECUTE);

        foreach (AMFObject* object, amf_->GetObjects())
        {
            const AMFMesh* mesh = object->GetMesh();
            const QList<AMFVertex*>* vertices = mesh->GetVertices();
            foreach (const AMFRegion* region, *mesh->GetRegions())
            {
                const QColor& color = kDefaultColor;
                float rgba[]  = { color.red() / 255.0f, color.green() / 255.0f, color.blue() / 255.0f, 1.0f };
                glColor4f(rgba[0], rgba[1], rgba[2], kAlpha);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, rgba);
                glBegin(GL_TRIANGLES);

                foreach (const AMFTriangle* amf_triangle, region->getTriangles())
                {
                    const FAHVector3& v0 = vertices->at(amf_triangle->getV1())->getPoint();
                    const FAHVector3& v1 = vertices->at(amf_triangle->getV2())->getPoint();
                    const FAHVector3& v2 = vertices->at(amf_triangle->getV3())->getPoint();
                    FAHTriangle triangle(v0, v1, v2);

                    FAHVector3 normal = triangle.normal();

                    glNormal3f(normal.x, normal.y, normal.z);

                    glVertex3f(triangle.v[0][0], triangle.v[0][1], triangle.v[0][2]);
                    glVertex3f(triangle.v[1][0], triangle.v[1][1], triangle.v[1][2]);
                    glVertex3f(triangle.v[2][0], triangle.v[2][1], triangle.v[2][2]);
                }

                glEnd();
            }
        }

        glEndList();
    }

    glPopMatrix();
}

void OpenGLModel::findMinMaxOfScaledRotatedMesh(FAHVector3* min, FAHVector3* max)
{
    FAHMatrix4x4 sr;
    if (manipulating_) {
      FAHMatrix4x4 m;
      sr.scaling(current_.scaling.copy().scalePairwise(manipulation_.scaling));
      m.rotationQuaternion(current_.rotation.copy().mul(manipulation_.rotation).normalize());
    } else {
      FAHMatrix4x4 m;
      sr.scaling(current_.scaling);
      m.rotationQuaternion(current_.rotation);
      sr.mul(m);
    }

    const QList<AMFVertex*>* vertices = amf_->GetObjects().at(0)->GetMesh()->GetVertices();
    FAHVector3 local_min(sr.transform(vertices->at(0)->getPoint()));
    FAHVector3 local_max(local_min);

    foreach (AMFVertex* v, *vertices) {
      FAHVector3& point = v->getPoint();
      local_min.min(sr.transform(point));
      local_max.max(sr.transform(point));
    }

    if (min != 0) min->set(local_min);
    if (max != 0) max->set(local_max);

}
