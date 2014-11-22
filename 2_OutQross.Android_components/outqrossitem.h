#ifndef OUTCROSSITEM_H
#define OUTCROSSITEM_H

#include <QObject>
#include <QQmlListProperty>

class OutQrossItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<QObject> children READ children)
    Q_CLASSINFO("DefaultProperty", "children")
public:
    explicit OutQrossItem(QObject *parent = 0);
    QQmlListProperty<QObject> children();

    static void append_child(QQmlListProperty<QObject> *list, QObject *child);
    static void clear_childPtr(QQmlListProperty<QObject> *property);
    static int child_Size(QQmlListProperty<QObject> *property);
    static QObject *child_At(QQmlListProperty<QObject> *property, int index);
protected:
    QList<QObject *> m_children;

signals:

public slots:

};

#endif // OUTCROSSITEM_H
