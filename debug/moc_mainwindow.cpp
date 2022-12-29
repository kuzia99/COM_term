/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
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
struct qt_meta_stringdata_MainWindow_t {};
static constexpr auto qt_meta_stringdata_MainWindow = QtMocHelpers::stringData(
    "MainWindow",
    "serialReceive",
    "",
    "on_pushButtonClear_clicked",
    "on_pushButtonConnect_clicked",
    "sendMessage",
    "updateGraph",
    "updateTimeTicks",
    "on_checkBox_clicked",
    "checked",
    "sendRequest",
    "on_pushButton_clicked",
    "on_pushButton_2_clicked",
    "changeColor",
    "sendNextRequest"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[30];
    char stringdata0[11];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[27];
    char stringdata4[29];
    char stringdata5[12];
    char stringdata6[12];
    char stringdata7[16];
    char stringdata8[20];
    char stringdata9[8];
    char stringdata10[12];
    char stringdata11[22];
    char stringdata12[24];
    char stringdata13[12];
    char stringdata14[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 13),  // "serialReceive"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 26),  // "on_pushButtonClear_clicked"
        QT_MOC_LITERAL(53, 28),  // "on_pushButtonConnect_clicked"
        QT_MOC_LITERAL(82, 11),  // "sendMessage"
        QT_MOC_LITERAL(94, 11),  // "updateGraph"
        QT_MOC_LITERAL(106, 15),  // "updateTimeTicks"
        QT_MOC_LITERAL(122, 19),  // "on_checkBox_clicked"
        QT_MOC_LITERAL(142, 7),  // "checked"
        QT_MOC_LITERAL(150, 11),  // "sendRequest"
        QT_MOC_LITERAL(162, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(184, 23),  // "on_pushButton_2_clicked"
        QT_MOC_LITERAL(208, 11),  // "changeColor"
        QT_MOC_LITERAL(220, 15)   // "sendNextRequest"
    },
    "MainWindow",
    "serialReceive",
    "",
    "on_pushButtonClear_clicked",
    "on_pushButtonConnect_clicked",
    "sendMessage",
    "updateGraph",
    "updateTimeTicks",
    "on_checkBox_clicked",
    "checked",
    "sendRequest",
    "on_pushButton_clicked",
    "on_pushButton_2_clicked",
    "changeColor",
    "sendNextRequest"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x08,    1 /* Private */,
       3,    0,   87,    2, 0x08,    2 /* Private */,
       4,    0,   88,    2, 0x08,    3 /* Private */,
       5,    0,   89,    2, 0x08,    4 /* Private */,
       6,    1,   90,    2, 0x08,    5 /* Private */,
       7,    0,   93,    2, 0x08,    7 /* Private */,
       8,    1,   94,    2, 0x08,    8 /* Private */,
      10,    1,   97,    2, 0x08,   10 /* Private */,
      11,    0,  100,    2, 0x08,   12 /* Private */,
      12,    0,  101,    2, 0x08,   13 /* Private */,
      13,    0,  102,    2, 0x08,   14 /* Private */,
      14,    0,  103,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'serialReceive'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonClear_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonConnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateGraph'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'updateTimeTicks'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_checkBox_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'sendRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendNextRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->serialReceive(); break;
        case 1: _t->on_pushButtonClear_clicked(); break;
        case 2: _t->on_pushButtonConnect_clicked(); break;
        case 3: _t->sendMessage(); break;
        case 4: _t->updateGraph((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->updateTimeTicks(); break;
        case 6: _t->on_checkBox_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->sendRequest((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->on_pushButton_clicked(); break;
        case 9: _t->on_pushButton_2_clicked(); break;
        case 10: _t->changeColor(); break;
        case 11: _t->sendNextRequest(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
