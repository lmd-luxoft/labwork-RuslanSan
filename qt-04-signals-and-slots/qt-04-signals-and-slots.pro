QT += core
QT -= gui

CONFIG += c++11

TARGET = qt-04-signals-and-slots
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    bankaccount.cpp \
    bank.cpp \
    logger.cpp

HEADERS += \
    bankaccount.h \
    bank.h \
    logger.h
