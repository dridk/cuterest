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

    QNetworkReply * reply = 0;

    if (request.verb() == "GET")
        reply = getRequest(request);

    if (request.verb() == "POST")
        reply = postRequest(request);

    if (request.verb() == "PUT")
        reply = putRequest(request);

    if (request.verb() == "DELETE")
        reply = deleteRequest(request);

    if (!reply){
        qDebug()<<"unknown HTTP VERBS";
        return;
    }


    mRequests.insert(reply,request);
    connect(reply,SIGNAL(finished()),this,SLOT(parse()));


    emit sended(request);
    emit loadingChanged(true);


}

void Manager::parse()
{
    QNetworkReply * reply = qobject_cast<QNetworkReply*>(sender());

    if (reply) {

        Response rep = createResponse(reply);
        emit received(rep);

        if (reply->error() != QNetworkReply::NoError)
            emit error(reply->errorString());
    }



    emit loadingChanged(false);


}



QNetworkReply* Manager::getRequest(const Request &request)
{
    if (!request.url().hasQuery())
    {
        //If url has no query, generate it from requestDialog
        QUrl url = request.url();
        QUrlQuery query;
        foreach (QString key, request.params().keys())
            query.addQueryItem(key, request.param(key).toString());

        Request newRequest = request;
        url.setQuery(query);
        newRequest.setUrl(url);
        return get(newRequest);
    }
    else
        return get(request);

}

QNetworkReply* Manager::postRequest(const Request &request)
{
    QJsonDocument doc;
    QJsonObject obj;

    foreach (QString key, request.params().keys())
        obj.insert(key, QJsonValue::fromVariant(request.param(key)));

    doc.setObject(obj);

   return post(request,doc.toJson());




}

QNetworkReply* Manager::putRequest(const Request &request)
{
    QJsonDocument doc;
    QJsonObject obj;

    foreach (QString key, request.params().keys())
        obj.insert(key, QJsonValue::fromVariant(request.param(key)));

    doc.setObject(obj);

    return put(request,doc.toJson());

}

QNetworkReply* Manager::deleteRequest(const Request &request)
{
    return deleteResource(request);
}

Response Manager::createResponse(QNetworkReply *reply)
{

    Response rep;
    rep.setBody(reply->readAll());
    rep.setElapsed(mTimer.elapsed());
    rep.setStatusCode(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt());
    rep.setRawHeaderPairs(reply->rawHeaderPairs());

    if (mRequests.contains(reply)) {
        rep.setRequest(mRequests[reply]);
        mRequests.remove(reply);
    }

    reply->deleteLater();

    return rep;

}

