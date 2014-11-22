#include "button.h"
#include <QDebug>

Button::Button(View *parent) :
    View(parent)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
}

Button::~Button()
{
    delete m_object;
}

void Button::setText(const QString &t) {
    if (t != m_text) {
        qDebug() << "setText" << t;
        m_text = t;
        if (m_object != NULL && m_object->isValid()) {
            qDebug() << "real setText" << t;
            QAndroidJniObject buttontext = QAndroidJniObject::fromString(m_text);
            m_object->callMethod<void>("setText", "(Ljava/lang/CharSequence;)V", buttontext.object<jstring>());
        }
        emit textChanged();
        qDebug() << "setText DONE";
    }
}

void Button::inflate()
{
    qDebug() << "Start buttoninflate";
    if (m_context != NULL && m_context->isValid()) {
        m_object = new QAndroidJniObject("android/widget/Button", "(Landroid/content/Context;)V", m_context->object());
        if (!m_text.isEmpty()) {
            qDebug() << "setText from inflate";
            QString tmptext = m_text;
            m_text.clear();
            setText(tmptext);
        }

        qDebug() << m_object->isValid();
        qDebug() << m_object->toString();
    } else
        qDebug() << "No context, cannot inflate!";
    View::inflate();
}

//        m_object->callMethod<void>("setTextColor", "(I)V", -1);
