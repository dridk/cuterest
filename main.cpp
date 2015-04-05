/*
* Copyright (c) 2015 CuteRest
* CuteRest, a json REST viewer [https://github.com/dridk/cuterest]
* This file is part of CuteRest Project.
* CuteRest is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
