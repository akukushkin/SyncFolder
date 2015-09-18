#-------------------------------------------------
#
# Project created by QtCreator 2015-09-17T23:23:01
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SyncFolder
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    choicerolewidget.cpp \
    serverwidget.cpp \
    inputdatawidget.cpp \
    syncserver.cpp

HEADERS  += mainwidget.h \
    choicerolewidget.h \
    serverwidget.h \
    inputdatawidget.h \
    syncserver.h

FORMS    += mainwidget.ui \
    choicerolewidget.ui \
    serverwidget.ui \
    inputdatawidget.ui
