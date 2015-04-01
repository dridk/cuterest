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

    a.setApplicationName("CuteRest");
    a.setApplicationVersion("alpha 0.1");
    a.setOrganizationDomain("labsquare.org");
    a.setOrganizationName("labsquare");


    int i = QFontDatabase::addApplicationFont(":/fonts/Menlo-Regular.ttf");
    i = QFontDatabase::addApplicationFont(":/fonts/American-Captain.ttf");

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
