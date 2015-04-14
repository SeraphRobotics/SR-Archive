/****************************************************************************
** Meta object code from reading C++ file 'scan.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Software/DataStructures/scan.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scan.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Scan[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x0a,
      14,    5,    5,    5, 0x0a,
      33,   28,    5,    5, 0x0a,
      64,   28,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Scan[] = {
    "Scan\0\0reset()\0writeToDisk()\0grid\0"
    "setInitialData(XYGrid<float>*)\0"
    "setProcessedGrid(XYGrid<float>*)\0"
};

void Scan::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Scan *_t = static_cast<Scan *>(_o);
        switch (_id) {
        case 0: _t->reset(); break;
        case 1: _t->writeToDisk(); break;
        case 2: _t->setInitialData((*reinterpret_cast< XYGrid<float>*(*)>(_a[1]))); break;
        case 3: _t->setProcessedGrid((*reinterpret_cast< XYGrid<float>*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Scan::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Scan::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Scan,
      qt_meta_data_Scan, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Scan::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Scan::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Scan::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Scan))
        return static_cast<void*>(const_cast< Scan*>(this));
    return QObject::qt_metacast(_clname);
}

int Scan::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
