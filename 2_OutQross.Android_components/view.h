#ifndef VIEW_H
#define VIEW_H

#include <QtAndroidExtras/QAndroidJniObject>
#include <outqrossitem.h>

class View : public OutQrossItem
{
    Q_OBJECT
    Q_DISABLE_COPY(View)
public:
    explicit View(OutQrossItem *parent = 0);
    void setContext(QAndroidJniObject *c);
    const QAndroidJniObject *context() { return m_context; }
    const QAndroidJniObject *object() { return m_object; }
    virtual void inflate();
protected:
    QAndroidJniObject *m_context = NULL;
    QAndroidJniObject *m_object = NULL;
signals:

public slots:

};

#endif // VIEW_H
