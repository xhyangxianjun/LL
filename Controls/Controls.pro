#-------------------------------------------------
#
# Project created by QtCreator 2019-07-08T18:37:30
#
#-------------------------------------------------

QT       -= gui

TARGET = Controls
TEMPLATE = lib

DEFINES += CONTROLS_LIBRARY

SOURCES += titlebar.cpp

HEADERS += titlebar.h\
        controls_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
