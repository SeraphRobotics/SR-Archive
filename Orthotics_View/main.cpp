#include <QtGui/QApplication>
#include "tempcontrolclass.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow m;
    TempControlClass tc(&m);
    m.show();

    return a.exec();
}
