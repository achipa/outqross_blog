# As of 5.4 beta, shadow building of plugins on Android is not supported 
# https://bugreports.qt-project.org/browse/QTBUG-38690
# 
# Plugins are not runnable, but you do need to "make install" to get
# the qmldir into the right directory. If you're running windows,
# take a look at/run makeinstall.bat to replicate behavior

TEMPLATE = lib
TARGET = acomponent
QT += qml androidextras
QT -= gui
CONFIG += qt plugin

uri = OutQross.Android # was *after* TARGET?

TARGET = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)/$$TARGET # qtLibraryTarget is \libs\arch.... ?
#TARGET = $$qtLibraryTarget($$TARGET)

# Input
SOURCES += \
    acomponent_plugin.cpp \
    activity.cpp \
    relativelayout.cpp \
    button.cpp \
    view.cpp \
    outqrossitem.cpp

HEADERS += \
    acomponent_plugin.h \
    activity.h \
    relativelayout.h \
    button.h \
    view.h \
    outqrossitem.h

OTHER_FILES = qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}

