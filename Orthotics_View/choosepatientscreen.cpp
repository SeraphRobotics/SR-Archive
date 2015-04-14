#include "choosepatientscreen.h"

#include "patientoptionsdialog.h"
#include "patientmodel.h"
#include <qmath.h>

ChoosePatientScreen::ChoosePatientScreen(QWidget *parent) :
    QWidget(parent)
{

    // Instantiate data models
    mdlPatientList = new PatientModel(this);
    mdlPendingFabrications = new PatientModel(this);
    mdlSearchResults = new QSortFilterProxyModel(this);
    mdlPatientSort = new QSortFilterProxyModel(this);

    // Instantiate data tables
    tblPatientList = new QTableView(this);
    tblPendingFabrications = new QTableView(this);
    tblSearchResults = new QTableView(this);

    // Set the tables' models
    resetModels();

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QGridLayout *topLayout = new QGridLayout(this);

    lblCurrentStep = new QLabel(tr("step 1: choose patient"));
    btnNextScreen = new QPushButton(tr("2: patient history"));
    lblDoctor = new QLabel(tr("Hello Dr. "));

    lblDoctor->setStyleSheet("QLabel { color:#18a4e2; font-family:\"Arial Helvetica\"; font-size:28px; margin: 10px; }");
    lblCurrentStep->setStyleSheet("QLabel { font-size:18px; font-style:bold; color:#858585; font-family:\"Arial Helvetica\"; }");
    btnNextScreen->setStyleSheet("QPushButton { color:#727272; font-style:bold; font-size:14px; font-family:\"Arial Helvetica\"; background:transparent; } ");



    topLayout->addWidget(lblDoctor, 0, 0);
    topLayout->addWidget(lblCurrentStep, 0, 1, 1, 1, Qt::AlignCenter);
    topLayout->addWidget(btnNextScreen, 0, 2, 1, 1, Qt::AlignRight);

    mainLayout->addLayout(topLayout);

    // Setup the layout
    layout = new QGridLayout(this);


    lblHello = new QLabel(this);

    // Use two additional layouts for the two columns
    lytPatientLists = new QGridLayout(this);
    lytSearchLists = new QGridLayout(this);

    // Patient List data



    btnShowHidePendingFabrications = new QPushButton(tr("hide pending fabrications"), this);
    btnSortAZ = new QPushButton(tr("A-Z"), this);
    btnSortDate = new QPushButton(tr("newest-oldest"), this);
    btnShowHideAll = new QPushButton(tr("show all patients"), this);
    btnShowMorePatients = new QPushButton(tr("more patients"), this);


    lytPatientLists->addWidget(tblPendingFabrications, 1, 0, 1, 3, Qt::AlignCenter);
    lytPatientLists->addWidget(btnShowHidePendingFabrications, 2, 0, 1, 3, Qt::AlignCenter);
    lytPatientLists->addWidget(btnSortAZ, 3, 0);
    lytPatientLists->addWidget(btnShowHideAll, 3, 1);
    lytPatientLists->addWidget(btnSortDate, 3, 2);
    lytPatientLists->addWidget(tblPatientList, 4, 0, 1, 3, Qt::AlignCenter);
    lytPatientLists->addWidget(btnShowMorePatients, 5, 1);

    // Search list data
    txtQuery = new QLineEdit(this);
    btnSearch = new QPushButton(tr("Search"), this);
    lblResultCount = new QLabel(this);

    txtQuery->setStyleSheet("QLineEdit { border-top-left-radius:8px; border-bottom-left-radius:8px; border:1px solid #dddddd; border-right:none; padding: 4px; margin-right:none; }");
    btnSearch->setStyleSheet("QPushButton { color:white; background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #4c4b9b, stop: 1 #25285b); border-top-right-radius:8px; border-bottom-right-radius:8px; border-left:none; margin-left:0; padding: 5px; }");
    lytSearchLists->addWidget(txtQuery, 0, 0);
    lytSearchLists->addWidget(btnSearch, 0, 1);
    lytSearchLists->addWidget(lblResultCount, 1, 0, 1, 2, Qt::AlignLeft);
    lytSearchLists->addWidget(tblSearchResults, 2, 0, 1, 2, Qt::AlignLeft);
    lytSearchLists->setColumnStretch(0, 1);
    lytSearchLists->setHorizontalSpacing(0);

    btnNewPatient = new QPushButton(tr("new patient"), this);

    QGroupBox *patientGroup = new QGroupBox("Patients");
    patientGroup->setLayout(lytPatientLists);
    lytPatientLists->setMargin(35);


    patientGroup->setStyleSheet("QGroupBox { background-color:white; border: 1px solid #dddddd; border-top: 25px solid qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #4c4b9b, stop: 1 #25285b); } QGroupBox::title {   background:transparent; border:none; color:white; padding-top:2px; font-family:\"Arial Helvetica\"; font-size:16px; }");
    patientGroup->setAlignment(Qt::AlignHCenter);
    // padding: 6 " + halfwidth + " 6 " + halfwidth + "; background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #4c4b9b, stop: 1 #25285b);
    // Add widgets to layout
    layout->addWidget(lblHello, 0, 0);

    layout->addWidget(patientGroup, 1, 0, 1, 2, Qt::AlignCenter);
    layout->addLayout(lytSearchLists, 1, 3, 1, 2, Qt::AlignCenter);

    layout->addWidget(btnNewPatient, 2, 0, 1, -1, Qt::AlignCenter);

    mainLayout->addLayout(layout);
    setLayout(mainLayout);

    // Make the dialog
    selectOptions = new PatientOptionsDialog(this);


    // Connect signals
    // buttons
    QObject::connect(btnNewPatient, SIGNAL(clicked()), this, SLOT(newPatientPressed()));
    QObject::connect(btnSearch, SIGNAL(clicked()), this, SLOT(searchPressed()));
    QObject::connect(btnSortAZ, SIGNAL(clicked()), this, SLOT(sortAZ()));
    QObject::connect(btnSortDate, SIGNAL(clicked()), this, SLOT(sortDate()));
    QObject::connect(btnShowHideAll, SIGNAL(clicked()), this, SLOT(showHideAll()));
    QObject::connect(btnShowMorePatients, SIGNAL(clicked()), this, SLOT(showMorePatients()));
    // Dialog
    QObject::connect(selectOptions, SIGNAL(changeOwner()), this, SLOT(makePatientPressed()));
    QObject::connect(selectOptions, SIGNAL(editOnly()), this, SLOT(editPatientPressed()));


    tblPatientList->horizontalHeader()->hide();
    tblPendingFabrications->horizontalHeader()->hide();
    tblSearchResults->horizontalHeader()->hide();

}

