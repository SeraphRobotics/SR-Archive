/********************************************************************************
** Form generated from reading UI file 'horizontalradio.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HORIZONTALRADIO_H
#define UI_HORIZONTALRADIO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HorizontalRadio
{
public:
    QHBoxLayout *horizontalLayout;
    QRadioButton *Left;
    QRadioButton *Both;
    QRadioButton *Right;

    void setupUi(QWidget *HorizontalRadio)
    {
        if (HorizontalRadio->objectName().isEmpty())
            HorizontalRadio->setObjectName(QString::fromUtf8("HorizontalRadio"));
        HorizontalRadio->resize(400, 52);
        horizontalLayout = new QHBoxLayout(HorizontalRadio);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Left = new QRadioButton(HorizontalRadio);
        Left->setObjectName(QString::fromUtf8("Left"));

        horizontalLayout->addWidget(Left);

        Both = new QRadioButton(HorizontalRadio);
        Both->setObjectName(QString::fromUtf8("Both"));
        Both->setContextMenuPolicy(Qt::PreventContextMenu);
        Both->setChecked(true);

        horizontalLayout->addWidget(Both);

        Right = new QRadioButton(HorizontalRadio);
        Right->setObjectName(QString::fromUtf8("Right"));

        horizontalLayout->addWidget(Right);


        retranslateUi(HorizontalRadio);

        QMetaObject::connectSlotsByName(HorizontalRadio);
    } // setupUi

    void retranslateUi(QWidget *HorizontalRadio)
    {
        HorizontalRadio->setWindowTitle(QApplication::translate("HorizontalRadio", "Form", 0, QApplication::UnicodeUTF8));
        Left->setText(QApplication::translate("HorizontalRadio", "Left", 0, QApplication::UnicodeUTF8));
        Both->setText(QApplication::translate("HorizontalRadio", "Both", 0, QApplication::UnicodeUTF8));
        Right->setText(QApplication::translate("HorizontalRadio", "Right", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HorizontalRadio: public Ui_HorizontalRadio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HORIZONTALRADIO_H
