/********************************************************************************
** Form generated from reading UI file 'hslider.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HSLIDER_H
#define UI_HSLIDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HSlider
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *minusButton;
    QSlider *horizontalSlider;
    QPushButton *plusButton;
    QDoubleSpinBox *doubleSpinBox;

    void setupUi(QWidget *HSlider)
    {
        if (HSlider->objectName().isEmpty())
            HSlider->setObjectName(QString::fromUtf8("HSlider"));
        HSlider->resize(693, 44);
        HSlider->setMaximumSize(QSize(16777215, 44));
        horizontalLayout = new QHBoxLayout(HSlider);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        minusButton = new QPushButton(HSlider);
        minusButton->setObjectName(QString::fromUtf8("minusButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(minusButton->sizePolicy().hasHeightForWidth());
        minusButton->setSizePolicy(sizePolicy);
        minusButton->setMinimumSize(QSize(10, 10));
        minusButton->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(minusButton);

        horizontalSlider = new QSlider(HSlider);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximumSize(QSize(16777215, 40));
        horizontalSlider->setMinimum(-760);
        horizontalSlider->setMaximum(760);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        plusButton = new QPushButton(HSlider);
        plusButton->setObjectName(QString::fromUtf8("plusButton"));
        plusButton->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(plusButton);

        doubleSpinBox = new QDoubleSpinBox(HSlider);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMaximumSize(QSize(16777215, 40));
        doubleSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox->setDecimals(1);
        doubleSpinBox->setMinimum(-76);
        doubleSpinBox->setMaximum(76);

        horizontalLayout->addWidget(doubleSpinBox);


        retranslateUi(HSlider);

        QMetaObject::connectSlotsByName(HSlider);
    } // setupUi

    void retranslateUi(QWidget *HSlider)
    {
        HSlider->setWindowTitle(QApplication::translate("HSlider", "Form", 0, QApplication::UnicodeUTF8));
        minusButton->setText(QApplication::translate("HSlider", "-", 0, QApplication::UnicodeUTF8));
        plusButton->setText(QApplication::translate("HSlider", "+", 0, QApplication::UnicodeUTF8));
        doubleSpinBox->setSuffix(QApplication::translate("HSlider", " MM", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HSlider: public Ui_HSlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HSLIDER_H
