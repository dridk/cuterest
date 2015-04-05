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

#ifndef REQUESTDIALOG_H
#define REQUESTDIALOG_H
#include <QDialog>
#include <QtWidgets>
#include "abstractrequestwidget.h"
#include "headerrequestwidget.h"
#include "paramrequestwidget.h"
#include "verbcombobox.h"
#include "request.h"
class RequestDialog : public QDialog
{
    Q_OBJECT
public:
    RequestDialog(const Request& request, QWidget * parent = 0);
    ~RequestDialog();
    void addRequestWidget(AbstractRequestWidget * widget);



    const Request& request() const;
    void setRequest(const Request &request);

protected slots:
    void save();
    void load();

private:
    QTabWidget * mTabWidget;
    QDialogButtonBox * mButtonBox;
    QList<AbstractRequestWidget*> mWidgets;
    Request mRequest;

};

#endif // REQUESTDIALOG_H
