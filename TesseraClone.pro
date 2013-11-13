#-------------------------------------------------
#
# Project created by QtCreator 2013-09-25T02:40:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TesseraClone
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        ControlPanel.cpp \
    ImageWindow.cpp \
    TesseraParameters.cpp \
        HSL.cpp

HEADERS  += mainwindow.h \
    ControlPanel.h \
    ImageWindow.h \
    TesseraParameters.h \
    Globals.h \
    HSL.h

RESOURCES += \
    icons.qrc
