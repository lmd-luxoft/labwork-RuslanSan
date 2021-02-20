#-------------------------------------------------
#
# Project created by QtCreator 2016-06-21T12:03:36
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-09-os-features
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    textstreamreader.cpp \
    datastreamwriter.cpp

HEADERS  += mainwidget.h \
    textstreamreader.h \
    datastreamwriter.h

FORMS    += mainwidget.ui

DISTFILES += \
    data.txt
