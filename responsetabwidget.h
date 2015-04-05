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

#ifndef RESPONSETABWIDGET_H
#define RESPONSETABWIDGET_H
#include <QTabWidget>
#include "urlmodel.h"
#include "abstractresponsewidget.h"
#include "response.h"
#include "responsetabwidget.h"
#include "textresponsewidget.h"
#include "jsonresponsewidget.h"
#include "inforesponsewidget.h"
#include "webresponsewidget.h"
#include "xmlresponsewidget.h"
class ResponseTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    ResponseTabWidget(QWidget * parent =0);
    ~ResponseTabWidget();

    void addResponseWidget(AbstractResponseWidget * widget);
    UrlModel *urlModel();

public slots:
    void setResponse(const Response& rep);
    void nextTab();
    void previousTab();

signals:
    void requestTrigger(const Request& request);

protected:
    AbstractResponseWidget *widgetFromType(const QByteArray& array);


private:
    QList<AbstractResponseWidget*> mList;

    TextResponseWidget* mTextWidget ;
    JsonResponseWidget* mJsonWidget;
    InfoResponseWidget* mInfoWidget ;
    WebResponseWidget*  mWebWidget ;
    XmlResponseWidget * mXmlWidget;

    UrlModel * mUrlModel; // save url if it's valid...


};

#endif // RESPONSETABWIDGET_H
