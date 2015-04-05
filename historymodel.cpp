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

#include "historymodel.h"
#include <QFont>
HistoryModel::HistoryModel(QObject * parent )
    :QAbstractTableModel(parent)
{





}

HistoryModel::~HistoryModel()
{

}

int HistoryModel::rowCount(const QModelIndex &parent) const
{

    return mData.count();

}

int HistoryModel::columnCount(const QModelIndex &parent) const
{
    return 6;
}

QVariant HistoryModel::data(const QModelIndex &index, int role) const
{

    if (!index.isValid())
        return QVariant();


    if (role == Qt::DisplayRole){

        Response rep = mData.at(index.row());

        if (index.column() == 0)
            return rep.request().verb();

        if (index.column() == 1)
            return rep.request().url();

        if (index.column() == 2)
            return rep.statusCode();

        if (index.column() == 3)
            return rep.time().toString(Qt::DefaultLocaleShortDate);
        if (index.column() == 4)
            return QString("%1 b").arg(rep.size());

        if (index.column() == 5)
            return QString("%1 ms").arg(rep.elapsed());


    }

    if (role == Qt::FontRole) {
        if (index.column() == 0)
        {
            QFont font;
            font.setBold(true);
            return font;
        }
    }


    return QVariant();



}

QVariant HistoryModel::headerData(int section, Qt::Orientation orientation, int role) const
{

    return QVariant();
}

Response HistoryModel::response(const QModelIndex &index)
{
    return mData.at(index.row());
}

void HistoryModel::append(const Response &reponse)
{


    beginInsertRows(QModelIndex(),0,0);
    mData.prepend(Response(reponse));
    endInsertRows();


}

void HistoryModel::clear()
{
    beginResetModel();
    mData.clear();
    endResetModel();
}

