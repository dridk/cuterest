#ifndef REQUESTSERIALIZER_H
#define REQUESTSERIALIZER_H
#include <QJsonDocument>
#include "request.h"
class RequestSerializer
{
public:
    static Request fromJson(const QByteArray& json);
    static QByteArray toJson(const Request& request);

 private:
    RequestSerializer(){}

};

#endif // REQUESTSERIALIZER_H
