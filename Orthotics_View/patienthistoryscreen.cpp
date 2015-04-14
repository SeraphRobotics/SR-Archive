#include "patienthistoryscreen.h"

PatientHistoryScreen::PatientHistoryScreen(QWidget *parent) :
    QWidget(parent)
{


    layout = new QVBoxLayout(this);

    QGridLayout *topLayout = new QGridLayout(this);

    lblCurrentStep = new QLabel(tr("step 2: patient history"));
    btnNextScreen = new QPushButton(tr("3: scan:"));
    btnPrevScreen = new QPushButton(tr("1: choose patient"));

    topLayout->addWidget(btnPrevScreen, 0, 0);
    topLayout->addWidget(lblCurrentStep, 0, 1, 1, 1, Qt::AlignCenter);
    topLayout->addWidget(btnNextScreen, 0, 2, 1, 1, Qt::AlignRight);

    layout->addLayout(topLayout);

    // Instantiate Objects
    txtLName = new QLineEdit(this);
    txtFName = new QLineEdit(this);
    txtDate = new QDateEdit(this);
    txtOccupation = new QLineEdit(this);

    vAge = new QIntValidator(1, 100, this);
    txtAge = new QLineEdit(this);
    txtAge->setValidator(vAge);

    cmbSex = new QComboBox(this);

    cmbHeightFt = new QComboBox(this);
    cmbHeightIn = new QComboBox(this);

    vWeight = new QIntValidator(0, 500, this);
    txtWeight = new QLineEdit(this);
    txtWeight->setValidator(vWeight);

    txtShoeSize = new QDoubleSpinBox(this);
    txtShoeSize->setRange(3.0, 18.0);
    txtShoeSize->setSingleStep(0.5);
    txtShoeSize->setDecimals(1);
    txtShoeSize->setValue(9.0);

    cmbShoeWidth = new QComboBox(this);

    vHeelHeight = new QDoubleValidator(0.0, 4.0, 1, this);
    txtHeelHeight = new QLineEdit(this);
    txtHeelHeight->setValidator(vHeelHeight);

    cmbShoeStyle = new QComboBox(this);

    txtComplaints = new QTextEdit(this);
    txtDiagnosis = new QTextEdit(this);
    txtPhysicalActivityLevel = new QTextEdit(this);

    lblComplaints = new QLabel(tr("Chief Complaint"));
    lblDiagnosis = new QLabel(tr("Diagnosis"));
    lblPhysicalActivityLevel = new QLabel(tr("Physical Activity Level"));

    lblComplaints->setBuddy(txtComplaints);
    lblDiagnosis->setBuddy(txtDiagnosis);
    lblPhysicalActivityLevel->setBuddy(txtPhysicalActivityLevel);

    QFormLayout *formLayout0 = new QFormLayout(this);
    QFormLayout *formLayout1 = new QFormLayout(this);
    QFormLayout *formLayout2 = new QFormLayout(this);
    QFormLayout *formLayout3 = new QFormLayout(this);

    QGridLayout *gridLayout0 = new QGridLayout(this);
    QGridLayout *gridLayout1 = new QGridLayout(this);
    QGridLayout *gridLayout2 = new QGridLayout(this);

    QHBoxLayout* heightLayout = new QHBoxLayout(this);
    heightLayout->setSpacing(1);

    heightLayout->addWidget(cmbHeightFt);
    heightLayout->addWidget(new QLabel(tr("' ")));
    heightLayout->addWidget(cmbHeightIn);
    heightLayout->addWidget(new QLabel(tr("\"")));

    formLayout0->addRow(tr("Last Name:"), txtLName);
    formLayout0->addRow(tr("First Name:"), txtFName);
    formLayout0->addRow(tr("Occupation:"), txtOccupation);

    formLayout1->addRow(tr("Date:"), txtDate);

    formLayout2->addRow(tr("Age:"), txtAge);
    formLayout2->addRow(tr("Sex:"), cmbSex);
    formLayout2->addRow(tr("Height:"), heightLayout);
    formLayout2->addRow(tr("Weight:"), txtWeight);

    formLayout3->setFormAlignment(Qt::AlignRight|Qt::AlignTop);
    formLayout3->addRow(tr("Shoe Size:"), txtShoeSize);
    formLayout3->addRow(tr("Shoe Width"), cmbShoeWidth);
    formLayout3->addRow(tr("Heel Height"), txtHeelHeight);
    formLayout3->addRow(tr("Shoe Style:"), cmbShoeStyle);

    gridLayout0->addLayout(formLayout0, 0, 0, 1, 1, Qt::AlignCenter);
    gridLayout0->addLayout(formLayout1, 0, 1, 1, 1, Qt::AlignCenter);
    gridLayout1->addLayout(formLayout2, 0, 0, 1, 1, Qt::AlignCenter);
    gridLayout1->addLayout(formLayout3, 0, 1, 1, 1, Qt::AlignCenter);

    gridLayout2->addWidget(lblComplaints, 0, 0);
    gridLayout2->addWidget(lblDiagnosis, 0, 1);
    gridLayout2->addWidget(lblPhysicalActivityLevel, 0, 2);
    gridLayout2->addWidget(txtComplaints, 1, 0);
    gridLayout2->addWidget(txtDiagnosis, 1, 1);
    gridLayout2->addWidget(txtPhysicalActivityLevel, 1, 2);

    layout->addLayout(gridLayout0);
    layout->addLayout(gridLayout1);
    layout->addLayout(gridLayout2);

    setLayout(layout);

    // Set mapping data
    QStringList sexes;
    sexes.append(tr("Male"));
    sexes.append(tr("Female"));


    cmbSex->setModel(new QStringListModel(sexes));

    mapData = 0;
    mdlData = 0;
    mdlShoeStyles = 0;


    QStringList heightIn;
    heightIn.append("0");
    heightIn.append("1");
    heightIn.append("2");
    heightIn.append("3");
    heightIn.append("4");
    heightIn.append("5");
    heightIn.append("6");
    heightIn.append("7");
    heightIn.append("8");
    heightIn.append("9");
    heightIn.append("10");
    heightIn.append("11");

    cmbHeightIn->setModel(new QStringListModel(heightIn));

    QStringList heightFt;
    heightFt.append("0");
    heightFt.append("1");
    heightFt.append("2");
    heightFt.append("3");
    heightFt.append("4");
    heightFt.append("5");
    heightFt.append("6");
    heightFt.append("7");
    heightFt.append("8");

    cmbHeightFt->setModel(new QStringListModel(heightFt));


    QStringList shoeWidths;
    shoeWidths.append("A");
    shoeWidths.append("B");
    shoeWidths.append("C");
    shoeWidths.append("D");
    shoeWidths.append("E");
    shoeWidths.append("EE");
    shoeWidths.append("EEE");
    shoeWidths.append("EEEE");
    shoeWidths.append("F");
    shoeWidths.append("G");

    cmbShoeWidth->setModel(new QStringListModel(shoeWidths));
}

