#-------------------------------------------------
#
# Project created by QtCreator 2015-01-23T23:16:16
#
#-------------------------------------------------

QT       += core gui network webkitwidgets xml

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
    historydockwidget.cpp \
    favoritedockwidget.cpp \
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
    inforesponsewidget.cpp \
    treesortfilterproxymodel.cpp \
    webresponsewidget.cpp \
    settingsdialog.cpp \
    abstractsettingswidget.cpp \
    proxysettingswidget.cpp \
    findbarwidget.cpp \
    domitem.cpp \
    dommodel.cpp \
    treeresponsewidget.cpp \
    xmlresponsewidget.cpp \
    controlbar.cpp \
    consoledockwidget.cpp \
    favoritetreeview.cpp

HEADERS  += mainwindow.h \
    statusbar.h \
    responsetabwidget.h \
    abstractresponsewidget.h \
    request.h \
    manager.h \
    textresponsewidget.h \
    historydockwidget.h \
    favoritedockwidget.h \
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
    inforesponsewidget.h \
    treesortfilterproxymodel.h \
    webresponsewidget.h \
    settingsdialog.h \
    abstractsettingswidget.h \
    proxysettingswidget.h \
    findbarwidget.h \
    domitem.h \
    dommodel.h \
    treeresponsewidget.h \
    xmlresponsewidget.h \
    controlbar.h \
    consoledockwidget.h \
    favoritetreeview.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc \
    icons/icons.qrc


   include(QtAwesome/QtAwesome.pri)

