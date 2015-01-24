#include "requestserializer.h"



Request RequestSerializer::fromJson(const QByteArray &json)
{

    Request req;
    QJsonDocument doc = QJsonDocument::fromJson(json);
    req.setUrl(doc.object().value("url").toString());
    req.setVerb(doc.object().value("verb").toString());

    return req;



}

QByteArray RequestSerializer::toJson(const Request &request)
{

    QJsonDocument doc;
    QJsonObject root;


    root.insert("url",request.url().toString());
    root.insert("verb", request.verb());

    doc.setObject(root);
    return doc.toJson();




}
