#-------------------------------------------------
#
# Project created by QtCreator 2019-07-09T09:40:22
#
#-------------------------------------------------

QT       += widgets

TARGET = Others
TEMPLATE = lib

DEFINES += OTHERS_LIBRARY

SOURCES += fronzentableview.cpp

HEADERS += fronzentableview.h\
        others_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
