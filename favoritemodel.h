#ifndef FAVORITEMODEL_H
#define FAVORITEMODEL_H
#include <QStandardItemModel>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QtCore>
#include "requestserializer.h"
class FavoriteModel : public QStandardItemModel
{
    Q_OBJECT
public:
    FavoriteModel(QObject * parent = 0);
    ~FavoriteModel();

     Request request(const QModelIndex& index);

public slots:
    void load(const QString& filename);



private:
    QHash<QString, QList<Request> > mData;


};

#endif // FAVORITEMODEL_H
