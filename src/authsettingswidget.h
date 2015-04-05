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

#ifndef AUTHSETTINGSWIDGET_H
#define AUTHSETTINGSWIDGET_H

#include <QtWidgets>
#include <QAuthenticator>
#include "abstractsettingswidget.h"
class AuthSettingsWidget : public AbstractSettingsWidget
{
    Q_OBJECT
public:
    AuthSettingsWidget(QWidget * parent=0);
    ~AuthSettingsWidget();

public slots:
    bool save();
    bool load();
    bool reset();


private:
    QLineEdit * mUserEdit;
    QLineEdit * mPassEdit;
    QCheckBox * mCheckBox;

};

#endif // AUTHSETTINGSWIDGET_H
