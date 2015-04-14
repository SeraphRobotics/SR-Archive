/********************************************************************************
** Form generated from reading UI file 'printerpage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTERPAGE_H
#define UI_PRINTERPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrinterPage
{
public:
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *timeLabel;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QDoubleSpinBox *rightDoubleSpinBox;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QDoubleSpinBox *leftDoubleSpinBox;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QDoubleSpinBox *totalDoubleSpinBox;
    QFrame *line;
    QSpacerItem *horizontalSpacer_6;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout;
    QPushButton *StartButton;
    QSpacerItem *horizontalSpacer_9;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pauseButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *FootGifLable;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *SRButton;

    void setupUi(QWidget *PrinterPage)
    {
        if (PrinterPage->objectName().isEmpty())
            PrinterPage->setObjectName(QString::fromUtf8("PrinterPage"));
        PrinterPage->resize(917, 623);
        horizontalLayout_8 = new QHBoxLayout(PrinterPage);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_4 = new QSpacerItem(20, 598, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        frame = new QFrame(PrinterPage);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(250, 50));
        frame->setMaximumSize(QSize(250, 250));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        timeLabel = new QLabel(frame);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(timeLabel->sizePolicy().hasHeightForWidth());
        timeLabel->setSizePolicy(sizePolicy1);
        timeLabel->setMinimumSize(QSize(0, 10));
        timeLabel->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setPointSize(12);
        timeLabel->setFont(font);
        timeLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(timeLabel);

        verticalSpacer_6 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_6);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(10);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_2);

        rightDoubleSpinBox = new QDoubleSpinBox(frame);
        rightDoubleSpinBox->setObjectName(QString::fromUtf8("rightDoubleSpinBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(rightDoubleSpinBox->sizePolicy().hasHeightForWidth());
        rightDoubleSpinBox->setSizePolicy(sizePolicy2);
        rightDoubleSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        rightDoubleSpinBox->setDecimals(0);

        horizontalLayout_6->addWidget(rightDoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_3);

        leftDoubleSpinBox = new QDoubleSpinBox(frame);
        leftDoubleSpinBox->setObjectName(QString::fromUtf8("leftDoubleSpinBox"));
        sizePolicy2.setHeightForWidth(leftDoubleSpinBox->sizePolicy().hasHeightForWidth());
        leftDoubleSpinBox->setSizePolicy(sizePolicy2);
        leftDoubleSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        leftDoubleSpinBox->setDecimals(0);

        horizontalLayout_5->addWidget(leftDoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_4 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        verticalSpacer_7 = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_4);

        totalDoubleSpinBox = new QDoubleSpinBox(frame);
        totalDoubleSpinBox->setObjectName(QString::fromUtf8("totalDoubleSpinBox"));
        sizePolicy2.setHeightForWidth(totalDoubleSpinBox->sizePolicy().hasHeightForWidth());
        totalDoubleSpinBox->setSizePolicy(sizePolicy2);
        totalDoubleSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        totalDoubleSpinBox->setDecimals(0);

        horizontalLayout_4->addWidget(totalDoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_3->addWidget(frame);

        line = new QFrame(PrinterPage);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);

        horizontalSpacer_6 = new QSpacerItem(20, 128, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        stackedWidget = new QStackedWidget(PrinterPage);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy3);
        stackedWidget->setMinimumSize(QSize(200, 200));
        stackedWidget->setMaximumSize(QSize(16777215, 250));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout = new QHBoxLayout(page);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        StartButton = new QPushButton(page);
        StartButton->setObjectName(QString::fromUtf8("StartButton"));
        sizePolicy.setHeightForWidth(StartButton->sizePolicy().hasHeightForWidth());
        StartButton->setSizePolicy(sizePolicy);
        StartButton->setMinimumSize(QSize(120, 40));

        horizontalLayout->addWidget(StartButton);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        horizontalLayout_2 = new QHBoxLayout(page_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pauseButton = new QPushButton(page_2);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pauseButton->sizePolicy().hasHeightForWidth());
        pauseButton->setSizePolicy(sizePolicy4);
        pauseButton->setMinimumSize(QSize(120, 50));
        pauseButton->setMaximumSize(QSize(200, 50));

        horizontalLayout_2->addWidget(pauseButton);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cancelButton = new QPushButton(page_2);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setMinimumSize(QSize(120, 50));
        cancelButton->setMaximumSize(QSize(200, 50));

        horizontalLayout_2->addWidget(cancelButton);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        stackedWidget->addWidget(page_2);

        horizontalLayout_3->addWidget(stackedWidget);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        horizontalSpacer_8 = new QSpacerItem(0, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        FootGifLable = new QLabel(PrinterPage);
        FootGifLable->setObjectName(QString::fromUtf8("FootGifLable"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(FootGifLable->sizePolicy().hasHeightForWidth());
        FootGifLable->setSizePolicy(sizePolicy5);
        FootGifLable->setMinimumSize(QSize(0, 0));

        horizontalLayout_7->addWidget(FootGifLable);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        verticalSpacer = new QSpacerItem(78, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        SRButton = new QPushButton(PrinterPage);
        SRButton->setObjectName(QString::fromUtf8("SRButton"));
        sizePolicy.setHeightForWidth(SRButton->sizePolicy().hasHeightForWidth());
        SRButton->setSizePolicy(sizePolicy);
        SRButton->setMinimumSize(QSize(100, 100));
        SRButton->setMaximumSize(QSize(100, 100));

        verticalLayout_2->addWidget(SRButton);


        horizontalLayout_7->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_7);


        horizontalLayout_8->addLayout(verticalLayout_4);


        retranslateUi(PrinterPage);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PrinterPage);
    } // setupUi

    void retranslateUi(QWidget *PrinterPage)
    {
        PrinterPage->setWindowTitle(QApplication::translate("PrinterPage", "Form", 0, QApplication::UnicodeUTF8));
        timeLabel->setText(QApplication::translate("PrinterPage", "Estimated Time", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PrinterPage", "Right", 0, QApplication::UnicodeUTF8));
        rightDoubleSpinBox->setSuffix(QApplication::translate("PrinterPage", " Min", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PrinterPage", "Left", 0, QApplication::UnicodeUTF8));
        leftDoubleSpinBox->setSuffix(QApplication::translate("PrinterPage", " Min", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PrinterPage", "Total", 0, QApplication::UnicodeUTF8));
        totalDoubleSpinBox->setSuffix(QApplication::translate("PrinterPage", " Min", 0, QApplication::UnicodeUTF8));
        StartButton->setText(QApplication::translate("PrinterPage", "START", 0, QApplication::UnicodeUTF8));
        pauseButton->setText(QApplication::translate("PrinterPage", "Pause", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("PrinterPage", "Cancel", 0, QApplication::UnicodeUTF8));
        FootGifLable->setText(QApplication::translate("PrinterPage", "footdisplay", 0, QApplication::UnicodeUTF8));
        SRButton->setText(QApplication::translate("PrinterPage", "SR", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PrinterPage: public Ui_PrinterPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTERPAGE_H
