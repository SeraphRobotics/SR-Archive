/********************************************************************************
** Form generated from reading UI file 'navbar.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVBAR_H
#define UI_NAVBAR_H

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

class Ui_NavBar
{
public:
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *BackButton;
    QLabel *BackLabel;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *CurrentLabel;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *NxtLabel;
    QPushButton *NxtButton;

    void setupUi(QWidget *NavBar)
    {
        if (NavBar->objectName().isEmpty())
            NavBar->setObjectName(QString::fromUtf8("NavBar"));
        NavBar->resize(941, 70);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NavBar->sizePolicy().hasHeightForWidth());
        NavBar->setSizePolicy(sizePolicy);
        NavBar->setMinimumSize(QSize(0, 60));
        NavBar->setMaximumSize(QSize(16777215, 70));
        horizontalLayout_3 = new QHBoxLayout(NavBar);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        BackButton = new QPushButton(NavBar);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(BackButton->sizePolicy().hasHeightForWidth());
        BackButton->setSizePolicy(sizePolicy1);
        BackButton->setMinimumSize(QSize(40, 40));
        BackButton->setMaximumSize(QSize(50, 50));
        BackButton->setFlat(true);

        horizontalLayout_2->addWidget(BackButton);

        BackLabel = new QLabel(NavBar);
        BackLabel->setObjectName(QString::fromUtf8("BackLabel"));
        BackLabel->setMinimumSize(QSize(120, 50));
        QFont font;
        font.setPointSize(12);
        BackLabel->setFont(font);

        horizontalLayout_2->addWidget(BackLabel);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalSpacer = new QSpacerItem(161, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        CurrentLabel = new QLabel(NavBar);
        CurrentLabel->setObjectName(QString::fromUtf8("CurrentLabel"));
        QFont font1;
        font1.setPointSize(14);
        CurrentLabel->setFont(font1);

        verticalLayout->addWidget(CurrentLabel);

        verticalSpacer = new QSpacerItem(208, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(161, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        NxtLabel = new QLabel(NavBar);
        NxtLabel->setObjectName(QString::fromUtf8("NxtLabel"));
        NxtLabel->setMinimumSize(QSize(120, 40));
        NxtLabel->setFont(font);
        NxtLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(NxtLabel);

        NxtButton = new QPushButton(NavBar);
        NxtButton->setObjectName(QString::fromUtf8("NxtButton"));
        sizePolicy1.setHeightForWidth(NxtButton->sizePolicy().hasHeightForWidth());
        NxtButton->setSizePolicy(sizePolicy1);
        NxtButton->setMinimumSize(QSize(40, 40));
        NxtButton->setMaximumSize(QSize(50, 50));
        NxtButton->setFlat(true);

        horizontalLayout->addWidget(NxtButton);


        horizontalLayout_3->addLayout(horizontalLayout);

        NxtButton->raise();
        NxtLabel->raise();
        BackButton->raise();
        BackLabel->raise();
        NxtLabel->raise();
        CurrentLabel->raise();

        retranslateUi(NavBar);

        QMetaObject::connectSlotsByName(NavBar);
    } // setupUi

    void retranslateUi(QWidget *NavBar)
    {
        NavBar->setWindowTitle(QApplication::translate("NavBar", "Form", 0, QApplication::UnicodeUTF8));
        BackButton->setText(QApplication::translate("NavBar", "(<-)", 0, QApplication::UnicodeUTF8));
        BackLabel->setText(QApplication::translate("NavBar", "1 :Choose Patient", 0, QApplication::UnicodeUTF8));
        CurrentLabel->setText(QApplication::translate("NavBar", " Step 2: Patient History", 0, QApplication::UnicodeUTF8));
        NxtLabel->setText(QApplication::translate("NavBar", "3: Scan", 0, QApplication::UnicodeUTF8));
        NxtButton->setText(QApplication::translate("NavBar", "(->)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NavBar: public Ui_NavBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVBAR_H
