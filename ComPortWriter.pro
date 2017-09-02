QT += core
QT -= gui
QT += serialport

CONFIG += c++11

TARGET = ComPortWriter
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    serialportwriter.cpp \
    message.cpp

HEADERS += \
    serialportwriter.h \
    message.h

DISTFILES += \
    config/write.ini
