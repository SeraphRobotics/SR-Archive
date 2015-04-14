/****************************************************************************
** Meta object code from reading C++ file 'radio.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UI/radio.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'radio.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Radio[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,   26,    6,    6, 0x0a,
      51,    6,    6,    6, 0x08,
      69,    6,    6,    6, 0x08,
      88,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Radio[] = {
    "Radio\0\0ScanType(scanfeet)\0sf\0"
    "setScanType(scanfeet)\0on_Both_clicked()\0"
    "on_Right_clicked()\0on_Left_clicked()\0"
};

void Radio::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Radio *_t = static_cast<Radio *>(_o);
        switch (_id) {
        case 0: _t->ScanType((*reinterpret_cast< scanfeet(*)>(_a[1]))); break;
        case 1: _t->setScanType((*reinterpret_cast< scanfeet(*)>(_a[1]))); break;
        case 2: _t->on_Both_clicked(); break;
        case 3: _t->on_Right_clicked(); break;
        case 4: _t->on_Left_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Radio::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Radio::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Radio,
      qt_meta_data_Radio, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Radio::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Radio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Radio::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Radio))
        return static_cast<void*>(const_cast< Radio*>(this));
    return QWidget::qt_metacast(_clname);
}

int Radio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Radio::ScanType(scanfeet _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_HorizontalRadio[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_HorizontalRadio[] = {
    "HorizontalRadio\0"
};

void HorizontalRadio::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData HorizontalRadio::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HorizontalRadio::staticMetaObject = {
    { &Radio::staticMetaObject, qt_meta_stringdata_HorizontalRadio,
      qt_meta_data_HorizontalRadio, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HorizontalRadio::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HorizontalRadio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HorizontalRadio::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HorizontalRadio))
        return static_cast<void*>(const_cast< HorizontalRadio*>(this));
    return Radio::qt_metacast(_clname);
}

int HorizontalRadio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Radio::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_VerticalRadio[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_VerticalRadio[] = {
    "VerticalRadio\0"
};

void VerticalRadio::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData VerticalRadio::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VerticalRadio::staticMetaObject = {
    { &Radio::staticMetaObject, qt_meta_stringdata_VerticalRadio,
      qt_meta_data_VerticalRadio, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VerticalRadio::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VerticalRadio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VerticalRadio::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VerticalRadio))
        return static_cast<void*>(const_cast< VerticalRadio*>(this));
    return Radio::qt_metacast(_clname);
}

int VerticalRadio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Radio::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
