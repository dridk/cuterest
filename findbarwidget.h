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

#ifndef FINDBARWIDGET_H
#define FINDBARWIDGET_H

#include <QtWidgets>
#include "treesortfilterproxymodel.h"

class FindBarWidget : public QFrame
{
    Q_OBJECT
public:
    explicit FindBarWidget(TreeSortFilterProxyModel * model, QWidget *parent = 0);
    ~FindBarWidget();
public slots:
    void edit();
    void setFilterColumn(int row);


signals:
    void textChanged(const QString& txt);

private:
    QLineEdit * mEdit;
    QComboBox * mColBox;
    TreeSortFilterProxyModel * mModel;

};

#endif // FINDBARWIDGET_H
