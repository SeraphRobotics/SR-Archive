/****************************************************************************
** Meta object code from reading C++ file 'printerpages.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UI/printerpages.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'printerpages.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PrinterPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      21,   12,   12,   12, 0x05,
      29,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   12,   12,   12, 0x0a,
      63,   12,   12,   12, 0x0a,
      88,   12,   12,   12, 0x0a,
     131,  114,   12,   12, 0x0a,
     159,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PrinterPage[] = {
    "PrinterPage\0\0start()\0pause()\0cancel()\0"
    "on_StartButton_clicked()\0"
    "on_pauseButton_clicked()\0"
    "on_cancelButton_clicked()\0left,right,total\0"
    "setTimes(float,float,float)\0completed()\0"
};

void PrinterPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PrinterPage *_t = static_cast<PrinterPage *>(_o);
        switch (_id) {
        case 0: _t->start(); break;
        case 1: _t->pause(); break;
        case 2: _t->cancel(); break;
        case 3: _t->on_StartButton_clicked(); break;
        case 4: _t->on_pauseButton_clicked(); break;
        case 5: _t->on_cancelButton_clicked(); break;
        case 6: _t->setTimes((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 7: _t->completed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PrinterPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PrinterPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PrinterPage,
      qt_meta_data_PrinterPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PrinterPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PrinterPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PrinterPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PrinterPage))
        return static_cast<void*>(const_cast< PrinterPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int PrinterPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void PrinterPage::start()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void PrinterPage::pause()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void PrinterPage::cancel()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
static const uint qt_meta_data_ScanPage[] = {

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

static const char qt_meta_stringdata_ScanPage[] = {
    "ScanPage\0"
};

void ScanPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ScanPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ScanPage::staticMetaObject = {
    { &PrinterPage::staticMetaObject, qt_meta_stringdata_ScanPage,
      qt_meta_data_ScanPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ScanPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ScanPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ScanPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScanPage))
        return static_cast<void*>(const_cast< ScanPage*>(this));
    return PrinterPage::qt_metacast(_clname);
}

int ScanPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PrinterPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_CreatePage[] = {

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

static const char qt_meta_stringdata_CreatePage[] = {
    "CreatePage\0"
};

void CreatePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CreatePage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CreatePage::staticMetaObject = {
    { &PrinterPage::staticMetaObject, qt_meta_stringdata_CreatePage,
      qt_meta_data_CreatePage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CreatePage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CreatePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CreatePage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CreatePage))
        return static_cast<void*>(const_cast< CreatePage*>(this));
    return PrinterPage::qt_metacast(_clname);
}

int CreatePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PrinterPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
