#include "response.h"

Response::Response()
{

}

Response::~Response()
{

}

void Response::setBody(const QByteArray &body)
{
    mBody = body;
}

const QByteArray &Response::body() const
{
    return mBody;
}

void Response::setElapsed(qint64 time)
{
 mElapsed = time;
}

qint64 Response::elapsed() const
{

    return mElapsed;
}

