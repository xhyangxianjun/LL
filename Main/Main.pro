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

message($$LIB_PATH)

LIBS += -L$$LIB_PATH -lCore

SOURCES += main.cpp\
        mainwindow.cpp \
    mainapplication.cpp

HEADERS  += mainwindow.h \
    mainapplication.h

FORMS    += mainwindow.ui
