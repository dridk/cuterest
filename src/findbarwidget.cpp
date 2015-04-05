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

#include "findbarwidget.h"
#include <QtAwesome/QtAwesome.h>
FindBarWidget::FindBarWidget(TreeSortFilterProxyModel * model,QWidget *parent)
    : QFrame(parent)
{
    mEdit = new QLineEdit;
    mColBox = new QComboBox();
    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget(mEdit);
    layout->addWidget(mColBox);
    setLayout(layout);

    mModel = model;

    for (int i=0; i< mModel->columnCount(); ++i)
        mColBox->addItem(mModel->headerData(i,Qt::Horizontal).toString());



    connect(mEdit,SIGNAL(textChanged(QString)),this,SIGNAL(textChanged(QString)));
    connect(mEdit,SIGNAL(textChanged(QString)),mModel,SLOT(setFilterFixedString(QString)));
    connect(mColBox,SIGNAL(currentIndexChanged(int)),this,SLOT(setFilterColumn(int)));


}

FindBarWidget::~FindBarWidget()
{

}



void FindBarWidget::edit()
{
    mEdit->setFocus();
    mEdit->selectAll();

}

void FindBarWidget::setFilterColumn(int row)
{
    mModel->setFilterKeyColumn(row);
}

