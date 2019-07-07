#-------------------------------------------------
#
# Project created by QtCreator 2019-07-07T22:01:04
#
#-------------------------------------------------

QT       -= gui

TARGET = MwhrController
TEMPLATE = lib

include(../../common.pri)

DEFINES += MWHRCONTROLLER_LIBRARY

SOURCES += mwhrcontroller.cpp \
    mwhrinterface.cpp

HEADERS += mwhrcontroller.h\
        mwhrcontroller_global.h \
    mwhrinterface.h

message($$THIRPARTY_LIB_PATH)
LIBS += -L$$THIRPARTY_LIB_PATH -lmwrf32

INCLUDEPATH += $$THIRPARTY_INCLUDE_PATH

unix {
    target.path = /usr/lib
    INSTALLS += target
}
