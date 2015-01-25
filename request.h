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

    const QUrlQuery& query() const;
    void setQuery(const QUrlQuery &query);

private:
    QString mVerb;
    QUrlQuery mQuery;
};

#endif // REQUEST_H
