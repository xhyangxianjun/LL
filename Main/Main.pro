#-------------------------------------------------
#
# Project created by QtCreator 2019-07-07T22:22:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Main
TEMPLATE = app

include(../common.pri)

include(maincomponent/maincomponent.pri)

LIBS += -L$$LIB_PATH -lCore -lNetwork  -lControls


INCLUDEPATH += $$BASE_SRC_PATH

SOURCES += main.cpp\
        mainwindow.cpp \
    mainapplication.cpp \
    test.cpp

HEADERS  += mainwindow.h \
    mainapplication.h \
    test.h

FORMS    += mainwindow.ui
