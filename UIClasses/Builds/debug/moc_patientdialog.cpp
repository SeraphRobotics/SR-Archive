/****************************************************************************
** Meta object code from reading C++ file 'patientdialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UI/patientdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'patientdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PatientDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      29,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,   14,   14,   14, 0x0a,
      67,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PatientDialog[] = {
    "PatientDialog\0\0makePatient()\0editOnly()\0"
    "on_patientButton_clicked()\0"
    "on_editButton_clicked()\0"
};

void PatientDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PatientDialog *_t = static_cast<PatientDialog *>(_o);
        switch (_id) {
        case 0: _t->makePatient(); break;
        case 1: _t->editOnly(); break;
        case 2: _t->on_patientButton_clicked(); break;
        case 3: _t->on_editButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData PatientDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PatientDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PatientDialog,
      qt_meta_data_PatientDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PatientDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PatientDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PatientDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PatientDialog))
        return static_cast<void*>(const_cast< PatientDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int PatientDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void PatientDialog::makePatient()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void PatientDialog::editOnly()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
