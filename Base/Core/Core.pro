#-------------------------------------------------
#
# Project created by QtCreator 2019-07-09T09:09:52
#
#-------------------------------------------------

QT       -= gui

TARGET = Core
TEMPLATE = lib

DEFINES += CORE_LIBRARY

SOURCES += hostinfo.cpp

HEADERS += hostinfo.h\
        core_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
