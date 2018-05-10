#-------------------------------------------------
#
# Project created by QtCreator 2018-05-10T12:29:20
#
#-------------------------------------------------

QT       += core gui network
CONFIG += c++1z
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TeQtClient
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    connectiondialog.cpp

HEADERS  += widget.hpp \
    connectiondialog.hpp

FORMS    += widget.ui \
    connectiondialog.ui
