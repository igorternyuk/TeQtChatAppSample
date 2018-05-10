QT += core network
QT -= gui

CONFIG += c++1z

TARGET = TeQtServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    teserver.cpp \
    tesocket.cpp

HEADERS += \
    teserver.hpp \
    tesocket.hpp
