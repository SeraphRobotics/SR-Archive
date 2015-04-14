/****************************************************************************
** Meta object code from reading C++ file 'navbar.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UI/navbar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'navbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NavBar[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      15,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   22,    7,    7, 0x0a,
      47,    7,    7,    7, 0x08,
      71,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NavBar[] = {
    "NavBar\0\0next()\0back()\0page_number\0"
    "setPage(int)\0on_BackButton_clicked()\0"
    "on_NxtButton_clicked()\0"
};

void NavBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NavBar *_t = static_cast<NavBar *>(_o);
        switch (_id) {
        case 0: _t->next(); break;
        case 1: _t->back(); break;
        case 2: _t->setPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_BackButton_clicked(); break;
        case 4: _t->on_NxtButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NavBar::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NavBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NavBar,
      qt_meta_data_NavBar, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NavBar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NavBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NavBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NavBar))
        return static_cast<void*>(const_cast< NavBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int NavBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void NavBar::next()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void NavBar::back()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
