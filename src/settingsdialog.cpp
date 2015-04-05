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

#include "settingsdialog.h"
#include <QVBoxLayout>
#include "proxysettingswidget.h"
#include "authsettingswidget.h"
#include "cookiesettingswidget.h"

SettingsDialog::SettingsDialog(Manager   * manager,QWidget *parent)
    : QDialog(parent)
{
    mManager = manager;
    mTabWidget = new QTabWidget;
    mButtonBox = new QDialogButtonBox(QDialogButtonBox::Save|
                                      QDialogButtonBox::Reset|
                                      QDialogButtonBox::Cancel);

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(mTabWidget);
    layout->addWidget(mButtonBox);

    setLayout(layout);
    resize(600,400);

    addSettingsWidget(new ProxySettingsWidget());
//    addSettingsWidget(new AuthSettingsWidget());
    addSettingsWidget(new CookieSettingsWidget());

    connect(mButtonBox,SIGNAL(accepted()),this,SLOT(save()));
    connect(mButtonBox,SIGNAL(rejected()),this,SLOT(reject()));
    connect(mButtonBox,SIGNAL(clicked(QAbstractButton*)),this,SLOT(buttonClicked(QAbstractButton*)));

    load();

    setWindowTitle(tr("Settings"));
}

SettingsDialog::~SettingsDialog()
{
    qDeleteAll(mWidgets);

    delete mTabWidget;
    delete mButtonBox;
}

void SettingsDialog::addSettingsWidget(AbstractSettingsWidget *widget)
{

    widget->setManager(mManager);
    mTabWidget->addTab(widget,widget->windowIcon(), widget->windowTitle());
    mWidgets.append(widget);


}

void SettingsDialog::save()
{

    foreach( AbstractSettingsWidget * w, mWidgets)
    {
        if (!w->save())
            return;
    }
    emit accept();
}

void SettingsDialog::load()
{
    foreach( AbstractSettingsWidget * w, mWidgets)
        w->load();
}

void SettingsDialog::reset()
{
    foreach( AbstractSettingsWidget * w, mWidgets)
        w->reset();
}

void SettingsDialog::buttonClicked(QAbstractButton *button)
{
    if (mButtonBox->standardButton(button) == QDialogButtonBox::Reset)
        reset();



}

