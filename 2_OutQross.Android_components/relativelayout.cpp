#include "relativelayout.h"
#include <QDebug>

RelativeLayout::RelativeLayout(View *parent) :
    View(parent)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
}

RelativeLayout::~RelativeLayout()
{
}

void RelativeLayout::inflate()
{
    View::inflate();
    qDebug() << "Start rellayout inflate";
    if (m_context != NULL && m_context->isValid()) {
        m_object = new QAndroidJniObject("android/widget/RelativeLayout", "(Landroid/content/Context;)V", m_context->object());
        qDebug() << m_object->isValid();
        qDebug() << m_object->toString();
        foreach (QObject *child, m_children) {
            qDebug() << "add children to layout";
            if (child != NULL) {
                qDebug() << child->metaObject()->className();
                child->dumpObjectInfo();
                if (child->inherits("View"))
                    m_object->callMethod<void>("addView", "(Landroid/view/View;)V", qobject_cast<View*>(child)->object()->object());
            }
        }
    } else
        qDebug() << "No context, cannot inflate!";
}

