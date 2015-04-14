#ifndef SRDIALOG_H
#define SRDIALOG_H

#include <QDialog>

namespace Ui {
class SRDialog;
}

class SRDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SRDialog(QWidget *parent = 0);
    ~SRDialog();

private:
    Ui::SRDialog *ui;
};

#endif // SRDIALOG_H
