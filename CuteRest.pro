#-------------------------------------------------
#
# Project created by QtCreator 2015-01-23T23:16:16
#
#-------------------------------------------------

QT       += core gui network webkit

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
    response.cpp \
    historymodel.cpp \
    requestserializer.cpp \
    favoritemodel.cpp \
    favoriteitem.cpp \
    requestdialog.cpp \
    paramrequestwidget.cpp \
    headerrequestwidget.cpp \
    abstractrequestwidget.cpp \
    dicteditorwidget.cpp \
    verbcombobox.cpp \
    dicteditormodel.cpp \
    inforesponsewidget.cpp

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
    response.h \
    historymodel.h \
    requestserializer.h \
    favoritemodel.h \
    favoriteitem.h \
    requestdialog.h \
    paramrequestwidget.h \
    headerrequestwidget.h \
    abstractrequestwidget.h \
    dicteditorwidget.h \
    verbcombobox.h \
    dicteditormodel.h \
    inforesponsewidget.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc \
    icons/icons.qrc


   include(QtAwesome/QtAwesome.pri)

