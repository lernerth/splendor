/****************************************************************************
** Meta object code from reading C++ file 'gamewindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Splendor/gamewindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameWindow_t_t {
    const uint offsetsAndSize[38];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_GameWindow_t_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_GameWindow_t_t qt_meta_stringdata_GameWindow_t = {
    {
QT_MOC_LITERAL(0, 12), // "GameWindow_t"
QT_MOC_LITERAL(13, 14), // "afficherJetons"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 9), // "highlight"
QT_MOC_LITERAL(39, 14), // "afficherCartes"
QT_MOC_LITERAL(54, 14), // "afficherImages"
QT_MOC_LITERAL(69, 9), // "FindeTour"
QT_MOC_LITERAL(79, 5), // "print"
QT_MOC_LITERAL(85, 17), // "creerGroupeCartes"
QT_MOC_LITERAL(103, 13), // "QButtonGroup*"
QT_MOC_LITERAL(117, 5), // "group"
QT_MOC_LITERAL(123, 14), // "clicJetonBlanc"
QT_MOC_LITERAL(138, 7), // "Couleur"
QT_MOC_LITERAL(146, 13), // "clicJetonNoir"
QT_MOC_LITERAL(160, 13), // "clicJetonBleu"
QT_MOC_LITERAL(174, 14), // "clicJetonRouge"
QT_MOC_LITERAL(189, 13), // "clicJetonVert"
QT_MOC_LITERAL(203, 10), // "priseJeton"
QT_MOC_LITERAL(214, 8) // "numChoix"

    },
    "GameWindow_t\0afficherJetons\0\0highlight\0"
    "afficherCartes\0afficherImages\0FindeTour\0"
    "print\0creerGroupeCartes\0QButtonGroup*\0"
    "group\0clicJetonBlanc\0Couleur\0clicJetonNoir\0"
    "clicJetonBleu\0clicJetonRouge\0clicJetonVert\0"
    "priseJeton\0numChoix"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameWindow_t[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    1 /* Private */,
       3,    0,   99,    2, 0x08,    2 /* Private */,
       4,    0,  100,    2, 0x08,    3 /* Private */,
       5,    0,  101,    2, 0x08,    4 /* Private */,
       6,    0,  102,    2, 0x08,    5 /* Private */,
       7,    0,  103,    2, 0x08,    6 /* Private */,
       8,    1,  104,    2, 0x08,    7 /* Private */,
      11,    0,  107,    2, 0x08,    9 /* Private */,
      13,    0,  108,    2, 0x08,   10 /* Private */,
      14,    0,  109,    2, 0x08,   11 /* Private */,
      15,    0,  110,    2, 0x08,   12 /* Private */,
      16,    0,  111,    2, 0x08,   13 /* Private */,
      17,    0,  112,    2, 0x08,   14 /* Private */,
      18,    0,  113,    2, 0x0a,   15 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    0x80000000 | 12,
    0x80000000 | 12,
    0x80000000 | 12,
    0x80000000 | 12,
    0x80000000 | 12,
    0x80000000 | 12,
    QMetaType::Void,

       0        // eod
};

void GameWindow_t::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameWindow_t *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->afficherJetons(); break;
        case 1: _t->highlight(); break;
        case 2: _t->afficherCartes(); break;
        case 3: _t->afficherImages(); break;
        case 4: _t->FindeTour(); break;
        case 5: _t->print(); break;
        case 6: _t->creerGroupeCartes((*reinterpret_cast< QButtonGroup*(*)>(_a[1]))); break;
        case 7: { Couleur _r = _t->clicJetonBlanc();
            if (_a[0]) *reinterpret_cast< Couleur*>(_a[0]) = std::move(_r); }  break;
        case 8: { Couleur _r = _t->clicJetonNoir();
            if (_a[0]) *reinterpret_cast< Couleur*>(_a[0]) = std::move(_r); }  break;
        case 9: { Couleur _r = _t->clicJetonBleu();
            if (_a[0]) *reinterpret_cast< Couleur*>(_a[0]) = std::move(_r); }  break;
        case 10: { Couleur _r = _t->clicJetonRouge();
            if (_a[0]) *reinterpret_cast< Couleur*>(_a[0]) = std::move(_r); }  break;
        case 11: { Couleur _r = _t->clicJetonVert();
            if (_a[0]) *reinterpret_cast< Couleur*>(_a[0]) = std::move(_r); }  break;
        case 12: { Couleur _r = _t->priseJeton();
            if (_a[0]) *reinterpret_cast< Couleur*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->numChoix(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QButtonGroup* >(); break;
            }
            break;
        }
    }
}

const QMetaObject GameWindow_t::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_GameWindow_t.offsetsAndSize,
    qt_meta_data_GameWindow_t,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_GameWindow_t_t
, QtPrivate::TypeAndForceComplete<GameWindow_t, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QButtonGroup *, std::false_type>, QtPrivate::TypeAndForceComplete<Couleur, std::false_type>, QtPrivate::TypeAndForceComplete<Couleur, std::false_type>, QtPrivate::TypeAndForceComplete<Couleur, std::false_type>, QtPrivate::TypeAndForceComplete<Couleur, std::false_type>, QtPrivate::TypeAndForceComplete<Couleur, std::false_type>, QtPrivate::TypeAndForceComplete<Couleur, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *GameWindow_t::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameWindow_t::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameWindow_t.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int GameWindow_t::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
