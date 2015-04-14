/********************************************************************************
** Form generated from reading UI file 'verticleradio.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERTICLERADIO_H
#define UI_VERTICLERADIO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VerticleRadio
{
public:
    QVBoxLayout *verticalLayout;
    QRadioButton *Right;
    QRadioButton *Left;
    QRadioButton *Both;

    void setupUi(QWidget *VerticleRadio)
    {
        if (VerticleRadio->objectName().isEmpty())
            VerticleRadio->setObjectName(QString::fromUtf8("VerticleRadio"));
        VerticleRadio->resize(153, 182);
        verticalLayout = new QVBoxLayout(VerticleRadio);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Right = new QRadioButton(VerticleRadio);
        Right->setObjectName(QString::fromUtf8("Right"));
        Right->setIconSize(QSize(0, 0));

        verticalLayout->addWidget(Right);

        Left = new QRadioButton(VerticleRadio);
        Left->setObjectName(QString::fromUtf8("Left"));
        Left->setIconSize(QSize(0, 0));

        verticalLayout->addWidget(Left);

        Both = new QRadioButton(VerticleRadio);
        Both->setObjectName(QString::fromUtf8("Both"));
        Both->setIconSize(QSize(0, 0));
        Both->setChecked(true);

        verticalLayout->addWidget(Both);


        retranslateUi(VerticleRadio);

        QMetaObject::connectSlotsByName(VerticleRadio);
    } // setupUi

    void retranslateUi(QWidget *VerticleRadio)
    {
        VerticleRadio->setWindowTitle(QApplication::translate("VerticleRadio", "Form", 0, QApplication::UnicodeUTF8));
        Right->setText(QApplication::translate("VerticleRadio", "Scan Right", 0, QApplication::UnicodeUTF8));
        Left->setText(QApplication::translate("VerticleRadio", "Scan Left", 0, QApplication::UnicodeUTF8));
        Both->setText(QApplication::translate("VerticleRadio", "Scan Both", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VerticleRadio: public Ui_VerticleRadio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERTICLERADIO_H
