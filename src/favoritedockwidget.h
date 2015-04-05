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

#ifndef FAVORITEDOCKWIDGET_H
#define FAVORITEDOCKWIDGET_H
#include <QDockWidget>
#include <QTreeView>
#include "favoritemodel.h"
#include "favoritetreeview.h"
class FavoriteDockWidget : public QDockWidget
{
    Q_OBJECT
public:
    FavoriteDockWidget(QWidget * parent= 0);
    ~FavoriteDockWidget();


public slots:
    void append(const Request& request);
    void importFavorite(const QString& path);
    void exportFavorite(const QString& path);

signals:
    void doubleClicked(const Request& request);
    void clicked(const Request& request);


private:
    FavoriteTreeView * mView;

};

#endif // FAVORITEDOCKWIDGET_H
