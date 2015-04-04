#ifndef HISTORYMODEL_H
#define HISTORYMODEL_H
#include <QAbstractTableModel>
#include "response.h"

class HistoryModel : public QAbstractTableModel
{
    Q_OBJECT
public:



    HistoryModel(QObject * parent = 0);
    ~HistoryModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent= QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Response response(const QModelIndex& index);




public slots:
    void append(const Response& reponse);
    void clear();



private:
    QList<Response> mData;
};

#endif // HISTORYMODEL_H
