#include "response.h"

Response::Response()
{
    mTime = QDateTime::currentDateTime();
}

Response::~Response()
{

}

void Response::setBody(const QByteArray &body)
{
    mBody = body;
    mSize = body.size();
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

void Response::setRequest(const Request &request)
{
    mRequest = request;
}

const Request &Response::request() const
{
    return mRequest;
}

void Response::setStatusCode(int code)
{
    mStatusCode = code;
}

int Response::statusCode() const
{
    return mStatusCode;
}

const QDateTime &Response::time() const
{
    return mTime;
}

int Response::size() const
{
    return mSize;
}

const QList<QNetworkReply::RawHeaderPair> &Response::rawHeaderPairs() const
{
    return mRawHeaderPairs;
}

void Response::setRawHeaderPairs(const QList<QNetworkReply::RawHeaderPair> &pairs)
{
    mRawHeaderPairs = pairs;

}

QByteArray Response::rawHeader(const QByteArray &headerName) const
{

    foreach (QNetworkReply::RawHeaderPair pair, rawHeaderPairs()){
        if (pair.first == headerName)
            return pair.second;
    }

    return QByteArray();



}

