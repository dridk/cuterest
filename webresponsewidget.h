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

#ifndef WEBRESPONSEWIDGET_H
#define WEBRESPONSEWIDGET_H

#include <QtWidgets>
#include <QWebView>
#include <QWebFrame>
#include <QWebElement>
#include "abstractresponsewidget.h"

class WebResponseWidget : public AbstractResponseWidget
{
    Q_OBJECT
public:
    WebResponseWidget(QWidget * parent=0);
    ~WebResponseWidget();

  protected:
    void examineChildElements(const QWebElement &parentElement,
                                      QTreeWidgetItem *parentItem);

public slots:
    virtual void setResponse(const Response& rep) ;
    void elementClicked(const QModelIndex& index);




private:
    QWebView * mWebView;
    QTreeWidget * mTreeWidget;

};

#endif // WEBRESPONSEWIDGET_H
