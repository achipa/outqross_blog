#ifndef RELATIVELAYOUT_H
#define RELATIVELAYOUT_H

#include <QObject>
#include <view.h>

class RelativeLayout : public View
{
    Q_OBJECT
    Q_DISABLE_COPY(RelativeLayout)

public:
    explicit RelativeLayout(View *parent = 0);
    ~RelativeLayout();
    void inflate();

signals:

public slots:

};

#endif // RELATIVELAYOUT_H
