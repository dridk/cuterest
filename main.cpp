#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QFontDatabase>
#include <QDebug>
#include "QtAwesome/QtAwesome.h"
#include <QStyleFactory>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    int i = QFontDatabase::addApplicationFont(":/fonts/Menlo-Regular.ttf");

    qDebug()<<QFontDatabase::applicationFontFamilies(i);

    QFile styleFile(":style.qss");
    styleFile.open( QFile::ReadOnly );
    QString style( styleFile.readAll() );
    qApp->setStyleSheet(style);
    styleFile.close();


    MainWindow w;
    w.show();

    return a.exec();
}
