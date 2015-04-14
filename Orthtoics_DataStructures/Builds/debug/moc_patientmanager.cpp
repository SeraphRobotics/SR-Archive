/****************************************************************************
** Meta object code from reading C++ file 'patientmanager.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Software/DataStructures/patientmanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'patientmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PatientManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   16,   15,   15, 0x0a,
      51,   49,   15,   15, 0x0a,
      81,   71,   15,   15, 0x0a,
     104,   15,   15,   15, 0x0a,
     118,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PatientManager[] = {
    "PatientManager\0\0PatientID,r\0"
    "updateRx(QString,Rx)\0P\0addPatient(Patient)\0"
    "PatientID\0removePatient(QString)\0"
    "writeToDisk()\0rescan()\0"
};

void PatientManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PatientManager *_t = static_cast<PatientManager *>(_o);
        switch (_id) {
        case 0: _t->updateRx((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< Rx(*)>(_a[2]))); break;
        case 1: _t->addPatient((*reinterpret_cast< Patient(*)>(_a[1]))); break;
        case 2: _t->removePatient((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->writeToDisk(); break;
        case 4: _t->rescan(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PatientManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PatientManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PatientManager,
      qt_meta_data_PatientManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PatientManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PatientManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PatientManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PatientManager))
        return static_cast<void*>(const_cast< PatientManager*>(this));
    return QObject::qt_metacast(_clname);
}

int PatientManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