ChoosePatientScreen::~ChoosePatientScreen()
{
    delete tblPatientList;
    delete tblPendingFabrications;
    delete tblSearchResults;

    delete mdlPatientList;
    delete mdlPendingFabrications;
    delete mdlSearchResults;
    delete mdlPatientSort;


    selPatientList = 0;
    delete selPatientList;
    selPendingFabrications = 0;
    delete selPendingFabrications;

    selSearchResults = 0;
    delete selSearchResults;

    delete lblHello;
    delete lblResultCount;

    layout = 0;
    delete layout;

    lytPatientLists = 0;
    delete lytPatientLists;

    lytSearchLists = 0;
    delete lytSearchLists;
    delete btnNewPatient;
    delete btnSortAZ;
    delete btnShowHideAll;
    delete btnSortDate;
    delete btnShowHidePendingFabrications;
    delete btnShowMorePatients;

    delete txtQuery;
    delete btnSearch;

    delete selectOptions;
}

void ChoosePatientScreen::resetModels()
{
    // Setup source model
    mdlSearchResults->setSourceModel(mdlPatientList);
    mdlPatientSort->setSourceModel(mdlPatientList);

    tblPatientList->setModel(mdlPatientSort);
    tblPendingFabrications->setModel(mdlPendingFabrications);
    tblSearchResults->setModel(mdlSearchResults);

    // Hide Patient ID
    tblPatientList->hideColumn(2);
    tblPendingFabrications->hideColumn(2);
    tblSearchResults->hideColumn(2);

    // Hide Patient Yours? field
    tblPatientList->hideColumn(3);
    tblPendingFabrications->hideColumn(3);
    tblSearchResults->hideColumn(3);

    // Setup selecting items
    selPatientList = tblPatientList->selectionModel();
    selPendingFabrications = tblPendingFabrications->selectionModel();
    selSearchResults = tblSearchResults->selectionModel();

    // Connect the toggle to the Models
    QObject::connect(this, SIGNAL(toggleShowAllPatients()), mdlPatientList, SLOT(toggleShowHideAll()));

    // Connect the tables' selections to the handler
    QObject::connect(selPatientList, SIGNAL(currentChanged(QModelIndex&,QModelIndex&)), this, SLOT(patientSelectedPL(QModelIndex&,QModelIndex&)));
    QObject::connect(selPendingFabrications, SIGNAL(currentChanged(QModelIndex&,QModelIndex&)), this, SLOT(patientSelectedPFL(QModelIndex&,QModelIndex&)));
    QObject::connect(selSearchResults, SIGNAL(currentChanged(QModelIndex&,QModelIndex&)), this, SLOT(patientSelectedSL(QModelIndex&,QModelIndex&)));
}



