#include "tempcontrolclass.h"
#include "startpage.h"
#include "choosepatientscreen.h"
#include "patienthistoryscreen.h"
#include "scanscreen.h"
#include "reviewscan.h"

#include "sroptions.h"


TempControlClass::TempControlClass(MainWindow *m, QObject *parent) :
    QObject(parent)
{
    window = m;

    QObject::connect(window->pgeStart, SIGNAL(login(QString)), this, SLOT(login(QString)));
    QObject::connect(this, SIGNAL(invalidPassword()), window->pgeStart, SLOT(invalidLogin()));

    QObject::connect(this, SIGNAL(goToScreen(MainWindow::pagelist)), window, SLOT(loadPage(MainWindow::pagelist)));
    QObject::connect(this, SIGNAL(SetCurrentDoctor(QString)), window, SLOT(SetCurrentDoctor(QString)));

    QObject::connect(window->pgeChoosePatient->tblPatientList, SIGNAL(clicked(QModelIndex)), this, SLOT(patientListClicked(QModelIndex)));
    QObject::connect(window->pgeChoosePatient->tblPendingFabrications, SIGNAL(clicked(QModelIndex)), this, SLOT(pendingListClicked(QModelIndex)));
    QObject::connect(window->pgeChoosePatient->tblSearchResults, SIGNAL(clicked(QModelIndex)), this, SLOT(patientListClicked(QModelIndex)));

    QObject::connect(this, SIGNAL(SetPatientList(PatientModel*)), window->pgeChoosePatient, SLOT(SetPatientList(PatientModel*)));
    QObject::connect(this, SIGNAL(SetPendingFabrications(PatientModel*)), window->pgeChoosePatient, SLOT(SetPendingFabrications(PatientModel*)));

    QObject::connect(window->pgePatientHistory->btnNextScreen, SIGNAL(clicked()), window, SLOT(nextScreenPressed()));
    QObject::connect(window->pgePatientHistory->btnPrevScreen, SIGNAL(clicked()), window, SLOT(prevScreenPressed()));

    QObject::connect(this, SIGNAL(SetPatientInfoModel(QStandardItemModel*)), window->pgePatientHistory, SLOT(SetStandardItemModel(QStandardItemModel*)));
    QObject::connect(this, SIGNAL(SetShoeStyleModel(QStringListModel*)), window->pgePatientHistory, SLOT(SetShoeStyleModel(QStringListModel*)));

    tblPending = window->pgeChoosePatient->mdlPendingFabrications;
    tblList = window->pgeChoosePatient->mdlPatientList;

    QList<PatientModelData *> *data = tblList->GetMap();

    PatientModelData *item = new PatientModelData;
    item->strFirstName = "Test";
    item->strLastName = "Test";
    item->Date = "11/21/13";
    item->yours = true;
    item->id = 1;

    data->append(item);

    tblList->SetPatientData(data);

    QStringList shoeStyles;
    shoeStyles.append(tr("Tennis"));
    shoeStyles.append(tr("Athletic"));
    shoeStyles.append(tr("Clown"));

    QStringListModel *shoeStylesModel = new QStringListModel(shoeStyles);
    emit SetShoeStyleModel(shoeStylesModel);

    window->pgeChoosePatient->resetModels();

    window->pgeScanReview->updateModel("../Orthotics_View/images/sphere.stl");

}

TempControlClass::~TempControlClass()
{
    delete window;
}

void TempControlClass::login(QString password)
{
    if(password != "good")
    {
        emit invalidPassword();
    }
    else
    {
        emit SetCurrentDoctor("Klein");
        emit goToScreen(MainWindow::lPatientOverviewPage);
    }
}

void TempControlClass::patientListClicked(QModelIndex) {
    emit goToScreen(MainWindow::lPatientHistoryPage);
}

void TempControlClass::pendingListClicked(QModelIndex) {
    emit goToScreen(MainWindow::lPatientHistoryPage);
}
