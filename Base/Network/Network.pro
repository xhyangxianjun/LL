#-------------------------------------------------
#
# Project created by QtCreator 2019-07-09T15:55:27
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = Network
TEMPLATE = lib

include(../../common.pri)

DEFINES += NETWORK_LIBRARY

SOURCES += httpclient.cpp \
    httprequest.cpp

HEADERS += httpclient.h\
        network_global.h \
    httpdefs.h \
    httprequest.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
