#ifndef REQUEST_H
#define REQUEST_H
#include <QtNetwork>

class Request : public QNetworkRequest
{
public:
    Request(const QUrl & url = QUrl());
    ~Request();
};

#endif // REQUEST_H
