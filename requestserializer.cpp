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

    return request;

}

QJsonObject RequestSerializer::toJsonObject(const Request &request)
{


    QJsonObject obj;

    obj.insert("url",request.url().toString());
    obj.insert("verb", request.verb());

    return obj;



}
