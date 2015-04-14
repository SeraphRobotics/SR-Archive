#include "patientoptionsdialog.h"

PatientOptionsDialog::PatientOptionsDialog(QWidget *parent) :
    QDialog(parent)
{
    layout = new QVBoxLayout();
    lblDiagDesc = new QLabel(tr("This patient is usually treated by another doctor, how would you like to proceed?"), this);
    btnChangeOwner = new QPushButton(tr("make my patient"), this);
    btnEditOnly = new QPushButton(tr("edit only"), this);

    layout->addWidget(lblDiagDesc);
    layout->addWidget(btnChangeOwner);
    layout->addWidget(btnEditOnly);

    setLayout(layout);

    QObject::connect(btnChangeOwner, SIGNAL(clicked()), this, SLOT(changeOwnerPressed()));
    QObject::connect(btnEditOnly, SIGNAL(clicked()), this, SLOT(editOnlyPressed()));
}
PatientOptionsDialog::~PatientOptionsDialog()
{
    delete layout;
    delete lblDiagDesc;
    delete btnChangeOwner;
    delete btnEditOnly;
}

void PatientOptionsDialog::editOnlyPressed()
{
    emit editOnly();
}

void PatientOptionsDialog::changeOwnerPressed()
{
    emit changeOwner();
}

