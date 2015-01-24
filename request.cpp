#include "request.h"

Request::Request(const QUrl & url)
    :QNetworkRequest(url)
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