// Private Slots
void ChoosePatientScreen::patientSelectedPL(QModelIndex &currentIndex, QModelIndex &prevIndex)
{
    intPatientID = tblPatientList->model()->data(tblPatientList->model()->index(currentIndex.row(), 2)).toInt();
    if(tblPatientList->model()->data(tblPatientList->model()->index(currentIndex.row(), 3)) == "1")
        emit editPatient(intPatientID);
    else
        selectOptions->show();
}

void ChoosePatientScreen::patientSelectedPFL(QModelIndex &currentIndex, QModelIndex &prevIndex)
{
    intPatientID = tblPendingFabrications->model()->data(tblPendingFabrications->model()->index(currentIndex.row(), 2)).toInt();
    if(tblPendingFabrications->model()->data(tblPendingFabrications->model()->index(currentIndex.row(), 3)) == "1")
        emit editPatient(intPatientID);
    else
        selectOptions->show();
}

void ChoosePatientScreen::patientSelectedSL(QModelIndex &currentIndex, QModelIndex &prevIndex)
{
    intPatientID = tblSearchResults->model()->data(tblSearchResults->model()->index(currentIndex.row(), 2)).toInt();
    if(tblSearchResults->model()->data(tblSearchResults->model()->index(currentIndex.row(), 3)) == "1")
        emit editPatient(intPatientID);
    else
        selectOptions->show();
}

void ChoosePatientScreen::newPatientPressed()
{
    emit newPatient();
}

void ChoosePatientScreen::searchPressed()
{
    mdlSearchResults->setFilterWildcard(txtQuery->text());
    intTotalResults = tblSearchResults->model()->rowCount();
    lblResultCount->setText(QString("Displaying %1 of %2 results").arg(intTotalResults).arg(intTotalResults));
}

void ChoosePatientScreen::sortAZ()
{
    if(mdlPatientSort->sortColumn() == 0)
        mdlPatientSort->sort(0, mdlPatientSort->sortOrder()==Qt::AscendingOrder?Qt::DescendingOrder:Qt::AscendingOrder); // Toggle the direction of the sort. This is either a brilliant line or I'm sleep deprived.
    else
        mdlPatientSort->sort(0, Qt::AscendingOrder);
}

void ChoosePatientScreen::sortDate()
{
    if(mdlPatientSort->sortColumn() == 1)
        mdlPatientSort->sort(1, mdlPatientSort->sortOrder()==Qt::AscendingOrder?Qt::DescendingOrder:Qt::AscendingOrder); // Toggle the direction of the sort. This is either a brilliant line or I'm sleep deprived.
    else
        mdlPatientSort->sort(1, Qt::AscendingOrder);
}

void ChoosePatientScreen::showHideAll()
{
    emit toggleShowAllPatients();
}

//public slots:
void ChoosePatientScreen::editPatientPressed()
{
    emit editPatient(intPatientID);
}

void ChoosePatientScreen::makePatientPressed()
{
    emit makePatient(intPatientID);
}

// public functions
void ChoosePatientScreen::SetPatientList(PatientModel *model)
{
    mdlPatientList = model;
    resetModels();
}


void ChoosePatientScreen::SetPendingFabrications(PatientModel *model)
{
    mdlPendingFabrications = model;
    resetModels();
}
