#include "mainwindow.h"

#include "startpage.h"
#include "choosepatientscreen.h"
#include "patienthistoryscreen.h"
#include "scanscreen.h"
#include "reviewscan.h"

#include "sroptions.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent, 0)
{
    //this->setFixedSize(800,600);


    // Instantiate the page manager

    wgtPages = new QStackedWidget(this);

    // Instantiate pages
    pgeStart = new StartPage(this);
    pgeChoosePatient = new ChoosePatientScreen(this);
    pgePatientHistory = new PatientHistoryScreen(this);
    pgeScanScreen = new ScanScreen(this);
    pgeScanReview = new ReviewScan(this);

    pgeSROptions = new SROptions(this);

    // Add pages to page manager
    wgtPages->addWidget(pgeStart);
    wgtPages->addWidget(pgeChoosePatient);
    wgtPages->addWidget(pgePatientHistory);
    wgtPages->addWidget(pgeScanScreen);
    wgtPages->addWidget(pgeScanReview);
    wgtPages->addWidget(new QWidget()); // Placeholder for classes not yet defined
    wgtPages->addWidget(new QWidget());
    wgtPages->addWidget(new QWidget());
    wgtPages->addWidget(pgeSROptions);


    setCentralWidget(wgtPages);


    qDebug() << QDir::currentPath();


}

MainWindow::~MainWindow()
{
    if(pgeStart)
        delete pgeStart;

    delete pgeChoosePatient;
    delete pgePatientHistory;
    delete pgeScanScreen;
    delete pgeScanReview;

}

QString MainWindow::GetCurrentDoctor()
{
    return Doctor;
}

void MainWindow::SetCurrentDoctor(QString doctor)
{
    this->Doctor = doctor;
    pgeChoosePatient->lblDoctor->setText(tr("Hello Dr. %1").arg(doctor));
}


void MainWindow::nextScreenPressed()
{
    if(wgtPages->currentIndex() < wgtPages->count())
        wgtPages->setCurrentIndex(wgtPages->currentIndex() + 1);
}

void MainWindow::prevScreenPressed()
{
    {
        if(wgtPages->currentIndex() > 0)
            wgtPages->setCurrentIndex(wgtPages->currentIndex() - 1);
    }
}

void MainWindow::loadPage(MainWindow::pagelist choice)
{
    wgtPages->setCurrentIndex(choice);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
            qApp->quit();
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap("../Orthotics_View/images/bg.png").scaled(size()));
    QWidget::paintEvent(e);
}
