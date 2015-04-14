/********************************************************************************
** Form generated from reading UI file 'patientdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTDIALOG_H
#define UI_PATIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PatientDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *patientButton;
    QPushButton *editButton;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *PatientDialog)
    {
        if (PatientDialog->objectName().isEmpty())
            PatientDialog->setObjectName(QString::fromUtf8("PatientDialog"));
        PatientDialog->setWindowModality(Qt::ApplicationModal);
        PatientDialog->resize(500, 215);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PatientDialog->sizePolicy().hasHeightForWidth());
        PatientDialog->setSizePolicy(sizePolicy);
        PatientDialog->setMinimumSize(QSize(500, 215));
        PatientDialog->setFocusPolicy(Qt::StrongFocus);
        PatientDialog->setModal(true);
        verticalLayout_2 = new QVBoxLayout(PatientDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(PatientDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        verticalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        patientButton = new QPushButton(PatientDialog);
        patientButton->setObjectName(QString::fromUtf8("patientButton"));
        patientButton->setMinimumSize(QSize(150, 40));

        verticalLayout->addWidget(patientButton);

        editButton = new QPushButton(PatientDialog);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setMinimumSize(QSize(150, 40));

        verticalLayout->addWidget(editButton);

        cancelButton = new QPushButton(PatientDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setMinimumSize(QSize(150, 40));

        verticalLayout->addWidget(cancelButton);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(PatientDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), PatientDialog, SLOT(reject()));
        QObject::connect(editButton, SIGNAL(clicked()), PatientDialog, SLOT(accept()));
        QObject::connect(patientButton, SIGNAL(clicked()), PatientDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(PatientDialog);
    } // setupUi

    void retranslateUi(QDialog *PatientDialog)
    {
        PatientDialog->setWindowTitle(QApplication::translate("PatientDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PatientDialog", "This patient is usually treated by another doctor, \n"
" how would you like to proceed?", 0, QApplication::UnicodeUTF8));
        patientButton->setText(QApplication::translate("PatientDialog", "Make my patient", 0, QApplication::UnicodeUTF8));
        editButton->setText(QApplication::translate("PatientDialog", "Edit only", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("PatientDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PatientDialog: public Ui_PatientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTDIALOG_H
