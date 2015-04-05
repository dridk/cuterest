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

#include "favoritemodel.h"
#include <QFile>
#include <QDebug>
#include <QStandardPaths>
#include "QtAwesome/QtAwesome.h"

FavoriteModel::FavoriteModel(QObject * parent)
    :QStandardItemModel(parent)
{

    // init decoration
    mDecorations.insert("GET", qMakePair(QString("#0098ff"),0xf18e));
    mDecorations.insert("POST", qMakePair(QString("#17CA65"),0xf190));
    mDecorations.insert("DELETE", qMakePair(QString("#FFAA2C"),0xf014));
    mDecorations.insert("PUT", qMakePair(QString("#CC0000"),0xf190));

    QDir dir;
    // make path to save
    dir.mkpath(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));


    connect(this,SIGNAL(itemChanged(QStandardItem*)),this,SLOT(itemChanged(QStandardItem*)));

}

FavoriteModel::~FavoriteModel()
{

}

Request FavoriteModel::request(const QModelIndex &index) const
{

    return mData.value(itemFromIndex(index));

}


bool FavoriteModel::remove(const QModelIndex &index)
{
    if (!index.isValid())
        return false;

    if (!index.parent().isValid())
        return false;

    QStandardItem * item = itemFromIndex(index);

    if (mData.contains(item)){
        mData.remove(item);
        item->parent()->removeRow(item->row());

        if (!item->parent()->rowCount())
            removeRow(item->parent()->row());
        return true;
    }
    return false;


}



bool FavoriteModel::save(const QString& fileName)
{
    mFilename = fileName;
    qDebug()<<"save "<<fileName;
    QByteArray array =  RequestSerializer::toJson(mData.values());


    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)){
        file.write(array);
        file.close();
        return true;
    }

    qDebug()<<"cannot open file";
    return false;

}

bool FavoriteModel::load(const QString& fileName)
{
    mFilename = fileName;
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)){
        foreach (Request r, RequestSerializer::fromJson(file.readAll()))
            append(r);

        sort(0);
        file.close();
        return true;
    }

    return false;


}


void FavoriteModel::itemChanged(QStandardItem *item)
{
    // when rename occurs !
    qDebug()<<"rename item..";
    mData[item].setName(item->text());
    save(mFilename);


}

QIcon FavoriteModel::iconFromVerb(const QString &verb)
{
    if (!mDecorations.keys().contains(verb))
        return QIcon();


    QVariantMap params;
    params.insert("color", QColor(mDecorations[verb].first));


    return QtAwesome::instance()->icon(mDecorations[verb].second, params);
}

QStandardItem * FavoriteModel::append(const Request &request)
{
    QString key = request.url().host();

    //find root elements
    QList<QStandardItem*> items = findItems(key);
    QStandardItem * root;
    if (items.isEmpty()){
        root = new QStandardItem;
        root->setEditable(false);
        root->setSelectable(false);
        root->setText(key);
        appendRow(root);
    }
    else
        root = items.first();

    // apppend request

    QStandardItem * item = new QStandardItem;
    item->setText(request.name());
    item->setEditable(true);
    mData.insert(item, request);
    item->setIcon(iconFromVerb(request.verb()));
    root->appendRow(item);

    return item;





}



//int FavoriteModel::rowCount(const QModelIndex &parent) const
//{

//    if (!parent.isValid())
//        return mData.count();




//    QString key = parent.data().toString();
//      qDebug()<<"child row count"<<mData.value(key).count();;
//    return mData.value(key).count();


//}

//int FavoriteModel::columnCount(const QModelIndex &parent) const
//{

//    return 1;

//}

//QVariant FavoriteModel::data(const QModelIndex &index, int role) const
//{

//    if (!index.isValid())
//        return QVariant();

//    if (role != Qt::DisplayRole)
//        return QVariant();




//    if (!index.parent().isValid()){

//        qDebug()<<"pas de parent";
//        return mData.keys().at(index.row());


//    }
//    else {

//        QString key = index.parent().data().toString();
//        return mData.value(key).at(index.row()).url().path();
//    }

//    return QVariant();





//}

//QModelIndex FavoriteModel::index(int row, int column, const QModelIndex &parent) const
//{

//    if (!hasIndex(row,column,parent))
//        return QModelIndex();


//    return createIndex(row,column,1);






//}

//QModelIndex FavoriteModel::parent(const QModelIndex &child) const
//{

//    if (!child.isValid())
//        return QModelIndex();



//return createIndex(2,0);


//    return QModelIndex();



//}




// Request FavoriteModel::request(const QModelIndex &index)
//{
//    if (index.parent().isValid()){

//        FavoriteItem * item =  itemFromIndex(index.parent());

//        qDebug()<<item->request().url();

//        return Request();
//    }



//return Request();



//}

//void FavoriteModel::load(const QString &filename)
//{


//    QFile file(filename);

//    if (file.open(QIODevice::ReadOnly)) {

//        clear();
//        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());


//        //Load Json file into a hash dict . goal => order by hostname
//        QHash<QString, QList<Request> > data;

//        foreach (Request r,  RequestSerializer::fromJson(doc.toJson()))
//            data[r.url().host()].append(r);


//        //Create StandardItem
//        foreach (QString key, data.keys()) {
//            QStandardItem * item = new QStandardItem;
//            item->setEditable(false);
//            item->setSelectable(false);
//            item->setText(key);
//            foreach (Request r, data[key]) {

//                FavoriteItem * child = new FavoriteItem();
//                child->setText(r.url().path());
//                child->setEditable(false);
//                child->setRequest(r);
//                item->appendRow(child);
//            }
//            appendRow(item);

//        }



//        file.close();


//    }




//}

//void FavoriteModel::append(const Request &request)
//{

//    qDebug()<<"append to favorite";

//    QString key = request.url().host();

//    if (findItems(key).count()) {




//    }






//}

