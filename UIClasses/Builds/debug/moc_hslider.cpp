/****************************************************************************
** Meta object code from reading C++ file 'hslider.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UI/hslider.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hslider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HSlider[] = {

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
      11,    9,    8,    8, 0x0a,
      49,    8,    8,    8, 0x0a,
      74,    8,    8,    8, 0x0a,
      98,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_HSlider[] = {
    "HSlider\0\0i\0on_horizontalSlider_valueChanged(int)\0"
    "on_minusButton_clicked()\0"
    "on_plusButton_clicked()\0"
    "on_doubleSpinBox_editingFinished()\0"
};

void HSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HSlider *_t = static_cast<HSlider *>(_o);
        switch (_id) {
        case 0: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_minusButton_clicked(); break;
        case 2: _t->on_plusButton_clicked(); break;
        case 3: _t->on_doubleSpinBox_editingFinished(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData HSlider::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HSlider::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HSlider,
      qt_meta_data_HSlider, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HSlider::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HSlider))
        return static_cast<void*>(const_cast< HSlider*>(this));
    return QWidget::qt_metacast(_clname);
}

int HSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
