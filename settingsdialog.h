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

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QTabWidget>
#include <QDialogButtonBox>
#include <QNetworkProxy>
#include <QNetworkAccessManager>
#include "manager.h"
#include "abstractsettingswidget.h"
class SettingsDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SettingsDialog(Manager * manager, QWidget *parent = 0);
    ~SettingsDialog();

    void addSettingsWidget(AbstractSettingsWidget* widget);
public slots:
    void save();
    void load();
    void reset();

protected slots:
    void buttonClicked(QAbstractButton * button);
private:
    QList<AbstractSettingsWidget*> mWidgets;
    QTabWidget * mTabWidget;
    QDialogButtonBox * mButtonBox;
    Manager * mManager;
};

#endif // SETTINGSDIALOG_H
