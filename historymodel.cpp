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
    mData.append(Response(reponse));
    endInsertRows();


}

