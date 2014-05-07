/****************************************************************************
** Meta object code from reading C++ file 'MVC.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../QMVC/MVC.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MVC.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MVCModel_t {
    QByteArrayData data[3];
    char stringdata[19];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MVCModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MVCModel_t qt_meta_stringdata_MVCModel = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 7),
QT_MOC_LITERAL(2, 17, 0)
    },
    "MVCModel\0changed\0\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MVCModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void MVCModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MVCModel *_t = static_cast<MVCModel *>(_o);
        switch (_id) {
        case 0: _t->changed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MVCModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MVCModel::changed)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MVCModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MVCModel.data,
      qt_meta_data_MVCModel,  qt_static_metacall, 0, 0}
};


const QMetaObject *MVCModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MVCModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MVCModel.stringdata))
        return static_cast<void*>(const_cast< MVCModel*>(this));
    return QObject::qt_metacast(_clname);
}

int MVCModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void MVCModel::changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
struct qt_meta_stringdata_MVCController_t {
    QByteArrayData data[8];
    char stringdata[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MVCController_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MVCController_t qt_meta_stringdata_MVCController = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 13),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 17),
QT_MOC_LITERAL(4, 47, 3),
QT_MOC_LITERAL(5, 51, 25),
QT_MOC_LITERAL(6, 77, 1),
QT_MOC_LITERAL(7, 79, 10)
    },
    "MVCController\0eventCaptured\0\0"
    "MVCMacro::EventId\0eid\0QGraphicsSceneMouseEvent*\0"
    "e\0QKeyEvent*\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MVCController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x0a,
       1,    2,   29,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 7,    4,    6,

       0        // eod
};

void MVCController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MVCController *_t = static_cast<MVCController *>(_o);
        switch (_id) {
        case 0: _t->eventCaptured((*reinterpret_cast< MVCMacro::EventId(*)>(_a[1])),(*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[2]))); break;
        case 1: _t->eventCaptured((*reinterpret_cast< MVCMacro::EventId(*)>(_a[1])),(*reinterpret_cast< QKeyEvent*(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject MVCController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MVCController.data,
      qt_meta_data_MVCController,  qt_static_metacall, 0, 0}
};


const QMetaObject *MVCController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MVCController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MVCController.stringdata))
        return static_cast<void*>(const_cast< MVCController*>(this));
    return QObject::qt_metacast(_clname);
}

int MVCController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_MVCView_t {
    QByteArrayData data[8];
    char stringdata[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MVCView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MVCView_t qt_meta_stringdata_MVCView = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 6),
QT_MOC_LITERAL(2, 15, 0),
QT_MOC_LITERAL(3, 16, 13),
QT_MOC_LITERAL(4, 30, 17),
QT_MOC_LITERAL(5, 48, 25),
QT_MOC_LITERAL(6, 74, 10),
QT_MOC_LITERAL(7, 85, 10)
    },
    "MVCView\0update\0\0eventCaptured\0"
    "MVCMacro::EventId\0QGraphicsSceneMouseEvent*\0"
    "QKeyEvent*\0invalidate\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MVCView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06,
       3,    2,   35,    2, 0x06,
       3,    2,   40,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    0,   45,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 5,    2,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    2,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void MVCView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MVCView *_t = static_cast<MVCView *>(_o);
        switch (_id) {
        case 0: _t->update(); break;
        case 1: _t->eventCaptured((*reinterpret_cast< MVCMacro::EventId(*)>(_a[1])),(*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[2]))); break;
        case 2: _t->eventCaptured((*reinterpret_cast< MVCMacro::EventId(*)>(_a[1])),(*reinterpret_cast< QKeyEvent*(*)>(_a[2]))); break;
        case 3: _t->invalidate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MVCView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MVCView::update)) {
                *result = 0;
            }
        }
        {
            typedef void (MVCView::*_t)(MVCMacro::EventId , QGraphicsSceneMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MVCView::eventCaptured)) {
                *result = 1;
            }
        }
        {
            typedef void (MVCView::*_t)(MVCMacro::EventId , QKeyEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MVCView::eventCaptured)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject MVCView::staticMetaObject = {
    { &QGraphicsObject::staticMetaObject, qt_meta_stringdata_MVCView.data,
      qt_meta_data_MVCView,  qt_static_metacall, 0, 0}
};


const QMetaObject *MVCView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MVCView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MVCView.stringdata))
        return static_cast<void*>(const_cast< MVCView*>(this));
    return QGraphicsObject::qt_metacast(_clname);
}

int MVCView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MVCView::update()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MVCView::eventCaptured(MVCMacro::EventId _t1, QGraphicsSceneMouseEvent * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MVCView::eventCaptured(MVCMacro::EventId _t1, QKeyEvent * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_MVCPixmap_t {
    QByteArrayData data[1];
    char stringdata[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MVCPixmap_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MVCPixmap_t qt_meta_stringdata_MVCPixmap = {
    {
QT_MOC_LITERAL(0, 0, 9)
    },
    "MVCPixmap\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MVCPixmap[] = {

 // content:
       7,       // revision
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

void MVCPixmap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MVCPixmap::staticMetaObject = {
    { &QGraphicsObject::staticMetaObject, qt_meta_stringdata_MVCPixmap.data,
      qt_meta_data_MVCPixmap,  qt_static_metacall, 0, 0}
};


const QMetaObject *MVCPixmap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MVCPixmap::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MVCPixmap.stringdata))
        return static_cast<void*>(const_cast< MVCPixmap*>(this));
    return QGraphicsObject::qt_metacast(_clname);
}

int MVCPixmap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
