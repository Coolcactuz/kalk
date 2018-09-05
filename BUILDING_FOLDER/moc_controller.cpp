/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Controller/controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_controller_t {
    QByteArrayData data[11];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_controller_t qt_meta_stringdata_controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "controller"
QT_MOC_LITERAL(1, 11, 22), // "data_controller_to_GUI"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 13), // "CtV_exception"
QT_MOC_LITERAL(4, 49, 8), // "defineTC"
QT_MOC_LITERAL(5, 58, 22), // "data_GUI_to_controller"
QT_MOC_LITERAL(6, 81, 11), // "soraz_logic"
QT_MOC_LITERAL(7, 93, 17), // "socomplesso_logic"
QT_MOC_LITERAL(8, 111, 20), // "circuito_cambia_volt"
QT_MOC_LITERAL(9, 132, 20), // "circuito_cambia_freq"
QT_MOC_LITERAL(10, 153, 18) // "gestisci_emergenza"

    },
    "controller\0data_controller_to_GUI\0\0"
    "CtV_exception\0defineTC\0data_GUI_to_controller\0"
    "soraz_logic\0socomplesso_logic\0"
    "circuito_cambia_volt\0circuito_cambia_freq\0"
    "gestisci_emergenza"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    2,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   67,    2, 0x08 /* Private */,
       5,    1,   70,    2, 0x08 /* Private */,
       6,    1,   73,    2, 0x08 /* Private */,
       7,    1,   76,    2, 0x08 /* Private */,
       8,    1,   79,    2, 0x08 /* Private */,
       9,    1,   82,    2, 0x08 /* Private */,
      10,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,

       0        // eod
};

void controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        controller *_t = static_cast<controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->data_controller_to_GUI((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->CtV_exception((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->defineTC((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->data_GUI_to_controller((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->soraz_logic((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->socomplesso_logic((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->circuito_cambia_volt((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->circuito_cambia_freq((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->gestisci_emergenza(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (controller::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&controller::data_controller_to_GUI)) {
                *result = 0;
            }
        }
        {
            typedef void (controller::*_t)(QString , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&controller::CtV_exception)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_controller.data,
      qt_meta_data_controller,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *controller::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_controller.stringdata0))
        return static_cast<void*>(const_cast< controller*>(this));
    return QObject::qt_metacast(_clname);
}

int controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void controller::data_controller_to_GUI(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void controller::CtV_exception(QString _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
