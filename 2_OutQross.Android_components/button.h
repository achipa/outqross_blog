#ifndef BUTTON_H
#define BUTTON_H

#include <QtAndroidExtras/QAndroidJniObject>
#include <QObject>
#include <view.h>

class Button : public View
{
    Q_OBJECT
    Q_DISABLE_COPY(Button)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)

    QString m_text = "";

public:
    explicit Button(View *parent = 0);
    ~Button();
    void setText(const QString &t);
    QString text() const {
        return m_text;
    }
    void inflate();

signals:
    void textChanged();
public slots:

protected:
};

#endif // BUTTON_H
