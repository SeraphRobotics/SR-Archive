/********************************************
 * TODO:
 * - Comlete class definition
 * - Figure out what you forgot
 *
 ********************************************/
#ifndef REVIEWSCAN_H
#define REVIEWSCAN_H

#include <QWidget>
#include <QtGui>

//#include "openglwindow.h"

class OpenGLWindow;

class ReviewScan : public QWidget
{
    Q_OBJECT
public:
    explicit ReviewScan(QWidget *parent = 0);

public slots:
    void updateModel(QString model);

private:
    QGridLayout *layout;
    OpenGLWindow *wndMain; // Large view on right side of screen
    OpenGLWindow *wndBack; // Other three views on side
    OpenGLWindow *wndSide;
    OpenGLWindow *wndTop;

    QSlider *slider;
    QPushButton *saveForLater;

};

#endif // REVIEWSCAN_H
