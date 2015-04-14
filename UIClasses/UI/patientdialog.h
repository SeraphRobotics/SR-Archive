#ifndef PATIENTDIALOG_H
#define PATIENTDIALOG_H

#include <QDialog>

namespace Ui {
class PatientDialog;
}

class PatientDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit PatientDialog(QWidget *parent = 0);
    ~PatientDialog();

public slots:
    void on_patientButton_clicked();
    void on_editButton_clicked();

signals:
    void makePatient();
    void editOnly();
    
private:
    Ui::PatientDialog *ui;
};

#endif // PATIENTDIALOG_H
