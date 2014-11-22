#include "outqrossitem.h"
#include <QDebug>

OutQrossItem::OutQrossItem(QObject *parent) :
    QObject(parent)
{
}

QQmlListProperty<QObject> OutQrossItem::children()
{
    return QQmlListProperty<QObject>(this, 0, &OutQrossItem::append_child, &OutQrossItem::child_Size, &OutQrossItem::child_At, &OutQrossItem::clear_childPtr);
//    return QQmlListProperty<QObject>(this, &m_children, &OutQrossItem::append_child, &OutQrossItem::child_Size, &OutQrossItem::child_At, &OutQrossItem::clear_childPtr);
}

void OutQrossItem::append_child(QQmlListProperty<QObject> *list, QObject *child)
{
    qDebug() << "append";
    OutQrossItem *ocitem = qobject_cast<OutQrossItem *>(list->object);
    if (child)
        ocitem->m_children.append(child);
}

QObject *OutQrossItem::child_At(QQmlListProperty<QObject> *property, int index)
{
    qDebug() << "at";
    return static_cast< QList<QObject *> *>(property->data)->at(index);
}

int OutQrossItem::child_Size(QQmlListProperty<QObject> *property)
{
    qDebug() << "size";
    return static_cast< QList<QObject *> *>(property->data)->size();
}

void OutQrossItem::clear_childPtr(QQmlListProperty<QObject> *property)
{
    qDebug() << "clear";
    return static_cast< QList<QObject *> *>(property->data)->clear();
}
