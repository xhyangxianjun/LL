#-------------------------------------------------
#
# Project created by QtCreator 2019-07-09T09:09:52
#
#-------------------------------------------------

QT += core gui widgets network

TARGET = Core
TEMPLATE = lib

include (../../common.pri)

DEFINES += CORE_LIBRARY

SOURCES += hostinfo.cpp \
    application.cpp \
    dirhelper.cpp \
    usermanager.cpp \
    event.cpp \
    object.cpp \
    resourcemgr.cpp

HEADERS += hostinfo.h\
        core_global.h \
     application.h \
    Any.hpp \
    Ioc.hpp \
    NonCopyable.hpp \
    dirhelper.h \
    usermanager.h \
    event.h \
    object.h \
    resourcemgr.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
