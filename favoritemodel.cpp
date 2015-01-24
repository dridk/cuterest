#include "favoritemodel.h"
#include <QFile>
#include <QDebug>
#include <QStandardPaths>

FavoriteModel::FavoriteModel(QObject * parent)
    :QStandardItemModel(parent)
{

    QDir dir;
    // make path to save
    dir.mkpath(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
    load(path());



}

FavoriteModel::~FavoriteModel()
{
    save(path());
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
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)){
        foreach (Request r, RequestSerializer::fromJson(file.readAll()))
            append(r);

        file.close();
        return true;
    }

    return false;


}

QString FavoriteModel::path()
{
    return QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + QDir::separator() + "favorite.json";
}

void FavoriteModel::append(const Request &request)
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
    item->setText(request.url().path());
    item->setEditable(false);
    mData.insert(item, request);
    root->appendRow(item);





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

