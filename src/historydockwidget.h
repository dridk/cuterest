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

#ifndef HISTORYDOCKWIDGET_H
#define HISTORYDOCKWIDGET_H
#include <QDockWidget>
#include <QtWidgets>
#include "historymodel.h"
#include "response.h"
class HistoryDockWidget : public QDockWidget
{
    Q_OBJECT
public:
    HistoryDockWidget(QWidget * parent = 0);
    ~HistoryDockWidget();
    HistoryModel *model() ;

public slots:
    void append(const Response& rep);
    void setBack();
    void setForward();
    void clear();


signals:
    void doubleClicked(const Request& request);


protected slots:
    void doubleClickedReceived(const QModelIndex& index);




private:
    HistoryModel * mModel;
    QTableView *mView;
};

#endif // HISTORYDOCKWIDGET_H
