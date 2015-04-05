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

QList<QByteArray> Response::rawHeaderList() const
{
    QList<QByteArray> list;
    foreach (QNetworkReply::RawHeaderPair pair, rawHeaderPairs()){
        list.append(pair.first);
    }


    return list;
}

