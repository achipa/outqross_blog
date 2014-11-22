#include "view.h"
#include <QQmlComponent>
#include <QDebug>

View::View(OutQrossItem *parent) :
    OutQrossItem(parent)
{
}

void View::setContext(QAndroidJniObject *c) {
    m_context = c;

    // set context for all our children
    foreach (QObject *child, m_children) {
        qDebug() << "setcontext qobj children";
        if (child != NULL) {
            qDebug() << child->metaObject()->className();
            child->dumpObjectInfo();
            if (child->inherits("View"))
                qobject_cast<View*>(child)->setContext(c);
        }
    }
}

void View::inflate() {
    foreach (QObject *child, m_children) {
        qDebug() << "inflate qobj children";
        if (child != NULL) {
            qDebug() << child->metaObject()->className();
            child->dumpObjectInfo();
            if (child->inherits("View"))
                qobject_cast<View*>(child)->inflate();
        }
    }
}
