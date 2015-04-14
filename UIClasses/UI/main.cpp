#include "mainwindow.h"
#include <QApplication>
#include "navbar.h"
#include "radio.h"
#include "hslider.h"
#include "patientdialog.h"
#include "loginpage.h"
#include "choosepatientpage.h"
#include "scanpage.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    NavBar nb;
//    nb.show();

//    VerticalRadio vr;
//    vr.show();

//    HorizontalRadio hr;
//    hr.show();

//    HSlider hs;
//    hs.show();

//    PatientDialog pd;
//    return pd.exec();

//    LoginPage lp;
//    lp.show();

//    ChoosePatientPage cp;
//    cp.show();

    PrinterPage sp;
    sp.show();

    return a.exec();
}
