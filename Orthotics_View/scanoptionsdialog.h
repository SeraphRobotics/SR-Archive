#ifndef SCANOPTIONSDIALOG_H
#define SCANOPTIONSDIALOG_H

#include <QDialog>
#include <QtGui>

class ScanOptionsDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ScanOptionsDialog(QWidget *parent = 0);
    ~ScanOptionsDialog();

signals:
    void review();
    void rescan();

public slots:
    void reviewPressed();
    void rescanPressed();

private:
    QVBoxLayout *layout;
    QLabel *lblDiagDesc;
    QPushButton *btnReview;
    QPushButton *btnRescan;
    
};

#endif // SCANOPTIONSDIALOG_H
