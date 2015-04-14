#include "reviewscan.h"
#include "openglwindow.h"

ReviewScan::ReviewScan(QWidget *parent) :
    QWidget(parent)
{
    layout = new QGridLayout(this);

    wndMain = new OpenGLWindow(this);
    wndBack = new OpenGLWindow(this);
    wndSide = new OpenGLWindow(this);
    wndTop = new OpenGLWindow(this);

    layout->addWidget(wndBack, 0, 0);
    layout->addWidget(wndSide, 1, 0);
    layout->addWidget(wndTop, 2, 0);
    layout->addWidget(wndMain, 0, 1, 3, 1);
}

void ReviewScan::updateModel(QString model)
{
    wndMain->loadModel(model);
    //wndMain->setView(0);
    wndBack->loadModel(model);
    //wndBack->setView(3);
    wndSide->loadModel(model);
    //wndSide->setView(1);
    wndTop->loadModel(model);
    //wndTop->setView(0);
}
