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

#include "request.h"

Request::Request(const QUrl & url)
    :QNetworkRequest(url)
{

    setRawHeader("Content-Type","application/json;charset=UTF-8");
    mName ="No name";
}

Request::Request(const Request &other)
    :QNetworkRequest(other)
{

    setVerb(other.verb());
    setParams(other.params());
    setName(other.name());

}

Request::Request(const QNetworkRequest &other)
    :QNetworkRequest(other)
{

}

Request::~Request()
{

}


const QString &Request::verb() const
{
    return  mVerb;
}

void Request::setVerb(const QString &verb)
{
    mVerb = verb;

}

const QHash<QString, QVariant> &Request::params() const
{
    return mParams;

}

QVariant Request::param(const QString &key) const
{
    return mParams.value(key);
}

void Request::insertParam(const QString &key, const QVariant &value)
{
    mParams.insert(key,value);
}

void Request::setParams(const QHash<QString, QVariant> &params)
{
    mParams = params;
}

void Request::clearRawHeaders()
{

    foreach (QByteArray key, rawHeaderList())
    {
        setRawHeader(key,QByteArray());
    }


}

void Request::clearParams()
{
    mParams.clear();
}
QString Request::name() const
{
    return mName;
}

void Request::setName(const QString &name)
{
    mName = name;
}

QByteArray Request::paramToJson() const
{
    QJsonDocument doc;
    QJsonObject obj;

    foreach (QString key, params().keys())
        obj.insert(key, QJsonValue::fromVariant(param(key)));

    doc.setObject(obj);

    return doc.toJson();
}




