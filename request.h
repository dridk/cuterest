#ifndef REQUEST_H
#define REQUEST_H
#include <QtNetwork>

class Request : public QNetworkRequest
{
public:

    Request(const QUrl & url = QUrl());
    ~Request();

    const QString &verb() const;
    void setVerb(const QString& verb);



private:
    QString mVerb;
};

#endif // REQUEST_H
