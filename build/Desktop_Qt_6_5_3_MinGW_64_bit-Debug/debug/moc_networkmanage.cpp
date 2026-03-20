/****************************************************************************
** Meta object code from reading C++ file 'networkmanage.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../networkmanage.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'networkmanage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSNetWorkManageENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSNetWorkManageENDCLASS = QtMocHelpers::stringData(
    "NetWorkManage",
    "sendMessageToMainWindow",
    "",
    "message",
    "sendGetOneMessageToMainWindow",
    "onConnected",
    "onDisconnected",
    "recvAccount",
    "account",
    "sendAccountToServer",
    "getMessageFromMainWindow",
    "target_user",
    "getMessage"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSNetWorkManageENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[14];
    char stringdata1[24];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[30];
    char stringdata5[12];
    char stringdata6[15];
    char stringdata7[12];
    char stringdata8[8];
    char stringdata9[20];
    char stringdata10[25];
    char stringdata11[12];
    char stringdata12[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSNetWorkManageENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSNetWorkManageENDCLASS_t qt_meta_stringdata_CLASSNetWorkManageENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "NetWorkManage"
        QT_MOC_LITERAL(14, 23),  // "sendMessageToMainWindow"
        QT_MOC_LITERAL(38, 0),  // ""
        QT_MOC_LITERAL(39, 7),  // "message"
        QT_MOC_LITERAL(47, 29),  // "sendGetOneMessageToMainWindow"
        QT_MOC_LITERAL(77, 11),  // "onConnected"
        QT_MOC_LITERAL(89, 14),  // "onDisconnected"
        QT_MOC_LITERAL(104, 11),  // "recvAccount"
        QT_MOC_LITERAL(116, 7),  // "account"
        QT_MOC_LITERAL(124, 19),  // "sendAccountToServer"
        QT_MOC_LITERAL(144, 24),  // "getMessageFromMainWindow"
        QT_MOC_LITERAL(169, 11),  // "target_user"
        QT_MOC_LITERAL(181, 10)   // "getMessage"
    },
    "NetWorkManage",
    "sendMessageToMainWindow",
    "",
    "message",
    "sendGetOneMessageToMainWindow",
    "onConnected",
    "onDisconnected",
    "recvAccount",
    "account",
    "sendAccountToServer",
    "getMessageFromMainWindow",
    "target_user",
    "getMessage"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSNetWorkManageENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       4,    1,   65,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   68,    2, 0x0a,    5 /* Public */,
       6,    0,   69,    2, 0x0a,    6 /* Public */,
       7,    1,   70,    2, 0x0a,    7 /* Public */,
       9,    0,   73,    2, 0x0a,    9 /* Public */,
      10,    2,   74,    2, 0x0a,   10 /* Public */,
      12,    0,   79,    2, 0x0a,   13 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,    3,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject NetWorkManage::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSNetWorkManageENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSNetWorkManageENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSNetWorkManageENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<NetWorkManage, std::true_type>,
        // method 'sendMessageToMainWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sendGetOneMessageToMainWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'onConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'recvAccount'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sendAccountToServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getMessageFromMainWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void NetWorkManage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NetWorkManage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendMessageToMainWindow((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->sendGetOneMessageToMainWindow((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->onConnected(); break;
        case 3: _t->onDisconnected(); break;
        case 4: _t->recvAccount((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->sendAccountToServer(); break;
        case 6: _t->getMessageFromMainWindow((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 7: _t->getMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NetWorkManage::*)(QString );
            if (_t _q_method = &NetWorkManage::sendMessageToMainWindow; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NetWorkManage::*)(QString );
            if (_t _q_method = &NetWorkManage::sendGetOneMessageToMainWindow; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *NetWorkManage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetWorkManage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSNetWorkManageENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NetWorkManage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void NetWorkManage::sendMessageToMainWindow(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetWorkManage::sendGetOneMessageToMainWindow(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
