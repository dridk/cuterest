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

#ifndef JSONRESPONSEWIDGET_H
#define JSONRESPONSEWIDGET_H

#include <QtWidgets>
#include <QKeyEvent>
#include <QDomDocument>
#include "treesortfilterproxymodel.h"
#include "qjsonmodel.h"
#include "dommodel.h"
#include "abstractresponsewidget.h"
#include "request.h"
#include "findbarwidget.h"
#include "jsonitemdelegate.h"
class JsonResponseWidget : public AbstractResponseWidget
{
    Q_OBJECT
public:
    JsonResponseWidget(QWidget * parent = 0);
    ~JsonResponseWidget();


public slots:
    void setResponse(const Response& rep);
    void copyKey();
    void copyValue();
    void showSearch(bool visible);


protected slots:
    void doubleClicked(const QModelIndex& index);
protected:
   // void contextMenuEvent(QContextMenuEvent * event);


signals:
    void requestTrigger(const Request& request);
private:
    QTreeView * mView;
    QJsonModel * mJsonModel;
    TreeSortFilterProxyModel * mProxyModel;
    FindBarWidget * mSearchEdit;
    JsonItemDelegate * mDelegate;
    QStringList mDomType;
    QStringList mJsonType;
    Response mCurrentResponse;
    QToolBar * mToolBar;
};

#endif // JSONRESPONSEWIDGET_H
