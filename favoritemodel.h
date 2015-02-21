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
    void append(const Request& request);
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
