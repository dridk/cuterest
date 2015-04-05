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

#include "headerrequestwidget.h"

HeaderRequestWidget::HeaderRequestWidget(QWidget *parent) :
    AbstractRequestWidget(parent)
{

    mEditor = new DictEditorWidget;
    QVBoxLayout * ll = new QVBoxLayout;
    ll->addWidget(mEditor);
    setLayout(ll);
    setWindowTitle(tr("Headers"));
    mEditor->setLabel(tr("Header type:  "),tr("Header value:  "));

    QStringList list;
    list<<"Accept"
       <<"Accept-Charset"
      <<"Accept-Encoding"
     <<"Accept-Language"
    <<"Accept-Datetime"
    <<"Authorization"
    <<"Cache-Control"
    <<"Connection"
    <<"Cookie"
    <<"Content-Length"
    <<"Content-MD5"
    <<"Content-Type"
    <<"Date"
    <<"Expect"
    <<"From"
    <<"Host"
    <<"If-Match"
    <<"If-Modified-Since"
    <<"If-None-Match"
    <<"If-Range"
    <<"If-Unmodified-Since"
    <<"Max-Forwards"
    <<"Origin"
    <<"Pragma"
    <<"Proxy-Authorization"
    <<"Range"
    <<"Referer"
    <<"TE"
    <<"User-Agent"
    <<"Upgrade"
    <<"Via";

    mEditor->setCompleter(list);
}

HeaderRequestWidget::~HeaderRequestWidget()
{

}

void HeaderRequestWidget::load(Request &request)
{
    mEditor->clear();

    foreach (QByteArray header, request.rawHeaderList()){
        mEditor->insert(header, request.rawHeader(header));
    }
}

void HeaderRequestWidget::save(Request &request)
{
    request.clearRawHeaders();
    for (int row=0; row < mEditor->count(); row++){

        qDebug()<<mEditor->key(row);
        request.setRawHeader(mEditor->key(row).toUtf8(), mEditor->value(row).toByteArray());
    }
}

void HeaderRequestWidget::reset()
{
    mEditor->clear();
}

