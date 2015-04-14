#ifndef PATIENTOPTIONSDIALOG_H
#define PATIENTOPTIONSDIALOG_H

#include <QDialog>
#include <QtGui>

class PatientOptionsDialog : public QDialog
{
    Q_OBJECT
public:
    explicit PatientOptionsDialog(QWidget *parent = 0);
    ~PatientOptionsDialog();

signals:
    void changeOwner();
    void editOnly();

public slots:
    void changeOwnerPressed();
    void editOnlyPressed();

private:
    QVBoxLayout *layout;
    QLabel *lblDiagDesc;
    QPushButton *btnChangeOwner;
    QPushButton *btnEditOnly;
};

#endif // PATIENTOPTIONSDIALOG_H
