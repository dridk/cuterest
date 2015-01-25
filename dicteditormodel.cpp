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
    return mData.count();
}

int DictEditorModel::columnCount(const QModelIndex &parent) const
{
    return 2;
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

