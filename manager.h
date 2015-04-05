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
    void setAuth(const QAuthenticator& auth);


protected slots:
    void parse();
    void auth(QNetworkReply * reply, QAuthenticator * authenticator);
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
    QAuthenticator mAuthentificator;

};

#endif // MANAGER_H
