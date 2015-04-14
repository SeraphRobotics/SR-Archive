#ifndef CHOOSEPATIENTSCREEN_H
#define CHOOSEPATIENTSCREEN_H

#include <QWidget>
#include <QtGui>

//#include "patientoptionsdialog.h"
//#include "patientmodel.h"

class PatientModel;
class PatientOptionsDialog;

class ChoosePatientScreen : public QWidget
{
    Q_OBJECT
public:
    ChoosePatientScreen(QWidget *parent = 0);
    ~ChoosePatientScreen();
    

    // Views that display the data
    QTableView *tblPatientList;
    QTableView *tblPendingFabrications;
    QTableView *tblSearchResults;
    PatientModel *mdlPatientList;
    PatientModel *mdlPendingFabrications;
    void resetModels();

    QPushButton *btnNextScreen;
    QPushButton *btnPrevScreen;
    QLabel *lblDoctor;

signals:
    void makePatient(int ID); // Assigns patient ID to current doctor
    void editPatient(int ID); // Opens patient History screen for patient ID
    void newPatient();

    void toggleShowAllPatients(); // Tells the model if it should display all of the patients, or just this doctor's


private slots:
    void newPatientPressed();
    void searchPressed();
    void sortAZ();
    void sortDate();
    void showHideAll(); // Toggles showing all patients or just the current doctors
    void patientSelectedPL(QModelIndex&,QModelIndex&);
    void patientSelectedPFL(QModelIndex&,QModelIndex&);
    void patientSelectedSL(QModelIndex&,QModelIndex&);

public slots:
    void SetPatientList(PatientModel *model);
    void SetPendingFabrications(PatientModel *model);
    void editPatientPressed();
    void makePatientPressed();

private:

    // Top of screen elements
    QLabel *lblCurrentStep;


    // Models that hold the data

    QSortFilterProxyModel *mdlSearchResults;
    QSortFilterProxyModel *mdlPatientSort;

    // Selection models for handling table selections
    QItemSelectionModel *selPatientList;
    QItemSelectionModel *selPendingFabrications;
    QItemSelectionModel *selSearchResults;

    // Visual Elements
    QLabel *lblHello;
    QLabel *lblResultCount;
    QLabel *lblPatientListTitle;
    QGridLayout *layout;
    QGridLayout *lytPatientLists;
    QGridLayout *lytSearchLists;
    QPushButton *btnNewPatient;
    QPushButton *btnSortAZ;
    QPushButton *btnShowHideAll;
    QPushButton *btnSortDate;
    QPushButton *btnShowHidePendingFabrications;
    QPushButton *btnShowMorePatients;

    QLineEdit *txtQuery;
    QPushButton *btnSearch;
    int intTotalResults;

    // Patient Click Dialog
    PatientOptionsDialog *selectOptions;
    int intPatientID;

};

#endif // CHOOSEPATIENTSCREEN_H
