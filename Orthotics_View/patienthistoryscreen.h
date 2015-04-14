#ifndef PAITENTHISTORYSCREEN_H
#define PAITENTHISTORYSCREEN_H

#include <QtGui>
#include <QWidget>

class PatientHistoryScreen : public QWidget
{
    Q_OBJECT
public:
    PatientHistoryScreen(QWidget *parent = 0);
    ~PatientHistoryScreen();

    QPushButton *btnNextScreen;
    QPushButton *btnPrevScreen;
    
public slots:
    void SetStandardItemModel(QStandardItemModel *dataModel);
    void SetShoeStyleModel(QStringListModel *dataModel);

private:
    void updateModel();

    QVBoxLayout *layout;

    // View elements
    QDataWidgetMapper *mapData;
    QStandardItemModel *mdlData;
    QStringListModel *mdlShoeStyles;

    // Data in model should be in the same order as this list, on row 0
    // Item  0 -> LName
    // Item 11 -> ShoeStyle (Note: This should be an integer with the id of the relevant field)
    // Item 12 -> Complaints
    // Item 14 -> Participating Hours Per Week
    // Item 15 -> PatientID (int)

    // Top of screen elements
    QLabel *lblCurrentStep;

    QLineEdit *txtLName;
    QLineEdit *txtFName;
    QDateEdit *txtDate;
    QLineEdit *txtOccupation;
    QIntValidator *vAge;
    QLineEdit *txtAge;
    QComboBox *cmbSex; // Model data should be 0->Male 1->Female

    QComboBox *cmbHeightFt;
    QComboBox *cmbHeightIn;
    //QLineEdit *txtHeight;

    QIntValidator *vWeight;
    QLineEdit *txtWeight;
    QDoubleSpinBox *txtShoeSize;
    QComboBox *cmbShoeWidth;
    QDoubleValidator *vHeelHeight;
    QLineEdit *txtHeelHeight;
    QComboBox *cmbShoeStyle;

    QLabel *lblComplaints;
    QLabel *lblDiagnosis;
    QLabel *lblPhysicalActivityLevel;

    QTextEdit *txtComplaints;
    QTextEdit *txtDiagnosis;
    QTextEdit *txtPhysicalActivityLevel;

    int intPatientID;
};

#endif // PAITENTHISTORYWINDOW_H
