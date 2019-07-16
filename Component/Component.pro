#-------------------------------------------------
#
# Project created by QtCreator 2019-07-16T15:57:04
#
#-------------------------------------------------

QT       += widgets network

TARGET = Component
TEMPLATE = lib

include(../common.pri)

DEFINES += COMPONENT_LIBRARY

SOURCES += component.cpp

HEADERS += component.h\
        component_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
