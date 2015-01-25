#ifndef MANAGER_H
#define MANAGER_H
#include <QtNetwork>
#include <QElapsedTimer>
#include "request.h"
#include "response.h"
class Manager : public QNetworkAccessManager
{
    Q_OBJECT
public:
    Manager(QObject * parent = 0);
    ~Manager();

public slots:
    void sendRequest(const Request& request);


protected slots:
    void parse();
    QNetworkReply* getRequest(const Request& request);
    QNetworkReply* postRequest(const Request& request);
    QNetworkReply* putRequest(const Request& request);
    QNetworkReply* deleteRequest(const Request& request);


signals:
    void received(const Response& response);
    void error(const QString& message);


protected:
    Response createResponse(QNetworkReply * reply) ;


private:
    QElapsedTimer mTimer;
    QHash<QNetworkReply*, Request> mRequests;


};

#endif // MANAGER_H
