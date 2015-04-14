#include "scanscreen.h"
#include "scanoptionsdialog.h"

ScanScreen::ScanScreen(QWidget *parent) :
    QWidget(parent)
{
    isScanning = false;
    scanOptions = 2;

    layout = new QGridLayout(this);
    QGridLayout subLayout(this);

    lblEstimatedTime = new QLabel(tr("Estimated Time"), this);

    lblRight = new QLabel(tr("Right"), this);
    lblLeft = new QLabel(tr("Left"), this);
    lblTotal = new QLabel(tr("Total"), this);

    lblLeftTime = new QLabel(this);
    lblRightTime = new QLabel(this);
    lblTotalTime = new QLabel(this);

    btnCreateRight = new QPushButton(tr("Create Right"), this);
    btnCreateLeft = new QPushButton(tr("Create Left"), this);
    btnCreateBoth = new QPushButton(tr("Create Both"), this); // Format this one to be selected

    btnStart = new QPushButton(tr("Start"), this);
    btnPause = new QPushButton(tr("Pause"), this);
    btnCancel = new QPushButton(tr("Cancel"), this);

    optionsDiag = new ScanOptionsDialog(this);

    feetImage = new QImage();
    feetImage->load("../Orthotics_View/images/feet.png");

    feetLabel = new QLabel(this);
    feetLabel->setPixmap(QPixmap::fromImage(*feetImage));

    layout->addWidget(lblEstimatedTime, 0, 0);

    subLayout.addWidget(lblLeft, 0, 0);
    subLayout.addWidget(lblLeftTime, 0, 1);
    subLayout.addWidget(lblRight, 0, 0);
    subLayout.addWidget(lblRightTime, 0, 1);
    subLayout.addWidget(lblTotal, 0, 0);
    subLayout.addWidget(lblTotalTime, 0, 1);

    layout->addLayout(&subLayout, 1, 0, 2, 1, Qt::AlignHCenter);

    buttons(0);

    layout->addWidget(feetLabel, 3, 0, 1, 3, Qt::AlignCenter);

    setLayout(layout);

    QObject::connect(btnCreateRight, SIGNAL(clicked()), this, SLOT(createR()));
    QObject::connect(btnCreateLeft, SIGNAL(clicked()), this, SLOT(createL()));
    QObject::connect(btnCreateBoth, SIGNAL(clicked()), this, SLOT(createB()));

    QObject::connect(btnStart, SIGNAL(clicked()), this, SLOT(startScanSlot()));
    QObject::connect(btnPause, SIGNAL(clicked()), this, SLOT(pauseScanSlot()));
    QObject::connect(btnCancel, SIGNAL(clicked()), this, SLOT(cancelScanSlot()));

    QObject::connect(optionsDiag, SIGNAL(rescan()), this, SLOT(rescanSlot()));
    QObject::connect(optionsDiag, SIGNAL(review()), this, SLOT(reviewSlot()));

    dataModel = new QStandardItemModel(this);
    dataMapper = new QDataWidgetMapper(this);

    dataMapper->setModel(dataModel);

    dataMapper->addMapping(lblLeftTime, 0);
    dataMapper->addMapping(lblRightTime, 1);
    dataMapper->addMapping(lblTotalTime, 2);
    dataMapper->toFirst();
}

ScanScreen::~ScanScreen()
{
    delete layout;

    delete dataMapper;
    delete dataModel;

    delete btnCreateRight;
    delete btnCreateLeft;
    delete btnCreateBoth;
    delete btnStart;
    delete btnPause;
    delete btnCancel;

    delete lblEstimatedTime;
    delete lblRight;
    delete lblLeft;
    delete lblTotal;

    delete lblRightTime;
    delete lblLeftTime;
    delete lblTotalTime;

    delete optionsDiag;

    delete feetImage;
    delete feetLabel;
}

void ScanScreen::buttons(int bMode)
{
    layout->removeWidget(btnStart);
    layout->removeWidget(btnPause);
    layout->removeWidget(btnCancel);
    layout->removeWidget(btnCreateRight);
    layout->removeWidget(btnCreateLeft);
    layout->removeWidget(btnCreateBoth);

    if(bMode == 0)
    {
        layout->addWidget(btnStart, 0, 1, 1, 3, Qt::AlignVCenter);
        layout->addWidget(btnCreateRight, 0, 2);
        layout->addWidget(btnCreateLeft, 1, 2);
        layout->addWidget(btnCreateBoth, 2, 2);
    }
    else
    {
        layout->addWidget(btnPause, 0, 1, 1, 3, Qt::AlignVCenter);
        layout->addWidget(btnCancel, 0, 2, 1, 3, Qt::AlignVCenter);
    }
}

void ScanScreen::scanFinishedSlot()
{
    optionsDiag->show();
}

void ScanScreen::startScanSlot()
{
    buttons(1);
    emit startScan(scanOptions);
}

void ScanScreen::pauseScanSlot()
{
    buttons(0);
    emit pauseScan();
}

void ScanScreen::cancelScanSlot()
{
    buttons(0);
    emit cancelScan();
}

void ScanScreen::updateModel(QStandardItemModel *model)
{
    dataModel = model;
    dataMapper->setModel(dataModel);
    dataMapper->toFirst();
}

void ScanScreen::reviewSlot()
{
    optionsDiag->hide();
    emit Review();
}

void ScanScreen::rescanSlot()
{
    buttons(0);
    emit Rescan();
}

void ScanScreen::createL()
{
    scanOptions = 0;
    formatButtons();
}

void ScanScreen::createR()
{
    scanOptions = 1;
    formatButtons();
}

void ScanScreen::createB()
{
    scanOptions = 2;
    formatButtons();
}

void ScanScreen::formatButtons()
{
    switch(scanOptions)
    {
    case 0: // Left
        break;
    case 1: // Right
        break;
    case 2: // Both
        break;
    }
}
