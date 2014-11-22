TEMPLATE = app

QT += core qml

CONFIG   += console
CONFIG   -= app_bundle

QT       -= gui
SOURCES += main.cpp

folder_02.source = imports
folder_02.target = imports

INSTALLS += folder_02
INSTALLS += imports

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH +=

# Default rules for deployment.
include(deployment.pri)

OTHER_FILES +=

contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
    ANDROID_EXTRA_LIBS =
}
