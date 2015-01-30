#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QFontDatabase>
#include <QDebug>
#include "QtAwesome/QtAwesome.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);



    int i = QFontDatabase::addApplicationFont(":/fonts/Menlo-Regular.ttf");

    qDebug()<<QFontDatabase::applicationFontFamilies(i);




    MainWindow w;
    w.show();

    return a.exec();
}
