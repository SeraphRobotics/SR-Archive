    // Displays an OpenGL window. The 3D model is rendered in here
/*********************************************
 * TODO:
 * - Add overlay for main window
 * - Add signals/slots for overlay buttons and control
 * - Figure out what I'm forgetting now
 *
 *********************************************/
#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <QGraphicsScene>
#include <QtGui>
#include <QtOpenGL/QtOpenGL>


//#include "openglmodel.h"
#include "Point3D.h"
#include "shared/fabathome-constants.h"


#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif

class OpenGLModel;
class OpenGLCamera;

class OpenGLWindow : public QGLWidget
{
    Q_OBJECT
public:
    explicit OpenGLWindow(QWidget *parent = 0);
    ~OpenGLWindow();


public slots:
    void loadModel(const QString &filePath);
    void modelLoaded();
    void setOverlay(bool isEnabled);
    void setView(int view); // 0->Top, 1->Left, 2->Right, 3->Front, 4->Back, 5->Bottom
    void setView(float radius, float theta, float phi);

private slots:
    void AcceptButton();
    void CancelButton();

signals:
    void accept(Point3D *point);
    void cancel();


protected:
    void initializeGL();
    void resizeGL( int width, int height);
    void paintGL();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:

    void setModel(OpenGLModel *model);

    OpenGLModel *mdlGLModel;

    OpenGLCamera *camera_;
    FAHVector3 next_target_;
    float zoom;
    float z_angle;
    float fltDistance;

    Point3D p3dPointClicked;

    QPushButton *btnOverlayAccept;
    QPushButton *btnOverlayCancel;

    bool boolOverlayEnabled;
    //QDialog *overlay;
    QGridLayout *overlayLayout;

    Point3D p3dRotation;
};

#endif // OPENGLWINDOW_H
