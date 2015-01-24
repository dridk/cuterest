#-------------------------------------------------
#
# Project created by QtCreator 2015-01-23T23:16:16
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CuteRest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    statusbar.cpp \
    responsetabwidget.cpp \
    abstractresponsewidget.cpp \
    request.cpp \
    manager.cpp \
    textresponsewidget.cpp \
    jsonresponsewidget.cpp \
    historydockwidget.cpp \
    favoritedockwidget.cpp \
    searchbar.cpp \
    qjsonmodel.cpp \
    qjsonitem.cpp \
    jsonsyntaxhighlighter.cpp \
    response.cpp

HEADERS  += mainwindow.h \
    statusbar.h \
    responsetabwidget.h \
    abstractresponsewidget.h \
    request.h \
    manager.h \
    textresponsewidget.h \
    jsonresponsewidget.h \
    historydockwidget.h \
    favoritedockwidget.h \
    searchbar.h \
    qjsonmodel.h \
    qjsonitem.h \
    jsonsyntaxhighlighter.h \
    response.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc \
    icons/icons.qrc
