/****************************************************************************
** Meta object code from reading C++ file 'loginpage.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UI/loginpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LoginPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      33,   10,   10,   10, 0x0a,
      62,   10,   10,   10, 0x0a,
      87,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LoginPage[] = {
    "LoginPage\0\0pwd\0password(QString)\0"
    "on_PwdEdit_editingFinished()\0"
    "on_StartButton_clicked()\0on_SRButton_clicked()\0"
};

void LoginPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LoginPage *_t = static_cast<LoginPage *>(_o);
        switch (_id) {
        case 0: _t->password((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_PwdEdit_editingFinished(); break;
        case 2: _t->on_StartButton_clicked(); break;
        case 3: _t->on_SRButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LoginPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LoginPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LoginPage,
      qt_meta_data_LoginPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LoginPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LoginPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LoginPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LoginPage))
        return static_cast<void*>(const_cast< LoginPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int LoginPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void LoginPage::password(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
