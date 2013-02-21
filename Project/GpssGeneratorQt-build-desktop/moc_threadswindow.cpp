/****************************************************************************
** Meta object code from reading C++ file 'threadswindow.h'
**
** Created: Thu Feb 21 19:16:09 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GpssGeneratorQt/threadswindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threadswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GeneratorGpss__ThreadsWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      30,   29,   29,   29, 0x0a,
      47,   29,   29,   29, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GeneratorGpss__ThreadsWindow[] = {
    "GeneratorGpss::ThreadsWindow\0\0"
    "addThreadClick()\0deleteThreadClick()\0"
};

void GeneratorGpss::ThreadsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ThreadsWindow *_t = static_cast<ThreadsWindow *>(_o);
        switch (_id) {
        case 0: _t->addThreadClick(); break;
        case 1: _t->deleteThreadClick(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData GeneratorGpss::ThreadsWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GeneratorGpss::ThreadsWindow::staticMetaObject = {
    { &AbstractNavigatableWindow::staticMetaObject, qt_meta_stringdata_GeneratorGpss__ThreadsWindow,
      qt_meta_data_GeneratorGpss__ThreadsWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GeneratorGpss::ThreadsWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GeneratorGpss::ThreadsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GeneratorGpss::ThreadsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GeneratorGpss__ThreadsWindow))
        return static_cast<void*>(const_cast< ThreadsWindow*>(this));
    return AbstractNavigatableWindow::qt_metacast(_clname);
}

int GeneratorGpss::ThreadsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractNavigatableWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_GeneratorGpss__ThreadWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      31,   29,   28,   28, 0x0a,
      48,   29,   28,   28, 0x0a,
      65,   29,   28,   28, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GeneratorGpss__ThreadWidget[] = {
    "GeneratorGpss::ThreadWidget\0\0i\0"
    "typeChanged(int)\0funcChanged(int)\0"
    "priorityTypeChanged(int)\0"
};

void GeneratorGpss::ThreadWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ThreadWidget *_t = static_cast<ThreadWidget *>(_o);
        switch (_id) {
        case 0: _t->typeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->funcChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->priorityTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GeneratorGpss::ThreadWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GeneratorGpss::ThreadWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GeneratorGpss__ThreadWidget,
      qt_meta_data_GeneratorGpss__ThreadWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GeneratorGpss::ThreadWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GeneratorGpss::ThreadWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GeneratorGpss::ThreadWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GeneratorGpss__ThreadWidget))
        return static_cast<void*>(const_cast< ThreadWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int GeneratorGpss::ThreadWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
