/****************************************************************************
** Meta object code from reading C++ file 'ControlPanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ControlPanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ControlPanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ControlPanel_t {
    QByteArrayData data[18];
    char stringdata[248];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ControlPanel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ControlPanel_t qt_meta_stringdata_ControlPanel = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 12),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 15),
QT_MOC_LITERAL(4, 43, 13),
QT_MOC_LITERAL(5, 57, 8),
QT_MOC_LITERAL(6, 66, 15),
QT_MOC_LITERAL(7, 82, 14),
QT_MOC_LITERAL(8, 97, 16),
QT_MOC_LITERAL(9, 114, 14),
QT_MOC_LITERAL(10, 129, 9),
QT_MOC_LITERAL(11, 139, 16),
QT_MOC_LITERAL(12, 156, 15),
QT_MOC_LITERAL(13, 172, 14),
QT_MOC_LITERAL(14, 187, 18),
QT_MOC_LITERAL(15, 206, 13),
QT_MOC_LITERAL(16, 220, 10),
QT_MOC_LITERAL(17, 231, 15)
    },
    "ControlPanel\0expandPanels\0\0resetBrightness\0"
    "resetContrast\0resetHue\0resetSaturation\0"
    "resetLightness\0changeBrightness\0"
    "changeContrast\0changeHue\0changeSaturation\0"
    "changeLightness\0revertOriginal\0"
    "resetInputControls\0resetControls\0"
    "setTileMap\0QMap<QRgb,Tile>\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ControlPanel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a,
       3,    0,   90,    2, 0x0a,
       4,    0,   91,    2, 0x0a,
       5,    0,   92,    2, 0x0a,
       6,    0,   93,    2, 0x0a,
       7,    0,   94,    2, 0x0a,
       8,    1,   95,    2, 0x0a,
       9,    1,   98,    2, 0x0a,
      10,    1,  101,    2, 0x0a,
      11,    1,  104,    2, 0x0a,
      12,    1,  107,    2, 0x0a,
      13,    0,  110,    2, 0x0a,
      14,    0,  111,    2, 0x0a,
      15,    0,  112,    2, 0x0a,
      16,    1,  113,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,    2,

       0        // eod
};

void ControlPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ControlPanel *_t = static_cast<ControlPanel *>(_o);
        switch (_id) {
        case 0: _t->expandPanels(); break;
        case 1: _t->resetBrightness(); break;
        case 2: _t->resetContrast(); break;
        case 3: _t->resetHue(); break;
        case 4: _t->resetSaturation(); break;
        case 5: _t->resetLightness(); break;
        case 6: _t->changeBrightness((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->changeContrast((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->changeHue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->changeSaturation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->changeLightness((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->revertOriginal(); break;
        case 12: _t->resetInputControls(); break;
        case 13: _t->resetControls(); break;
        case 14: _t->setTileMap((*reinterpret_cast< QMap<QRgb,Tile>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ControlPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ControlPanel.data,
      qt_meta_data_ControlPanel,  qt_static_metacall, 0, 0}
};


const QMetaObject *ControlPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControlPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ControlPanel.stringdata))
        return static_cast<void*>(const_cast< ControlPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int ControlPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
