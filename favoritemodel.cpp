#include "favoritemodel.h"
#include <QFile>
#include <QDebug>
FavoriteModel::FavoriteModel(QObject * parent)
    :QStandardItemModel(parent)
{
        setColumnCount(1);

}

FavoriteModel::~FavoriteModel()
{

}

 Request FavoriteModel::request(const QModelIndex &index)
{
    if (index.parent().isValid()){

        QString key = itemFromIndex(index.parent())->text();
        return mData.value(key).value(index.row()).url();
    }

return Request();



}

void FavoriteModel::load(const QString &filename)
{


    QFile file(filename);

    if (file.open(QIODevice::ReadOnly)) {

        clear();
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());


        //Load Json file into a hash dict . goal => order by hostname
        foreach (Request r,  RequestSerializer::fromJson(doc.toJson()))
            mData[r.url().host()].append(r);


        //Create StandardItem
        foreach (QString key, mData.keys()) {
            QStandardItem * item = new QStandardItem;
            item->setEditable(false);
            item->setSelectable(false);
            foreach (Request r, mData[key]) {

                QStandardItem * child = new QStandardItem();
                child->setText(r.url().path());
                child->setEditable(false);

                item->appendRow(child);




            }


            item->setText(key);

            appendRow(item);

        }








        file.close();


    }




}

