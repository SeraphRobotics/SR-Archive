#include "patientmodel.h"

PatientModel::PatientModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    patientMap = new QList<PatientModelData*>;
    showHideAll = true;

}

int PatientModel::rowCount(const QModelIndex &parent)const
{
    return patientMap->size();
}

int PatientModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant PatientModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

    PatientModelData* temp = patientMap->at(row);
    if((*temp).yours || showHideAll)
    {
        switch(role)
        {
        case Qt::DisplayRole:

            switch(col) {
            case 0: // Name
                return QString("%1, %2").arg((*temp).strLastName).arg((*temp).strFirstName);
                break;
            case 1: // Date
                return QString((*temp).Date);
                break;
            case 2: // Patient ID
                return QString((*temp).id);
                break;
            case 3: // Is the patient this doctor's?
                return QString((*temp).yours ? "1":"0");
                break;
            }
            break;
        case Qt::ForegroundRole:
            if((*temp).yours)
                return QBrush(Qt::black);
            else
                return QBrush(Qt::gray);
            break;
        }

    }
    return QVariant();

}
/*
QVariant PatientModel::headerData(int section, Qt::Orientation orientation, int role) const
{

} // */

void PatientModel::toggleShowHideAll()
{
    showHideAll = !showHideAll;
}

void PatientModel::SetPatientData(QList<PatientModelData *> *data)
{
    patientMap = data;
}

QList<PatientModelData*> *PatientModel::GetMap() {
    return patientMap;
}
