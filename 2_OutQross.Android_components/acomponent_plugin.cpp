#include "acomponent_plugin.h"
#include "activity.h"
#include "outqrossitem.h"
#include "button.h"
#include "relativelayout.h"

#include <qqml.h>

void AcomponentPlugin::registerTypes(const char *uri)
{
    // @uri OutQross.Android
    qmlRegisterType<OutQrossItem>(uri, 0, 1, "OutQrossItem");
    qmlRegisterType<Activity>(uri, 0, 1, "Activity");
    qmlRegisterType<RelativeLayout>(uri, 0, 1, "RelativeLayout");
    qmlRegisterType<Button>(uri, 0, 1, "Button");
}


