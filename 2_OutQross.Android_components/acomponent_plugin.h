#ifndef ACOMPONENT_PLUGIN_H
#define ACOMPONENT_PLUGIN_H

#include <QQmlExtensionPlugin>

class AcomponentPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // ACOMPONENT_PLUGIN_H

