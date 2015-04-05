/*
* Copyright (c) 2015 CuteRest
* CuteRest, a json REST viewer [https://github.com/dridk/cuterest]
* This file is part of CuteRest Project.
* CuteRest is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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

    if (request.verb() == "HEAD")
        reply = headRequest(request);

    if (!reply){



        return;
    }


    mRequests.insert(reply,request);
    connect(reply,SIGNAL(finished()),this,SLOT(parse()));


    emit sended(request);
    emit loadingChanged(true);


}

void Manager::abortRequest()
{
    qDebug()<<"ABORT";
    foreach ( QNetworkReply * reply, mRequests.keys())
    {
        reply->abort();
    }
}

void Manager::loadProxySettings()
{
    QSettings settings;
    settings.beginGroup("proxy");

    QNetworkProxy proxy;
    proxy.setType(QNetworkProxy::ProxyType(settings.value("type").toInt()));
    proxy.setHostName(settings.value("host").toString());
    proxy.setPort(settings.value("port").toInt());
    proxy.setUser(settings.value("user").toString());
    proxy.setPassword(settings.value("password").toString());

    setProxy(proxy);

    settings.endGroup();
}

void Manager::setAuth(const QAuthenticator &auth)
{
    mAuthentificator = auth;
}

void Manager::parse()
{

    QNetworkReply * reply = qobject_cast<QNetworkReply*>(sender());

    if (reply) {

        Response rep = createResponse(reply);
        emit received(rep);

        if (reply->error() != QNetworkReply::NoError){
         emit error(reply->errorString());

        }
    }



    emit loadingChanged(false);


}

void Manager::auth(QNetworkReply *reply, QAuthenticator *authenticator)
{
    Q_UNUSED(reply);
    if (!mAuthentificator.user().isEmpty())
    {
        authenticator->setUser(mAuthentificator.user());
        authenticator->setPassword(mAuthentificator.password());
        authenticator->setRealm(mAuthentificator.realm());
    }
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
   return post(request,request.paramToJson());
}

QNetworkReply* Manager::putRequest(const Request &request)
{

    return put(request,request.paramToJson());

}

QNetworkReply* Manager::deleteRequest(const Request &request)
{
    return deleteResource(request);
}

QNetworkReply *Manager::headRequest(const Request &request)
{
    return headRequest(request);
}
QNetworkReply* Manager::customRequest(const Request &request)
{
   return sendCustomRequest(request, request.verb().toUtf8());
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

