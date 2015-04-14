#include "scanoptionsdialog.h"

ScanOptionsDialog::ScanOptionsDialog(QWidget *parent) :
    QDialog(parent)
{
    layout = new QVBoxLayout(this);
    lblDiagDesc = new QLabel(tr("Finished scanning impression."), this);
    btnReview = new QPushButton(tr("review scan"), this);
    btnRescan = new QPushButton(tr("rescan"), this);

    layout->addWidget(lblDiagDesc);
    layout->addWidget(btnReview);
    layout->addWidget(btnRescan);

    setLayout(layout);

    QObject::connect(btnReview, SIGNAL(clicked()), this, SLOT(reviewPressed()));
    QObject::connect(btnRescan, SIGNAL(clicked()), this, SLOT(rescanPressed()));
}

ScanOptionsDialog::~ScanOptionsDialog()
{
    delete layout;
    delete lblDiagDesc;
    delete btnReview;
    delete btnRescan;
}

void ScanOptionsDialog::reviewPressed()
{
    emit review();
}

void ScanOptionsDialog::rescanPressed()
{
    emit rescan();
}
