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

#ifndef FAVORITETREEVIEW_H
#define FAVORITETREEVIEW_H

#include <QTreeView>
#include <QtWidgets>
#include "favoritemodel.h"
class FavoriteTreeView : public QTreeView
{
    Q_OBJECT
public:
    FavoriteTreeView(QWidget * parent = 0);
    ~FavoriteTreeView();

    FavoriteModel *favoriteModel();

protected slots:
    void renameFavorite();
    void editFavorite();
    void deleteFavorite();
    void doubleClickedReceived(const QModelIndex& index);
    void clickedReceived(const QModelIndex& index);


protected :
    virtual void contextMenuEvent(QContextMenuEvent * event);

signals:
    void doubleClicked(const Request& request);
    void clicked(const Request& request);


private:
    FavoriteModel * mModel;
    QAction * mRenameAction;
    QAction * mDeleteAction;
    QAction * mCollapseAction;



};

#endif // FAVORITETREEVIEW_H
