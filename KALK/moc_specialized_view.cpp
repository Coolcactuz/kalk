/****************************************************************************
** Meta object code from reading C++ file 'specialized_view.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "View/specialized_view_hierarchy/specialized_view.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'specialized_view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_specialized_view_t {
    QByteArrayData data[18];
    char stringdata0[254];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_specialized_view_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_specialized_view_t qt_meta_stringdata_specialized_view = {
    {
QT_MOC_LITERAL(0, 0, 16), // "specialized_view"
QT_MOC_LITERAL(1, 17, 4), // "back"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 7), // "inviaQS"
QT_MOC_LITERAL(4, 31, 10), // "inviaSORaz"
QT_MOC_LITERAL(5, 42, 16), // "inviaSOComplesso"
QT_MOC_LITERAL(6, 59, 26), // "specialized_view_inviaVolt"
QT_MOC_LITERAL(7, 86, 26), // "specialized_view_inviaFreq"
QT_MOC_LITERAL(8, 113, 10), // "emergenza2"
QT_MOC_LITERAL(9, 124, 23), // "raccogli_testo_corrente"
QT_MOC_LITERAL(10, 148, 11), // "specops_raz"
QT_MOC_LITERAL(11, 160, 17), // "specops_complesso"
QT_MOC_LITERAL(12, 178, 7), // "helpRaz"
QT_MOC_LITERAL(13, 186, 13), // "helpComplesso"
QT_MOC_LITERAL(14, 200, 12), // "helpCircuito"
QT_MOC_LITERAL(15, 213, 9), // "helpTupla"
QT_MOC_LITERAL(16, 223, 13), // "mostra_result"
QT_MOC_LITERAL(17, 237, 16) // "handle_exception"

    },
    "specialized_view\0back\0\0inviaQS\0"
    "inviaSORaz\0inviaSOComplesso\0"
    "specialized_view_inviaVolt\0"
    "specialized_view_inviaFreq\0emergenza2\0"
    "raccogli_testo_corrente\0specops_raz\0"
    "specops_complesso\0helpRaz\0helpComplesso\0"
    "helpCircuito\0helpTupla\0mostra_result\0"
    "handle_exception"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_specialized_view[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    1,   95,    2, 0x06 /* Public */,
       4,    1,   98,    2, 0x06 /* Public */,
       5,    1,  101,    2, 0x06 /* Public */,
       6,    1,  104,    2, 0x06 /* Public */,
       7,    1,  107,    2, 0x06 /* Public */,
       8,    0,  110,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    1,  118,    2, 0x0a /* Public */,
      17,    2,  121,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    2,    2,

       0        // eod
};

void specialized_view::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        specialized_view *_t = static_cast<specialized_view *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->back(); break;
        case 1: _t->inviaQS((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->inviaSORaz((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->inviaSOComplesso((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->specialized_view_inviaVolt((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->specialized_view_inviaFreq((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->emergenza2(); break;
        case 7: _t->raccogli_testo_corrente(); break;
        case 8: _t->specops_raz(); break;
        case 9: _t->specops_complesso(); break;
        case 10: _t->helpRaz(); break;
        case 11: _t->helpComplesso(); break;
        case 12: _t->helpCircuito(); break;
        case 13: _t->helpTupla(); break;
        case 14: _t->mostra_result((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->handle_exception((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (specialized_view::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&specialized_view::back)) {
                *result = 0;
            }
        }
        {
            typedef void (specialized_view::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&specialized_view::inviaQS)) {
                *result = 1;
            }
        }
        {
            typedef void (specialized_view::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&specialized_view::inviaSORaz)) {
                *result = 2;
            }
        }
        {
            typedef void (specialized_view::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&specialized_view::inviaSOComplesso)) {
                *result = 3;
            }
        }
        {
            typedef void (specialized_view::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&specialized_view::specialized_view_inviaVolt)) {
                *result = 4;
            }
        }
        {
            typedef void (specialized_view::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&specialized_view::specialized_view_inviaFreq)) {
                *result = 5;
            }
        }
        {
            typedef void (specialized_view::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&specialized_view::emergenza2)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject specialized_view::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_specialized_view.data,
      qt_meta_data_specialized_view,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *specialized_view::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *specialized_view::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_specialized_view.stringdata0))
        return static_cast<void*>(const_cast< specialized_view*>(this));
    return QWidget::qt_metacast(_clname);
}

int specialized_view::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void specialized_view::back()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void specialized_view::inviaQS(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void specialized_view::inviaSORaz(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void specialized_view::inviaSOComplesso(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void specialized_view::specialized_view_inviaVolt(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void specialized_view::specialized_view_inviaFreq(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void specialized_view::emergenza2()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
