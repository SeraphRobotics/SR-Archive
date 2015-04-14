#ifndef PATIENTMODEL_H
#define PATIENTMODEL_H

#include <QAbstractTableModel>
#include <QtGui>

struct PatientModelData {
    QString strFirstName;
    QString strLastName;
    QString Date;
    bool yours;
    int id; // PatientID
};

class PatientModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit PatientModel(QObject *parent = 0); // Takes in the current doctor, for formatting

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    //QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QList<PatientModelData*> *GetMap();

public slots:
    void SetPatientData(QList<PatientModelData*> *data); // Lets us set the table from outside the function, if needed
    void toggleShowHideAll();

private:
    QList<PatientModelData*> *patientMap;
    int numRowsShown;
    bool showHideAll;

    
};



#endif // PATIENTMODEL_H
