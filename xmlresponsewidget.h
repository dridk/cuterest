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

#ifndef DOMRESPONSEWIDGET_H
#define DOMRESPONSEWIDGET_H

#include <QWidget>
#include <QDomDocument>
#include "abstractresponsewidget.h"
#include "dommodel.h"
#include "findbarwidget.h"
#include "treesortfilterproxymodel.h"

class XmlResponseWidget : public AbstractResponseWidget
{
    Q_OBJECT
public:
    XmlResponseWidget(QWidget * parent = 0);
    ~XmlResponseWidget();
    void setResponse(const Response& rep);

protected slots:
    void copyKey();
    void copyAttribut();
    void copyValue();
    void showSearch(bool visible);


private:
    QDomDocument mDoc;
    DomModel * mModel;
    QTreeView * mView;
    QToolBar * mToolBar;
    QAction * mCopyNameAction;
    QAction * mCopyAttributeAction;
    QAction * mCopyValueAction;
    FindBarWidget * mSearchEdit;
    TreeSortFilterProxyModel * mProxyModel;




};

#endif // DOMRESPONSEWIDGET_H
