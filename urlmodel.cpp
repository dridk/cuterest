#include "urlmodel.h"

UrlModel::UrlModel(QObject * parent):
    QAbstractListModel(parent)
{
    load();
}

UrlModel::~UrlModel()
{
    save();
}

int UrlModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return mUrls.count();

}

QVariant UrlModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();


    if (role == Qt::DisplayRole)
        return mUrls.at(index.row());


    return QVariant();

}

void UrlModel::save()
{
    QSettings settings;
    settings.beginWriteArray("urls");
    for (int i=0; i<mUrls.count(); ++i)
    {
        settings.setArrayIndex(i);
        settings.setValue("url", mUrls.at(i));
    }

    settings.endArray();

}

void UrlModel::load()
{
    QSettings settings;
    int size = settings.beginReadArray("urls");
    for (int i=0; i<size; ++i)
    {
        settings.setArrayIndex(i);
        append(settings.value("url").toUrl());
    }

    settings.endArray();

}

void UrlModel::append(const QUrl &url)
{
    if (mUrls.contains(url))
        return;

    beginInsertRows(QModelIndex(),0,0);
    mUrls.append(url);
    endInsertRows();


}

