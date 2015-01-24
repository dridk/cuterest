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


signals:
    void received(const Response& response);

protected:
    Response createResponse(QNetworkReply * reply) const;


private:
    QElapsedTimer mTimer;

};

#endif // MANAGER_H
