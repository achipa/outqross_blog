#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QtAndroidExtras/QAndroidJniObject>
#include <QtAndroidExtras/QtAndroid>
#include <view.h>

class Activity : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Activity)

public:
    Activity(QObject *parent = 0);
    ~Activity();
private:
    QAndroidJniObject m_activity = QtAndroid::androidActivity();
public slots:
    Q_INVOKABLE void setViewContent(View *view);
};

#endif // ACTIVITY_H

