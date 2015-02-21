#ifndef DICTEDITORMODEL_H
#define DICTEDITORMODEL_H
#include <QAbstractTableModel>
#include <QtCore>
class DictEditorModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    DictEditorModel(QObject * parent =0);
    ~DictEditorModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role) const;
    const QString &key(int row);
    const QVariant &value(int row);
    void setHeaders(const QStringList& list);

public slots:
    void clear();
    void insert(const QString& key, const QVariant& value);
    void remove(int row);


private:
    QList< QPair<QString, QVariant> > mData;
    QStringList mHeaders;


};

#endif // DICTEDITORMODEL_H
