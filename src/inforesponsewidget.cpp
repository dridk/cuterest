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

#include "inforesponsewidget.h"

InfoResponseWidget::InfoResponseWidget(QWidget * widget)
    :AbstractResponseWidget(widget)
{
    setWindowTitle("Info");
    mTableWidget = new QTreeWidget;
//    mListView    = new QListView;
//    mListModel   = new QStringListModel;

//    mListView->setModel(mListModel);


//    QSplitter * splitter = new QSplitter(Qt::Horizontal);

//    splitter->addWidget(mTableWidget);
//    splitter->addWidget(mListView);


    setWidget(mTableWidget);

    mTableWidget->setColumnCount(2);
    mTableWidget->setAlternatingRowColors(false);

    mTableWidget->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    mTableWidget->setHeaderLabels(QStringList()<<"Key"<<"Value");

//    connect(mTableWidget,SIGNAL(activated(QModelIndex)),this,SLOT(setListFromIndex(QModelIndex)));

}

InfoResponseWidget::~InfoResponseWidget()
{



}

void InfoResponseWidget::setResponse(const Response &rep)
{

    mTableWidget->clear();
    mTableWidget->setIndentation(0);
    foreach (QNetworkReply::RawHeaderPair pair ,rep.rawHeaderPairs())
    {

        QTreeWidgetItem * item = new QTreeWidgetItem();
        item->setText(0, pair.first);
        item->setBackgroundColor(0, QColor("#f7f7f7"));
        item->setText(1,pair.second);
        item->setFlags(Qt::ItemIsEditable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);

        mTableWidget->addTopLevelItem(item);
    }

    setEnabled(true);
}

void InfoResponseWidget::setListFromIndex(const QModelIndex &index)
{
    Q_UNUSED(index);

//    QString value = mTableWidget->currentItem()->text(1);

//    if (value.contains(";"))
//    {
//        QStringList list = value.split(";");
//        qDebug()<<list;
//        mListModel->setStringList(list);
//    }




}

