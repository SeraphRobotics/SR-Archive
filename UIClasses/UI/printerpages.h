#ifndef SCANPAGE_H
#define SCANPAGE_H

#include <QWidget>
#include "radio.h"

namespace Ui {
class PrinterPage;
class ScanPage;
class CreatePage;
}

class PrinterPage : public QWidget
{
    Q_OBJECT
    
public:
    explicit PrinterPage(QWidget *parent = 0);
    ~PrinterPage();
    
public slots:
    void on_StartButton_clicked();
    void on_pauseButton_clicked();
    void on_cancelButton_clicked();
    void setTimes(float left, float right, float total);
    void completed();

signals:
    void start();
    void pause();
    void cancel();


private:
    Ui::PrinterPage *ui;
};


class ScanPage: public PrinterPage
{
    Q_OBJECT
public:
    explicit ScanPage(QWidget *parent =0);
    ~ScanPage();

private:
    Ui::PrinterPage *ui;
};

class CreatePage: public PrinterPage
{
    Q_OBJECT
public:
    explicit CreatePage(QWidget *parent =0);
    ~CreatePage();

private:
    Ui::PrinterPage *ui;
};

#endif // SCANPAGE_H
