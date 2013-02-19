/****************************************************************************
** Meta object code from reading C++ file 'transferwindow.h'
**
** Created: Sun Jan 20 20:03:27 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GpssGeneratorQt/transferwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'transferwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GeneratorGpss__TransferWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      31,   30,   30,   30, 0x0a,
      48,   30,   30,   30, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GeneratorGpss__TransferWindow[] = {
    "GeneratorGpss::TransferWindow\0\0"
    "nextBtnClicked()\0prevBtnClicked()\0"
};

const QMetaObject GeneratorGpss::TransferWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GeneratorGpss__TransferWindow,
      qt_meta_data_GeneratorGpss__TransferWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GeneratorGpss::TransferWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GeneratorGpss::TransferWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GeneratorGpss::TransferWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GeneratorGpss__TransferWindow))
        return static_cast<void*>(const_cast< TransferWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int GeneratorGpss::TransferWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: nextBtnClicked(); break;
        case 1: prevBtnClicked(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_GeneratorGpss__TransferThreadParams[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      37,   36,   36,   36, 0x0a,
      55,   36,   36,   36, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GeneratorGpss__TransferThreadParams[] = {
    "GeneratorGpss::TransferThreadParams\0"
    "\0addTransferNode()\0deleteTransferNode()\0"
};

const QMetaObject GeneratorGpss::TransferThreadParams::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GeneratorGpss__TransferThreadParams,
      qt_meta_data_GeneratorGpss__TransferThreadParams, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GeneratorGpss::TransferThreadParams::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GeneratorGpss::TransferThreadParams::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GeneratorGpss::TransferThreadParams::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GeneratorGpss__TransferThreadParams))
        return static_cast<void*>(const_cast< TransferThreadParams*>(this));
    return QWidget::qt_metacast(_clname);
}

int GeneratorGpss::TransferThreadParams::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addTransferNode(); break;
        case 1: deleteTransferNode(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_GeneratorGpss__TransferNodeParams[] = {

 // content:
       5,       // revision
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

static const char qt_meta_stringdata_GeneratorGpss__TransferNodeParams[] = {
    "GeneratorGpss::TransferNodeParams\0"
};

const QMetaObject GeneratorGpss::TransferNodeParams::staticMetaObject = {
    { &QHBoxLayout::staticMetaObject, qt_meta_stringdata_GeneratorGpss__TransferNodeParams,
      qt_meta_data_GeneratorGpss__TransferNodeParams, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GeneratorGpss::TransferNodeParams::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GeneratorGpss::TransferNodeParams::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GeneratorGpss::TransferNodeParams::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GeneratorGpss__TransferNodeParams))
        return static_cast<void*>(const_cast< TransferNodeParams*>(this));
    return QHBoxLayout::qt_metacast(_clname);
}

int GeneratorGpss::TransferNodeParams::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QHBoxLayout::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
