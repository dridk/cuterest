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

#include "statusbar.h"

StatusBar::StatusBar(QWidget * parent)
    :QStatusBar(parent)
{


    mLoadingLabel = new QLabel;
    mLoadingLabel->setMovie(new QMovie(":/loading.gif"));
    insertPermanentWidget(0, mLoadingLabel);


}

StatusBar::~StatusBar()
{
delete mLoadingLabel;
}

void StatusBar::setLoading(bool loading)
{
    mLoadingLabel->setVisible(loading);

    if (loading){
        mLoadingLabel->movie()->start();

    }
    else {
        mLoadingLabel->movie()->stop();

    }

}

void StatusBar::setResponse(const Response &response)
{


    showMessage(response.rawHeader("Content-Type") + QString(" %1 bytes").arg(response.body().size()));


}

