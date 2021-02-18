QT += core
QT -= gui

CONFIG += c++11

TARGET = qt-06-properties
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    bankaccount.cpp

HEADERS += \
    bankaccount.h
