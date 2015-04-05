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

#ifndef CONSOLEDOCKWIDGET_H
#define CONSOLEDOCKWIDGET_H

#include <QWidget>
#include <QDockWidget>
#include <QPlainTextEdit>
#include "response.h"
class ConsoleDockWidget : public QDockWidget
{
    Q_OBJECT
public:
    ConsoleDockWidget(QWidget * parent = 0);
    ~ConsoleDockWidget();
public slots:
    void append(const Response& rep);
    void append(const Request& rep);


    void out(const QString& message, bool rich = false);

private:
    QPlainTextEdit * mTextEdit;
};

#endif // CONSOLEDOCKWIDGET_H
