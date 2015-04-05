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

#include "favoritedockwidget.h"
#include <QHeaderView>
#include <QStandardPaths>
FavoriteDockWidget::FavoriteDockWidget(QWidget * parent)
    :QDockWidget(parent, Qt::Window | Qt::CustomizeWindowHint )
{

    mView = new FavoriteTreeView;

    setWidget(mView);

    mView->setObjectName("Favorite");

    setFeatures(QDockWidget::NoDockWidgetFeatures);



    setWindowTitle(tr("Favorite"));

    connect(mView,SIGNAL(doubleClicked(Request)),this,SIGNAL(doubleClicked(Request)));
    connect(mView,SIGNAL(clicked(Request)),this,SIGNAL(clicked(Request)));

}

FavoriteDockWidget::~FavoriteDockWidget()
{
    delete mView;

}

void FavoriteDockWidget::append(const Request &request)
{
    QStandardItem * item = mView->favoriteModel()->append(request);
    mView->expand(item->parent()->index());
    mView->edit(item->index());

}

void FavoriteDockWidget::importFavorite(const QString &path)
{
    mView->favoriteModel()->load(path);
}

void FavoriteDockWidget::exportFavorite(const QString &path)
{
    mView->favoriteModel()->save(path);
}


