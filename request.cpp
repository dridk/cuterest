#include "request.h"

Request::Request(const QUrl & url)
    :QNetworkRequest(url)
{

}

Request::~Request()
{

}

