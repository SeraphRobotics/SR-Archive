#ifndef CHOOSEPATIENTPAGE_H
#define CHOOSEPATIENTPAGE_H

#include <QWidget>

namespace Ui {
class ChoosePatientPage;
}

class ChoosePatientPage : public QWidget
{
    Q_OBJECT
    
public:
    explicit ChoosePatientPage(QWidget *parent = 0);
    ~ChoosePatientPage();
    
public slots:
    void on_SRButton_clicked();
    void on_NewPatientButton_clicked();


private:
    Ui::ChoosePatientPage *ui;
};

#endif // CHOOSEPATIENTPAGE_H
