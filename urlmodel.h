#ifndef URLMODEL_H
#define URLMODEL_H
#include <QStringListModel>
#include <QSettings>
#include <QtCore>

class UrlModel : public QAbstractListModel
{
    Q_OBJECT
public:
    UrlModel(QObject * parent=0);
    ~UrlModel();
    int rowCount(const QModelIndex &parent =QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;

    void save();
    void load();

public slots:
    void append(const QUrl& url);


private:
    QList<QUrl> mUrls;
};

#endif // URLMODEL_H
