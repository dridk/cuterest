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

#include "responsetabwidget.h"
ResponseTabWidget::ResponseTabWidget(QWidget * parent)
    :QTabWidget(parent)
{

    mUrlModel   = new UrlModel;
    mTextWidget = new TextResponseWidget();
    mJsonWidget = new JsonResponseWidget();
    mInfoWidget = new InfoResponseWidget();
    mWebWidget  = new WebResponseWidget();
    mXmlWidget  = new XmlResponseWidget();

    addResponseWidget(mTextWidget);
    addResponseWidget(mJsonWidget);
    addResponseWidget(mXmlWidget);
    addResponseWidget(mInfoWidget);
    addResponseWidget(mWebWidget);

    connect(mJsonWidget,SIGNAL(requestTrigger(Request)),this,SIGNAL(requestTrigger(Request)));

    setObjectName("response");



}

ResponseTabWidget::~ResponseTabWidget()
{
    qDeleteAll(mList);
    delete mUrlModel;
}

void ResponseTabWidget::addResponseWidget(AbstractResponseWidget *widget)
{

    addTab(widget, widget->windowTitle());
    mList.append(widget);
    widget->setEnabled(false);



}

UrlModel *ResponseTabWidget::urlModel()
{
    return mUrlModel;
}

void ResponseTabWidget::setResponse(const Response &rep)
{

    // If response if valid, save the url .. This is used for search line completer
    if ( (rep.statusCode() >=200) && (rep.statusCode() <300))
        mUrlModel->append(rep.request().url());

    foreach (AbstractResponseWidget * w, mList) {
        w->setResponse(rep);

    }

    //    setCurrentWidget(widgetFromType(rep.rawHeader("Content-Type")));

}

void ResponseTabWidget::nextTab()
{
    setCurrentIndex(currentIndex() == count()-1 ? 0 : currentIndex()+1);
}

void ResponseTabWidget::previousTab()
{
    setCurrentIndex(currentIndex() == 0 ? count()-1 : currentIndex()-1);

}

AbstractResponseWidget *ResponseTabWidget::widgetFromType(const QByteArray &array)
{
    AbstractResponseWidget * w = mTextWidget;

    if (array.contains("html"))
        w = mWebWidget;
    if (array.contains("json"))
        w = mJsonWidget;

    return w;





}

