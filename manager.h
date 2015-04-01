#ifndef MANAGER_H
#define MANAGER_H
#include <QtNetwork>
#include <QElapsedTimer>
#include <QSettings>
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
    void abortRequest();
    void loadProxySettings();


protected slots:
    void parse();
    QNetworkReply* getRequest(const Request& request);
    QNetworkReply* postRequest(const Request& request);
    QNetworkReply* putRequest(const Request& request);
    QNetworkReply* deleteRequest(const Request& request);
    QNetworkReply *headRequest(const Request& request);
    QNetworkReply *customRequest(const Request& request);



signals:
    void sended(const Request& request);
    void received(const Response& response);
    void error(const QString& message);
    void loadingChanged(bool loading);


protected:
    Response createResponse(QNetworkReply * reply) ;


private:
    QElapsedTimer mTimer;
    QHash<QNetworkReply*, Request> mRequests;

};

#endif // MANAGER_H
