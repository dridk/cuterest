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

#include "webresponsewidget.h"
WebResponseWidget::WebResponseWidget(QWidget * parent)
    :AbstractResponseWidget(parent)
{
    mWebView = new QWebView;
    mTreeWidget = new QTreeWidget;

//    QSplitter * splitter = new QSplitter(Qt::Horizontal);

    //Disable html tree for now ..

//    splitter->addWidget(mTreeWidget);
//    splitter->addWidget(mWebView);
    setWidget(mWebView);

    setWindowTitle("Web");



//    connect(mTreeWidget,SIGNAL(clicked(QModelIndex)),this,SLOT(elementClicked(QModelIndex)));
}

WebResponseWidget::~WebResponseWidget()
{
    delete mWebView;
    delete mTreeWidget;
}

void WebResponseWidget::setResponse(const Response &rep)
{
    mWebView->setHtml("<html></html>");
    mWebView->setHtml(rep.body());

    mTreeWidget->clear();
    QWebElement document = mWebView->page()->mainFrame()->documentElement();
    examineChildElements(document, mTreeWidget->invisibleRootItem());
}

void WebResponseWidget::elementClicked(const QModelIndex &index)
{



}

void WebResponseWidget::examineChildElements(const QWebElement &parentElement,
                                             QTreeWidgetItem *parentItem)
{
    QWebElement element = parentElement.firstChild();
    while (!element.isNull()) {

        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText(0, element.tagName());


        parentItem->addChild(item);

        examineChildElements(element, item);

        element = element.nextSibling();
    }
}
