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

#include "authsettingswidget.h"

AuthSettingsWidget::AuthSettingsWidget(QWidget * parent):
    AbstractSettingsWidget(parent)
{
    setWindowTitle(tr("Authentification"));
    mUserEdit = new QLineEdit;
    mPassEdit = new QLineEdit;
    mPassEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    QFormLayout * fLayout = new QFormLayout;
    fLayout->addRow(tr("username"), mUserEdit);
    fLayout->addRow(tr("password"),mPassEdit);

    setLayout(fLayout);

}

AuthSettingsWidget::~AuthSettingsWidget()
{

}

bool AuthSettingsWidget::save()
{


    return true;
}

bool AuthSettingsWidget::load()
{

    return true;
}

bool AuthSettingsWidget::reset()
{
    mUserEdit->clear();
    mPassEdit->clear();

    return true;


}


