#include "manager.h"
#include <QDebug>
Manager::Manager(QObject * parent)
    :QNetworkAccessManager(parent)
{

}

Manager::~Manager()
{

}

void Manager::sendRequest(const Request &request)
{
qDebug()<<"send request"<<request.url();


mTimer.start();
QNetworkReply * reply = get(request);
connect(reply,SIGNAL(finished()),this,SLOT(parse()));




}

void Manager::parse()
{

    QNetworkReply * reply = qobject_cast<QNetworkReply*>(sender());

    if (reply) {


        Response rep;
        rep.setBody(reply->readAll());
        rep.setElapsed(mTimer.elapsed());


        emit received(rep);




    }





}

