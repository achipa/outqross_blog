#include <QCoreApplication>
#include <QtAndroidExtras/QAndroidJniObject>
#include <QtAndroidExtras/QtAndroid>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QAndroidJniObject activity = QtAndroid::androidActivity();
    QAndroidJniObject layout("android/widget/RelativeLayout", "(Landroid/content/Context;)V", activity.object());

    QAndroidJniObject button("android/widget/Button", "(Landroid/content/Context;)V", activity.object());
    button.callMethod<void>("setTextColor", "(I)V", -1); // Color.WHITE
    QAndroidJniObject buttontext = QAndroidJniObject::fromString("Hello World!");
    button.callMethod<void>("setText", "(Ljava/lang/CharSequence;)V", buttontext.object<jstring>());

    QAndroidJniObject buttonParams("android/widget/RelativeLayout$LayoutParams", "(II)V", (jint)-2, (jint)-2);
    buttonParams.callMethod<void>("addRule", "(I)V", (jint)15); // RelativeLayout.CENTER_VERTICAL
    buttonParams.callMethod<void>("addRule", "(I)V", (jint)14); // RelativeLayout.CENTER_HORIZONTAL

    layout.callMethod<void>("addView", "(Landroid/view/View;Landroid/view/ViewGroup$LayoutParams;)V", button.object(), buttonParams.object());
    activity.callMethod<void>("setContentView", "(Landroid/view/View;)V", layout.object());

    return app.exec();
}