PatientHistoryScreen::~PatientHistoryScreen()
{

    delete mapData;
    delete mdlData;
    delete mdlShoeStyles;

    delete layout;

    delete txtLName;
    delete txtFName;
    delete txtDate;
    delete txtOccupation;
    delete txtAge;
    delete cmbSex;
    delete cmbHeightFt;
    delete cmbHeightIn;
    delete txtWeight;
    delete txtShoeSize;
    delete cmbShoeWidth;
    delete txtHeelHeight;
    delete cmbShoeStyle;

    delete lblComplaints;
    delete lblDiagnosis;
    delete lblPhysicalActivityLevel;

    delete txtComplaints;
    delete txtDiagnosis;
    delete txtPhysicalActivityLevel;
}

void PatientHistoryScreen::updateModel()
{

    mapData->setModel(mdlData);
    mapData->toFirst();

    intPatientID = mdlData->data(mdlData->index(0, 15), Qt::DisplayRole).toInt();

    mapData->addMapping(txtLName, 0);
    mapData->addMapping(txtFName, 1);
    mapData->addMapping(txtDate, 2);
    mapData->addMapping(txtOccupation, 3);
    mapData->addMapping(txtAge, 4);
    mapData->addMapping(cmbSex, 5, "currentIndex");
    //mapData->addMapping(txtHeight, 6);
    mapData->addMapping(cmbHeightFt, 6, "currentIndex");
    mapData->addMapping(cmbHeightIn, 7, "currentIndex");
    mapData->addMapping(txtWeight, 8);
    mapData->addMapping(txtShoeSize, 9);
    mapData->addMapping(cmbShoeWidth, 10, "currentIndex");
    mapData->addMapping(txtHeelHeight, 11);
    mapData->addMapping(cmbShoeStyle, 12, "currentIndex");

    mapData->addMapping(txtComplaints, 13);
    mapData->addMapping(txtDiagnosis, 14);
    mapData->addMapping(txtPhysicalActivityLevel, 15);
}

void PatientHistoryScreen::SetStandardItemModel(QStandardItemModel *dataModel)
{
    mdlData = dataModel;
    updateModel();
}

void PatientHistoryScreen::SetShoeStyleModel(QStringListModel *dataModel)
{
    mdlShoeStyles = dataModel;
    cmbShoeStyle->setModel(mdlShoeStyles);
    cmbShoeStyle->update();
}
