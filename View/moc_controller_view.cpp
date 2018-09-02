/****************************************************************************
** Meta object code from reading C++ file 'controller_view.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "controller_view.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller_view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_controller_view_t {
    QByteArrayData data[9];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_controller_view_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_controller_view_t qt_meta_stringdata_controller_view = {
    {
QT_MOC_LITERAL(0, 0, 15), // "controller_view"
QT_MOC_LITERAL(1, 16, 9), // "inviaTipo"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "inviaStringa"
QT_MOC_LITERAL(4, 40, 11), // "inviaResult"
QT_MOC_LITERAL(5, 52, 11), // "SOComplesso"
QT_MOC_LITERAL(6, 64, 5), // "SORaz"
QT_MOC_LITERAL(7, 70, 17), // "createSpecialized"
QT_MOC_LITERAL(8, 88, 13) // "createStartup"

    },
    "controller_view\0inviaTipo\0\0inviaStringa\0"
    "inviaResult\0SOComplesso\0SORaz\0"
    "createSpecialized\0createStartup"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_controller_view[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,
       4,    1,   55,    2, 0x06 /* Public */,
       5,    1,   58,    2, 0x06 /* Public */,
       6,    1,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   64,    2, 0x0a /* Public */,
       8,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void controller_view::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        controller_view *_t = static_cast<controller_view *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->inviaTipo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->inviaStringa((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->inviaResult((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->SOComplesso((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->SORaz((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->createSpecialized((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->createStartup(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (controller_view::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&controller_view::inviaTipo)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (controller_view::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&controller_view::inviaStringa)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (controller_view::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&controller_view::inviaResult)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (controller_view::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&controller_view::SOComplesso)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (controller_view::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&controller_view::SORaz)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject controller_view::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_controller_view.data,
      qt_meta_data_controller_view,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *controller_view::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *controller_view::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_controller_view.stringdata0))
        return static_cast<void*>(const_cast< controller_view*>(this));
    return QObject::qt_metacast(_clname);
}

int controller_view::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void controller_view::inviaTipo(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void controller_view::inviaStringa(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void controller_view::inviaResult(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void controller_view::SOComplesso(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void controller_view::SORaz(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
