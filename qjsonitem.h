#ifndef JSONITEM_H
#define JSONITEM_H
#include <QtCore>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
class QJsonTreeItem
{
public:
    QJsonTreeItem(QJsonTreeItem * parent = 0);
    ~QJsonTreeItem();
    void appendChild(QJsonTreeItem * item);
    QJsonTreeItem *child(int row);
    QJsonTreeItem *parent();
    int childCount() const;
    int row() const;
    void setKey(const QString& key);
    void setValue(const QVariant& value);
    void setType(const QJsonValue::Type& type);
    QString key() const;
    QVariant value() const;
    QJsonValue::Type type() const;
    void clear();


    static QJsonTreeItem* load(const QJsonValue& value, QJsonTreeItem * parent = 0);

protected:


private:
    QString mKey;
    QVariant mValue;
    QJsonValue::Type mType;

    QList<QJsonTreeItem*> mChilds;
    QJsonTreeItem * mParent;


};

#endif // JSONITEM_H
