#include "activity.h"
#include <QDebug>

Activity::Activity(QObject *parent):
    QObject(parent)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
}

Activity::~Activity()
{
}

void Activity::setViewContent(View *view)
{
   qDebug() << "setVC with" << view;
//   QAndroidJniObject *viewcontext = qobject_cast<View>(view)->context();
   if (view) {
       view->setContext(&m_activity);
       qDebug() << "context set" << m_activity.toString();
       view->inflate();
       qDebug() << "view inflated";
       qDebug() << "view is" << view->object()->isValid();
       qDebug() << "view is" << view->object()->toString();
       qDebug() << "view is" << view->object();
//       QAndroidJniObject layout("android/widget/RelativeLayout", "(Landroid/content/Context;)V", m_activity.object());
//       m_activity.callMethod<void>("setContentView", "(Landroid/view/View;)V", layout.object());
       m_activity.callMethod<void>("setContentView", "(Landroid/view/View;)V", view->object()->object());
   }
   qDebug() << "setVC done";
}

