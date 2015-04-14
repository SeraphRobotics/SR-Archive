#ifndef HSLIDER_H
#define HSLIDER_H

#include <QWidget>

namespace Ui {
class HSlider;
}

class HSlider : public QWidget
{
    Q_OBJECT
    
public:
    explicit HSlider(QWidget *parent = 0);
    ~HSlider();

public slots:
    void on_horizontalSlider_valueChanged(int i);
//    void on_horizontalSlider_sliderPressed();
    void on_minusButton_clicked();
    void on_plusButton_clicked();
    void on_doubleSpinBox_editingFinished();

    
private:
    Ui::HSlider *ui;
};

#endif // HSLIDER_H
