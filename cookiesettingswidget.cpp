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

#include "cookiesettingswidget.h"

CookieSettingsWidget::CookieSettingsWidget(QWidget * parent)
    :AbstractSettingsWidget(parent)
{
    setWindowTitle(tr("Cookies"));

    mView = new QTableView;
    mModel =new QStandardItemModel;
    mView->setModel(mModel);
    mClearButton = new QPushButton(tr("Clear"));

    QVBoxLayout * layout  = new QVBoxLayout;
    layout->addWidget(mView);
    layout->addWidget(mClearButton);

    setLayout(layout);

    connect(mClearButton,SIGNAL(clicked()),this,SLOT(clear()));


}

CookieSettingsWidget::~CookieSettingsWidget()
{
    delete mView;
    delete mModel;
    delete mClearButton;
}

bool CookieSettingsWidget::save()
{


return true;
}

bool CookieSettingsWidget::load()
{

return true;

    //    mModel->clear();
    //    foreach (QNetworkCookie cookie, manager()->cookieJar()->allCookies()){

    //        QList<QStandardItem*> row;

    //        row.append(new QStandardItem(cookie.domain()));
    //        row.append(new QStandardItem(cookie.expirationDate().toString()));
    //        row.append(new QStandardItem(cookie.value()));

    //        mModel->appendRow(row);




    //    }


}

bool CookieSettingsWidget::reset()
{
    return true;
}

void CookieSettingsWidget::clear()
{


}

