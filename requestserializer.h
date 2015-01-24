#ifndef REQUESTSERIALIZER_H
#define REQUESTSERIALIZER_H
#include <QJsonDocument>
#include "request.h"
class RequestSerializer
{
public:
    static QList<Request> fromJson(const QByteArray& json);

    static QByteArray toJson(const Request& request);
    static QByteArray toJson(const QList<Request>& list);


protected:
    static Request fromJsonObject(const QJsonObject& obj);
    static QJsonObject toJsonObject(const Request& request);


private:
    RequestSerializer(){}

};

#endif // REQUESTSERIALIZER_H
