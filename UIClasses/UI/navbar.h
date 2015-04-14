#ifndef NAVBAR_H
#define NAVBAR_H

#include <QWidget>
#include <QMap>

namespace Ui {
class NavBar;
}

class NavBar : public QWidget
{
    Q_OBJECT


public:
    explicit NavBar(QWidget *parent = 0);
    ~NavBar();

public slots:
    void setPage(int page_number);

private slots:
    void on_BackButton_clicked();
    void on_NxtButton_clicked();

signals:
    void next();
    void back();

private:
    Ui::NavBar *ui;
    QMap<int, QString> page_text_map;

};

#endif // NAVBAR_H
