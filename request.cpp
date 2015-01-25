#include "request.h"

Request::Request(const QUrl & url)
    :QNetworkRequest(url)
{

    setRawHeader("User-Agent", "CuteRest");

}

Request::Request(const Request &other)
    :QNetworkRequest(other)
{

setVerb(other.verb());


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


const QUrlQuery &Request::query() const
{
    return mQuery;
}

void Request::setQuery(const QUrlQuery &query)
{
    mQuery = query;
}


