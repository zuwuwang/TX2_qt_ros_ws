/****************************************************************************
** Meta object code from reading C++ file 'socketsend_node.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/guitest/include/guitest/socketsend_node.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'socketsend_node.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_guitest__SocketSendNode[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   41,   41,   41, 0x05,
      42,   41,   41,   41, 0x05,
      56,   41,   41,   41, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_guitest__SocketSendNode[] = {
    "guitest::SocketSendNode\0loggingUpdated()\0"
    "\0rosShutdown()\0mcnnResault()\0"
};

void guitest::SocketSendNode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SocketSendNode *_t = static_cast<SocketSendNode *>(_o);
        switch (_id) {
        case 0: _t->loggingUpdated(); break;
        case 1: _t->rosShutdown(); break;
        case 2: _t->mcnnResault(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData guitest::SocketSendNode::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject guitest::SocketSendNode::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_guitest__SocketSendNode,
      qt_meta_data_guitest__SocketSendNode, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &guitest::SocketSendNode::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *guitest::SocketSendNode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *guitest::SocketSendNode::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_guitest__SocketSendNode))
        return static_cast<void*>(const_cast< SocketSendNode*>(this));
    return QThread::qt_metacast(_clname);
}

int guitest::SocketSendNode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void guitest::SocketSendNode::loggingUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void guitest::SocketSendNode::rosShutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void guitest::SocketSendNode::mcnnResault()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
