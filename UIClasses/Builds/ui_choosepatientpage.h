/********************************************************************************
** Form generated from reading UI file 'choosepatientpage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEPATIENTPAGE_H
#define UI_CHOOSEPATIENTPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChoosePatientPage
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *UserLabel;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *MainHLayout;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QPushButton *NewPatientButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *SRButton;

    void setupUi(QWidget *ChoosePatientPage)
    {
        if (ChoosePatientPage->objectName().isEmpty())
            ChoosePatientPage->setObjectName(QString::fromUtf8("ChoosePatientPage"));
        ChoosePatientPage->resize(829, 574);
        verticalLayout_2 = new QVBoxLayout(ChoosePatientPage);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        UserLabel = new QLabel(ChoosePatientPage);
        UserLabel->setObjectName(QString::fromUtf8("UserLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UserLabel->sizePolicy().hasHeightForWidth());
        UserLabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(14);
        UserLabel->setFont(font);

        horizontalLayout_2->addWidget(UserLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        MainHLayout = new QHBoxLayout();
        MainHLayout->setObjectName(QString::fromUtf8("MainHLayout"));

        horizontalLayout_4->addLayout(MainHLayout);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(100, 100, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        NewPatientButton = new QPushButton(ChoosePatientPage);
        NewPatientButton->setObjectName(QString::fromUtf8("NewPatientButton"));
        NewPatientButton->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(NewPatientButton);

        verticalSpacer = new QSpacerItem(118, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        SRButton = new QPushButton(ChoosePatientPage);
        SRButton->setObjectName(QString::fromUtf8("SRButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(SRButton->sizePolicy().hasHeightForWidth());
        SRButton->setSizePolicy(sizePolicy1);
        SRButton->setMinimumSize(QSize(100, 100));

        horizontalLayout->addWidget(SRButton);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(ChoosePatientPage);

        QMetaObject::connectSlotsByName(ChoosePatientPage);
    } // setupUi

    void retranslateUi(QWidget *ChoosePatientPage)
    {
        ChoosePatientPage->setWindowTitle(QApplication::translate("ChoosePatientPage", "Form", 0, QApplication::UnicodeUTF8));
        UserLabel->setText(QApplication::translate("ChoosePatientPage", "Doctor Who", 0, QApplication::UnicodeUTF8));
        NewPatientButton->setText(QApplication::translate("ChoosePatientPage", "New Patient", 0, QApplication::UnicodeUTF8));
        SRButton->setText(QApplication::translate("ChoosePatientPage", "SR", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChoosePatientPage: public Ui_ChoosePatientPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEPATIENTPAGE_H
