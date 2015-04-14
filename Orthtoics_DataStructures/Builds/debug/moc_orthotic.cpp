/****************************************************************************
** Meta object code from reading C++ file 'orthotic.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Software/DataStructures/orthotic.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'orthotic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Orthotic[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      26,   24,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,   44,    9,    9, 0x0a,
      76,    9,    9,    9, 0x0a,
      83,    9,    9,    9, 0x0a,
      90,    9,    9,    9, 0x0a,
     109,  104,    9,    9, 0x0a,
     126,  124,    9,    9, 0x0a,
     151,  146,    9,    9, 0x0a,
     184,  182,    9,    9, 0x0a,
     209,  207,    9,    9, 0x0a,
     236,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Orthotic[] = {
    "Orthotic\0\0manipulated()\0s\0needScan(QString)\0"
    "m\0addManipulation(Manipulation)\0undo()\0"
    "redo()\0writeToDisk()\0scan\0setScan(Scan*)\0"
    "p\0setPosting(Posting)\0loop\0"
    "setBoundary(FAHLoopInXYPlane*)\0t\0"
    "setFootType(foot_type)\0b\0"
    "setBottomType(bottom_type)\0requestScanData()\0"
};

void Orthotic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Orthotic *_t = static_cast<Orthotic *>(_o);
        switch (_id) {
        case 0: _t->manipulated(); break;
        case 1: _t->needScan((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->addManipulation((*reinterpret_cast< Manipulation(*)>(_a[1]))); break;
        case 3: _t->undo(); break;
        case 4: _t->redo(); break;
        case 5: _t->writeToDisk(); break;
        case 6: _t->setScan((*reinterpret_cast< Scan*(*)>(_a[1]))); break;
        case 7: _t->setPosting((*reinterpret_cast< Posting(*)>(_a[1]))); break;
        case 8: _t->setBoundary((*reinterpret_cast< FAHLoopInXYPlane*(*)>(_a[1]))); break;
        case 9: _t->setFootType((*reinterpret_cast< foot_type(*)>(_a[1]))); break;
        case 10: _t->setBottomType((*reinterpret_cast< bottom_type(*)>(_a[1]))); break;
        case 11: _t->requestScanData(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Orthotic::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Orthotic::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Orthotic,
      qt_meta_data_Orthotic, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Orthotic::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Orthotic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Orthotic::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Orthotic))
        return static_cast<void*>(const_cast< Orthotic*>(this));
    return QObject::qt_metacast(_clname);
}

int Orthotic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Orthotic::manipulated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Orthotic::needScan(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
