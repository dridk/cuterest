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

#include "dicteditormodel.h"
#include <QDebug>

DictEditorModel::DictEditorModel(QObject * parent)
    :QAbstractTableModel(parent)
{

}

DictEditorModel::~DictEditorModel()
{

}

int DictEditorModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mData.count();
}

int DictEditorModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 2;
}

QVariant DictEditorModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if ( (section < 0)  || (section > columnCount()))
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal){
           return "test";
        }
    }
    return QVariant();
}

QVariant DictEditorModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();


    if (index.column() == 0)
        return mData.at(index.row()).first;

    if (index.column() == 1)
        return mData.at(index.row()).second;


    return QVariant();


}

const QString &DictEditorModel::key(int row)
{
    return mData.at(row).first;
}

const QVariant &DictEditorModel::value(int row)
{
    return mData.at(row).second;
}

void DictEditorModel::setHeaders(const QStringList &list)
{
    mHeaders = list;
    emit headerDataChanged(Qt::Horizontal,0,2);
}



void DictEditorModel::clear()
{
    beginResetModel();
    mData.clear();
    endResetModel();


}

void DictEditorModel::insert(const QString &key, const QVariant &value)
{

    beginInsertRows(QModelIndex(),mData.count(),mData.count());
    mData.append(qMakePair(key,value));
    endInsertRows();

}

void DictEditorModel::remove(int row)
{

    beginRemoveRows(QModelIndex(),row,row);
    mData.removeAt(row);
    endRemoveRows();



}

