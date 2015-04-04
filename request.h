#ifndef REQUEST_H
#define REQUEST_H
#include <QtNetwork>
#include <QUrlQuery>
class Request : public QNetworkRequest
{
public:

    Request(const QUrl & url = QUrl());
    Request(const Request& other);
    Request(const QNetworkRequest& other);
    ~Request();

    const QString &verb() const;
    void setVerb(const QString& verb);

    const QHash<QString, QVariant> &params() const;
    QVariant param(const QString& key) const;
    void insertParam(const QString& key, const QVariant& value);
    void setParams(const  QHash<QString,QVariant>& params);
    void clearRawHeaders();
    void clearParams();
    QString name() const;
    void setName(const QString &name);

    QByteArray paramToJson() const;

private:
    QString mVerb;
    QHash<QString,QVariant> mParams;
    QString mName;

};

#endif // REQUEST_H
