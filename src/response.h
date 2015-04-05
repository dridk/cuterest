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

#ifndef REPONSE_H
#define REPONSE_H
#include <QtCore>
#include <QByteArray>
#include <QNetworkReply>
#include "request.h"
class Response
{
public:
    Response();
    ~Response();
    void setBody(const QByteArray& body);
    const QByteArray &body() const;

    void setElapsed(qint64 time);
    qint64 elapsed() const;

    void setRequest(const Request& request);
    const Request &request() const;

    void setStatusCode(int code);
    int statusCode() const;

    const QDateTime &time() const;
    int size() const;

    const QList<QNetworkReply::RawHeaderPair> &rawHeaderPairs() const;
    void setRawHeaderPairs(const QList<QNetworkReply::RawHeaderPair> & pairs);

    QByteArray	rawHeader(const QByteArray & headerName) const;
    QList<QByteArray> rawHeaderList() const;

private:
    QList<QNetworkReply::RawHeaderPair> mRawHeaderPairs;
    QByteArray mBody;
    qint64	mElapsed;
    Request mRequest;
    int mStatusCode;
    QDateTime mTime;
    int mSize;




};

#endif // REPONSE_H
