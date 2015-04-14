#ifndef SCANSCREEN_H
#define SCANSCREEN_H

#include <QWidget>
#include <QtGui>

//#include "scanoptionsdialog.h"

class ScanOptionsDialog;

class ScanScreen : public QWidget
{
    Q_OBJECT
public:
    explicit ScanScreen(QWidget *parent = 0);
    ~ScanScreen();

signals:
    void Review();
    void Rescan();
    void startScan(int side); // 0 - Left, 1 - Right, 2 - Both
    void pauseScan();
    void cancelScan();

public slots:
    void scanFinishedSlot();
    void startScanSlot();
    void pauseScanSlot();
    void cancelScanSlot();
    void updateModel(QStandardItemModel *model);
    void reviewSlot();
    void rescanSlot();

private slots:
    void createL();
    void createR();
    void createB();



private:

    bool isScanning;
    int scanOptions; // 0 - Left, 1 - Right, 2 - Both

    void buttons(int bMode);
    void formatButtons();

    QGridLayout *layout;

    QDataWidgetMapper *dataMapper;
    QStandardItemModel *dataModel;
    // Data model should be right << left << total

    QPushButton *btnCreateRight;
    QPushButton *btnCreateLeft;
    QPushButton *btnCreateBoth;
    QPushButton *btnStart;
    QPushButton *btnPause;
    QPushButton *btnCancel;

    QLabel *lblEstimatedTime;
    QLabel *lblRight;
    QLabel *lblLeft;
    QLabel *lblTotal;

    QLabel *lblRightTime;
    QLabel *lblLeftTime;
    QLabel *lblTotalTime;

    ScanOptionsDialog *optionsDiag;

    QImage *feetImage;
    QLabel *feetLabel;
};

#endif // SCANSCREEN_H
