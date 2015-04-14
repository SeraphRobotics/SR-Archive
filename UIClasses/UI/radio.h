#ifndef VERTICLERADIO_H
#define VERTICLERADIO_H

#include <QWidget>

namespace Ui {
class VerticleRadio;
class HorizontalRadio;
class Radio;
}

enum scanfeet{kRight,kLeft,kBoth};

class Radio : public QWidget
{
    Q_OBJECT
    
public:
    explicit Radio(QWidget *parent = 0);
    ~Radio();
    scanfeet getScanType();
    
public slots:
    void setScanType(scanfeet sf);

private slots:
    void on_Both_clicked();
    void on_Right_clicked();
    void on_Left_clicked();

signals:
    void ScanType(scanfeet);

private:
    Ui::VerticleRadio *ui;
};

class HorizontalRadio : public Radio{
    Q_OBJECT
public:
    explicit HorizontalRadio(QWidget *parent =0);
    ~ HorizontalRadio();

    Ui::HorizontalRadio *ui;
};

class VerticalRadio: public Radio{
    Q_OBJECT
public:
    explicit VerticalRadio(QWidget *parent =0);
    ~ VerticalRadio();
private:
    Ui::VerticleRadio *ui;
};


#endif // VERTICLERADIO_H
