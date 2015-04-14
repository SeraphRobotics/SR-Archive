#ifndef TEMPCONTROLCLASS_H
#define TEMPCONTROLCLASS_H

#include <QObject>

#include "mainwindow.h"
#include "patientmodel.h"

class TempControlClass : public QObject
{
    Q_OBJECT
public:
    explicit TempControlClass(MainWindow *m, QObject *parent = 0);
    ~TempControlClass();
    
signals:
    void SetCurrentDoctor(QString doctor);
    void goToScreen(MainWindow::pagelist choice);
    void invalidPassword();
    void SetPatientList(PatientModel*);
    void SetPendingFabrications(PatientModel*);

    // Patient History Signals
    void SetPatientInfoModel(QStandardItemModel*);
    void SetShoeStyleModel(QStringListModel*);

public slots:
    void login(QString password);
    void patientListClicked(QModelIndex);
    void pendingListClicked(QModelIndex);

private:
    MainWindow *window;
    PatientModel* tblPending;
    PatientModel* tblList;
    
};

#endif // TEMPCONTROLCLASS_H
