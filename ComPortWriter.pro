QT += core
QT -= gui
QT += serialport

CONFIG += c++11

TARGET = ComPortWriter
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    serialportwriter.cpp

HEADERS += \
    serialportwriter.h

DISTFILES += \
    config/write.ini
