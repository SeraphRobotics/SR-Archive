#include "openglwindow.h"
#include "openglmodel.h"
#include "openglcamera.h"
#include <math.h>
#include <cmath>

#define PI 3.141592f
#define X_AXIS 0
#define Y_AXIS 1
#define Z_AXIS 2

#define _USE_MATH_DEFINES

OpenGLWindow::OpenGLWindow(QWidget *parent) :
    QGLWidget(parent, 0, 0)
{
    mdlGLModel = 0;
    fltDistance = 1.0f;
    /*
    btnOverlayAccept = new QPushButton();
    btnOverlayCancel = new QPushButton();

    overlayLayout = new QGridLayout();

    overlayLayout->addWidget(btnOverlayAccept, 0, 1);
    overlayLayout->addWidget(btnOverlayCancel, 0, 2);

    overlay = new QDialog(0, Qt::FramelessWindowHint);
    overlay->setAttribute(Qt::WA_TranslucentBackground);
    overlay->setLayout(overlayLayout);
    */

    camera_ = new OpenGLCamera();
    zoom = 2.0f;
    z_angle = 0.0f;
    next_target_ = camera_->getTarget();
    FAHVector3 eye_dest;
    eye_dest.set(next_target_).add(FAHVector3::make(150*zoom*sin(z_angle), 150*zoom*cos(z_angle), 150*zoom));
    camera_->setEye(eye_dest.x, eye_dest.y, eye_dest.z);

}

OpenGLWindow::~OpenGLWindow()
{
    delete mdlGLModel;
    /*delete overlay;
    delete overlayLayout;

    delete btnOverlayAccept;
    delete btnOverlayCancel;*/
    delete camera_;
}


void OpenGLWindow::paintGL()
{//*
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(!mdlGLModel)
        return;

    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

    camera_->glSetCamera();

    mdlGLModel->draw();


    QTimer::singleShot(20, this, SLOT(update())); // */
}

void OpenGLWindow::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void OpenGLWindow::resizeGL(int width, int height)
{
    if(height==0)
        height = 1;

    glViewport(0, 0, (GLint)width, (GLint)height);

    camera_->setScreenSize(width, height);
    camera_->glSetCamera();
}

static OpenGLModel *loadModel(const QString &filepath)
{
    return OpenGLModel::fromSTLFile(filepath);
}

void OpenGLWindow::loadModel(const QString &filePath)
{
    if(filePath.isEmpty())
        return;

    QApplication::setOverrideCursor(Qt::BusyCursor);
    setModel(::loadModel(filePath));
    modelLoaded();
}

void OpenGLWindow::modelLoaded()
{
    QApplication::restoreOverrideCursor();
}

void OpenGLWindow::setModel(OpenGLModel *model)
{
    delete mdlGLModel;
    mdlGLModel = model;

    update();
}

void OpenGLWindow::setOverlay(bool isEnabled) { }

void OpenGLWindow::setView(int view)  // 0->Top, 1->Left, 2->Right, 3->Front, 4->Back, 5->Bottom
{
    switch(view)
    {
    case 0:
        setView(fltDistance, M_PI / 2.0f, 0.0f);
        break;
    case 1:
        setView(fltDistance, 0.0f, 0.0f);
        break;
    case 2:
        setView(fltDistance, 0.0f, M_PI);
        break;
    case 3:
        setView(fltDistance, 0.0f, M_PI / 2.0f);
        break;
    case 4:
        setView(fltDistance, 0.0f, 3.0f * M_PI / 2.0f);
        break;
    case 5:
        setView(fltDistance, 3.0f * M_PI / 2.0f, 0.0f);
        break;
    }
}

void OpenGLWindow::setView(float radius, float theta, float phi) // Phi & Theta in Radians. Theta is polar angle, Phi is azimuthal
{
    p3dRotation.x = radius * cos(phi) * sin(theta);
    p3dRotation.y = radius * sin(theta) * sin(phi);
    p3dRotation.z = radius * cos(theta);

    // Update the camera. Somehow.
    camera_->setTarget(0,0,0);
    camera_->setEye(p3dRotation.x, p3dRotation.y, p3dRotation.z);

}

void OpenGLWindow::AcceptButton()
{
    emit accept(&p3dPointClicked);
}

void OpenGLWindow::CancelButton()
{
    emit cancel();
}

void OpenGLWindow::mousePressEvent(QGraphicsSceneMouseEvent *event) { }
void OpenGLWindow::mouseMoveEvent(QGraphicsSceneMouseEvent *event) { }
void OpenGLWindow::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) { }
