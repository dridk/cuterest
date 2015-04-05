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

#include "xmlresponsewidget.h"
#include <QVBoxLayout>
#include "QtAwesome/QtAwesome.h"
XmlResponseWidget::XmlResponseWidget(QWidget * parent )
    :AbstractResponseWidget(parent)
{

    mView = new QTreeView;
    mModel = new DomModel();
    mProxyModel = new TreeSortFilterProxyModel();
    mToolBar = new QToolBar;

    mProxyModel->setSourceModel(mModel);
    mView->setModel(mProxyModel);

    mSearchEdit = new FindBarWidget(mProxyModel);




    mToolBar->setIconSize(QSize(16,16));
    mToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);


    QAction * expandAction   = mToolBar->addAction(QtAwesome::instance()->icon(0xf067),tr("Expand all"));
    QAction * collapseAction = mToolBar->addAction(QtAwesome::instance()->icon(0xf068),tr("Collapse all"));

    QWidget* spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mToolBar->addWidget(spacer);

    QAction * searchAction = mToolBar->addAction(QtAwesome::instance()->icon(0xf002),tr("Search"));
    QAction * copyKeyAction = mToolBar->addAction(QtAwesome::instance()->icon(0xf0ea),tr("Copy key"));
    QAction * copyAttributAction = mToolBar->addAction(QtAwesome::instance()->icon(0xf0ea),tr("Copy attribut"));
    QAction * copyValueAction = mToolBar->addAction(QtAwesome::instance()->icon(0xf0ea),tr("Copy value"));

    searchAction->setShortcut(QKeySequence("Ctrl+F"));

    searchAction->setCheckable(true);

    QWidget * mainWidget = new QWidget;
    QVBoxLayout * vLayout = new QVBoxLayout;

    vLayout->addWidget(mToolBar);
    vLayout->addWidget(mView);
    vLayout->addWidget(mSearchEdit);

    mSearchEdit->hide();
    vLayout->setSpacing(0);
    vLayout->setContentsMargins(0,0,0,0);
    mainWidget->setLayout(vLayout);
    setWidget(mainWidget);

    mView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    setWindowTitle("Xml");

    mCopyNameAction = new QAction(tr("Copy name"),this);
    mCopyAttributeAction = new QAction(tr("Copy attributes"),this);
    mCopyValueAction = new QAction(tr("Copy value"),this);

    addAction(mCopyNameAction);
    addAction(mCopyAttributeAction);
    addAction(mCopyValueAction);

    setContextMenuPolicy(Qt::ActionsContextMenu);

    connect(copyKeyAction, SIGNAL(triggered()),this,SLOT(copyKey()));
    connect(copyAttributAction, SIGNAL(triggered()),this,SLOT(copyAttribut()));
    connect(copyValueAction, SIGNAL(triggered()),this,SLOT(copyValue()));
    connect(searchAction,SIGNAL(triggered(bool)),this,SLOT(showSearch(bool)));
    connect(collapseAction,SIGNAL(triggered()),mView,SLOT(collapseAll()));
    connect(expandAction,SIGNAL(triggered()),mView,SLOT(expandAll()));


}

XmlResponseWidget::~XmlResponseWidget()
{

}

void XmlResponseWidget::setResponse(const Response &rep)
{
    qDebug()<<"set DOM TREE";

    if ( mModel->loadXml(rep.body()))
        setEnabled(true);

    else
        setEnabled(false);

}

void XmlResponseWidget::copyKey()
{
    QString tmp = mView->selectionModel()->selectedRows(0).first().data().toString();
    qApp->clipboard()->setText(tmp);

}

void XmlResponseWidget::copyAttribut()
{
    QString tmp = mView->selectionModel()->selectedRows(1).first().data().toString();
    qApp->clipboard()->setText(tmp);
}

void XmlResponseWidget::copyValue()
{
    QString tmp = mView->selectionModel()->selectedRows(2).first().data().toString();
    qApp->clipboard()->setText(tmp);
}

void XmlResponseWidget::showSearch(bool visible)
{
    mSearchEdit->setVisible(visible);

    if (visible)
        mSearchEdit->edit();
}



