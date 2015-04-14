#include "startpage.h"

StartPage::StartPage(QWidget *parent) :
    QWidget(parent)
{
    layout = new QGridLayout;


    startButton = new QPushButton(this);
    editPassword = new QLineEdit;
    editPassword->setEchoMode(QLineEdit::Password);

    startButton->setStyleSheet("QPushButton { background-color: transparent; background-image: url(\"../Orthotics_View/images/start.png\"); background-repeat:none; border: none; cursor:pointer; }");
    editPassword->setStyleSheet("QLineEdit { border: none; border-radius:8px; }");
    //startButton->setSizePolicy(QSizePolicy::Maximum);
    startButton->setMaximumWidth(155);
    startButton->setMaximumHeight(62);
    editPassword->setMaximumHeight(62);
    editPassword->setMaximumWidth(155);

    editPassword->setAlignment(Qt::AlignCenter);

    QObject::connect(startButton, SIGNAL(clicked()), this, SLOT(startPressed()));
    QObject::connect(editPassword, SIGNAL(returnPressed()), this, SLOT(passwordEntered()));


    layout->addWidget(startButton, 0, 0);
    layout->addWidget(editPassword, 0, 0);
    editPassword->setVisible(false);

    setLayout(layout);
}

void StartPage::startPressed()
{
    startButton->setVisible(false);
    editPassword->setVisible(true);

    editPassword->setFocus(Qt::OtherFocusReason);

}

void StartPage::passwordEntered() {
    qDebug() << "Enter hit";
    emit login(editPassword->text());
}

void StartPage::loggedOut()
{
    startButton->setVisible(true);
    editPassword->setVisible(false);
}

void StartPage::invalidLogin()
{
    // Turn box border red for a short amount and add text saying invalid password
    editPassword->setText("");
    editPassword->setStyleSheet("border: 1px solid red;  border-radius: 8px;");
}


