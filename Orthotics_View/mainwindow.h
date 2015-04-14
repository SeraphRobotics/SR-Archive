// Main Program Window
// This does the heavy lifting
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui>

class StartPage;
class ChoosePatientScreen;
class PatientHistoryScreen;
class ScanScreen;
class ReviewScan;
class SROptions;
class TempControlClass;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_ENUMS(pagelist)
public:
    enum pagelist {
        lStartPage = 0,
        lPatientOverviewPage,
        lPatientHistoryPage,
        lScanPage,
        lScanReviewPage,
        lSettingsPage,
        lReviewPage,
        lCreatePage,
        lSROptionsPage
    };

    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString GetCurrentDoctor();

    StartPage *pgeStart;
    ChoosePatientScreen *pgeChoosePatient;
    PatientHistoryScreen *pgePatientHistory;
    ScanScreen *pgeScanScreen;
    ReviewScan *pgeScanReview;
    TempControlClass *controller;

public slots:
    void SetCurrentDoctor(QString doctor);

    void nextScreenPressed();
    void prevScreenPressed();

    void loadPage(MainWindow::pagelist choice);

protected:
    void keyPressEvent(QKeyEvent * event);
    void paintEvent(QPaintEvent *);

private:
    void emptyLayout();
    void startScreen();

    int intCurrScreen; // Current Page (for navigation button purposes)
    QString Doctor; // Current Doctor name

    QStackedWidget* wgtPages;



    SROptions *pgeSROptions;

};

#endif // MAINWINDOW_H
