#ifndef SROPTIONS_H
#define SROPTIONS_H

#include <QWidget>
#include <QtGui>

class PatientModel;

class SROptions : public QWidget
{
    Q_OBJECT
public:
    explicit SROptions(QWidget *parent = 0);
    
signals:
    void logout();
    void resetPIN();
    void changeUser();
    void contactSupport();
    void orderMaterials();
    void backupPatients();
    void usageTracker();

public slots:
    void Creating(PatientModel *creating);
    void OnQue(PatientModel *onque);
    void SetUser(QString name, QImage logo);
    void Close();
    void Open();

private:
    QImage *imgLogo;
    QString *strDoctor;
    PatientModel *mdlCreating;
    PatientModel *mdlOnQue;
};

#endif // SROPTIONS_H
