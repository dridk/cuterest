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

#include "favoritetreeview.h"
#include <QMenu>
#include <QDebug>
#include <QStandardPaths>
FavoriteTreeView::FavoriteTreeView(QWidget * parent)
    :QTreeView(parent)
{

    mModel = new FavoriteModel();
    setModel(mModel);

    setEditTriggers(QAbstractItemView::EditKeyPressed);
    setSortingEnabled(true);
    header()->hide();
    mRenameAction = new QAction(tr("Rename"),this);
    mDeleteAction= new QAction(tr("Delete"),this);
    mCollapseAction = new QAction(tr("Collapse all"), this);
    connect(mRenameAction,SIGNAL(triggered()),this,SLOT(renameFavorite()));
    connect(mDeleteAction,SIGNAL(triggered()),this,SLOT(deleteFavorite()));
    connect(mCollapseAction,SIGNAL(triggered()),this,SLOT(collapseAll()));
    connect(this,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickedReceived(QModelIndex)));
    connect(this,SIGNAL(clicked(QModelIndex)),this,SLOT(clickedReceived(QModelIndex)));


    mModel->load(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + QDir::separator() + "favorite.json");

}

FavoriteTreeView::~FavoriteTreeView()
{
    mModel->save(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + QDir::separator() + "favorite.json");
    delete mModel;
}

FavoriteModel *FavoriteTreeView::favoriteModel()
{
    return mModel;
}

void FavoriteTreeView::renameFavorite()
{
    QModelIndex index = currentIndex();
    if (index.parent().isValid()) {

        edit(index);
    }
}

void FavoriteTreeView::editFavorite()
{

}

void FavoriteTreeView::deleteFavorite()
{
    QModelIndex index = currentIndex();
    if (index.parent().isValid()) {
        mModel->remove(index);
    }

}

void FavoriteTreeView::doubleClickedReceived(const QModelIndex &index)
{
    //Avoid root parent selection... thos who have no parent
    if (index.parent().isValid())
    {
        emit doubleClicked(mModel->request(index));
    }
}

void FavoriteTreeView::clickedReceived(const QModelIndex &index)
{
    //Avoid root parent selection... thos who have no parent
    if (index.parent().isValid())
    {
        emit clicked(mModel->request(index));
    }
}

void FavoriteTreeView::contextMenuEvent(QContextMenuEvent *event)
{


    if (indexAt(event->pos()).parent().isValid())
    {
        QMenu menu(this);
        menu.addAction(mRenameAction);
        menu.addAction(mDeleteAction);
        menu.exec(event->globalPos());
    }

    else  {
        QMenu menu(this);
        menu.addAction(mCollapseAction);
        menu.exec(event->globalPos());
    }




}

