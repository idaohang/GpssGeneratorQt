/****************************************************************************
** Meta object code from reading C++ file 'nodeswindow.h'
**
** Created: Tue Feb 19 17:35:56 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GpssGeneratorQt/nodeswindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nodeswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GeneratorGpss__NodesWindow[] = {

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
      28,   27,   27,   27, 0x0a,
      43,   27,   27,   27, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GeneratorGpss__NodesWindow[] = {
    "GeneratorGpss::NodesWindow\0\0addNodeClick()\0"
    "deleteNodeClick()\0"
};

void GeneratorGpss::NodesWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NodesWindow *_t = static_cast<NodesWindow *>(_o);
        switch (_id) {
        case 0: _t->addNodeClick(); break;
        case 1: _t->deleteNodeClick(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData GeneratorGpss::NodesWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GeneratorGpss::NodesWindow::staticMetaObject = {
    { &AbstractNavigatableWindow::staticMetaObject, qt_meta_stringdata_GeneratorGpss__NodesWindow,
      qt_meta_data_GeneratorGpss__NodesWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GeneratorGpss::NodesWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GeneratorGpss::NodesWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GeneratorGpss::NodesWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GeneratorGpss__NodesWindow))
        return static_cast<void*>(const_cast< NodesWindow*>(this));
    return AbstractNavigatableWindow::qt_metacast(_clname);
}

int GeneratorGpss::NodesWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
