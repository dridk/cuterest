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

#ifndef FAVORITEMODEL_H
#define FAVORITEMODEL_H
#include <QAbstractItemModel>
#include <QStandardItemModel>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QtCore>
#include "requestserializer.h"
#include "favoriteitem.h"


class FavoriteModel : public QStandardItemModel
{
    Q_OBJECT
public:
    FavoriteModel( QObject * parent = 0);
    ~FavoriteModel();

   Request request(const QModelIndex& index) const;

public slots:
    QStandardItem * append(const Request& request);
    bool remove(const QModelIndex& index);
    bool save(const QString& fileName = QString());
    bool load(const QString& fileName = QString());

protected slots:
    void itemChanged(QStandardItem *item);


protected:
    QIcon iconFromVerb(const QString& verb);


private:
    QHash<QStandardItem*, Request> mData;
    // colors and font code icon
    QHash<QString, QPair<QString, int> >mDecorations;
    QString mFilename;


};

#endif // FAVORITEMODEL_H
