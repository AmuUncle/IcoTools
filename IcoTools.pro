#-------------------------------------------------
#
# Project created by QtCreator 2021-09-07T19:15:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = icoTools
TEMPLATE = app
DESTDIR = bin
unix:UI_DIR = ../tmp/ui
win32:UI_DIR = tmp/ui

INCLUDEPATH += include

include ($$PWD/public/public.pri)

SOURCES += source/main.cpp\
        source/mainwnd.cpp \
    source/leftnavbarpane.cpp \
    source/headertitlepane.cpp \
    source/mainpane.cpp \
    source/canvas.cpp \
    source/about.cpp

HEADERS  += include/mainwnd.h \
    include/leftnavbarpane.h \
    include/headertitlepane.h \
    include/global.h \
    include/mainpane.h \
    include/canvas.h \
    include/about.h

RESOURCES += \
    res/res.qrc

RC_FILE +=  \
    res/icon.rc
