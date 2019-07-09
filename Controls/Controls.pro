#-------------------------------------------------
#
# Project created by QtCreator 2019-07-08T18:37:30
#
#-------------------------------------------------

QT       +=  core gui widgets

TARGET = Controls
TEMPLATE = lib

include(../common.pri)

DEFINES += CONTROLS_LIBRARY

SOURCES += titlebar.cpp \
    wincontrolbox.cpp \
    line.cpp \
    framelesswidget.cpp \
    basewidget.cpp \
    framelesshelper.cpp \
    navigatorbar.cpp \
    sidebar.cpp \
    subtab.cpp

HEADERS += titlebar.h\
        controls_global.h \
    wincontrolbox.h \
    line.h \
    framelesswidget.h \
    basewidget.h \
    framelesshelper.h \
    navigatorbar.h \
    sidebar.h \
    subtab.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
