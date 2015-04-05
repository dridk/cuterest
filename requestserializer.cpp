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

#include "requestserializer.h"




QList<Request> RequestSerializer::fromJson(const QByteArray &json)
{
    QList<Request> list;

    QJsonDocument doc = QJsonDocument::fromJson(json);
    if (doc.isObject()){
        QJsonArray  array = doc.object().value("requests").toArray();
        foreach (QJsonValue v, array) {

            if (v.isObject())
                list.append(fromJsonObject(v.toObject()));
        }
    }


    return list;
}

QByteArray RequestSerializer::toJson(const Request &request)
{
    QJsonDocument doc;
    doc.setObject(toJsonObject(request));
    return doc.toJson();
}

QByteArray RequestSerializer::toJson(const QList<Request> &list)
{
    QJsonArray array;
    QJsonDocument doc;
    foreach (Request r, list){

        array.append(toJsonObject(r));

    }

    QJsonObject root;
    root.insert("requests", array);
    doc.setObject(root);

    return doc.toJson();

}

Request RequestSerializer::fromJsonObject(const QJsonObject &obj)
{

    Request request;
    request.setVerb(obj.value("verb").toString());
    request.setUrl(obj.value("url").toString());
    request.setName(obj.value("name").toString());

    // Unserialize parameters
    if (obj.contains("params")){
        QJsonObject param = obj.value("params").toObject();

        foreach (QString key , param.keys()){
            request.insertParam(key, param.value(key).toVariant());
        }
    }

    // Unserialize headers
    if (obj.contains("headers")){
        QJsonObject param = obj.value("headers").toObject();

        foreach (QString key , param.keys()){
            request.setRawHeader(key.toUtf8(), param.value(key).toVariant().toByteArray());
        }
    }



    return request;

}

QJsonObject RequestSerializer::toJsonObject(const Request &request)
{


    QJsonObject obj;

    obj.insert("url",request.url().toString());
    obj.insert("verb", request.verb());
    obj.insert("name",request.name());

    // Serialize parameters...
    QJsonObject param;

    foreach (QString key, request.params().keys()){
        param.insert(key, QJsonValue::fromVariant(request.param(key)));
    }

    obj.insert("params", param);

    //Serialize headers
    QJsonObject header;

    foreach (QByteArray key, request.rawHeaderList()){
        header.insert(key, QJsonValue::fromVariant(request.rawHeader(key)));
    }

    obj.insert("headers", header);



    return obj;



}
