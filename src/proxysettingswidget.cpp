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

#include "proxysettingswidget.h"

ProxySettingsWidget::ProxySettingsWidget(QWidget * parent)
    :AbstractSettingsWidget(parent)
{
    mHostEdit    = new QLineEdit();
    mPortEdit    = new QSpinBox();
    mUserEdit    = new QLineEdit();
    mPasswordEdit= new QLineEdit();
    mTypeCombo   = new QComboBox();
    mBox         = new QGroupBox();

    setTypeCombo();



    QFormLayout * layout = new QFormLayout;

    layout->addRow(tr("Host"), mHostEdit);
    layout->addRow(tr("Port"), mPortEdit);
    layout->addRow(tr("User"), mUserEdit);
    layout->addRow(tr("Password"), mPasswordEdit);

    mBox->setLayout(layout);
    mPortEdit->setRange(0,65535);

    QVBoxLayout * mainLayout = new QVBoxLayout;
    mainLayout->addWidget(mTypeCombo);
    mainLayout->addWidget(mBox);

    setLayout(mainLayout);
    setWindowTitle("Proxy");

    connect(mTypeCombo,SIGNAL(currentIndexChanged(int)),this,SLOT(typeChanged(int)));
}

ProxySettingsWidget::~ProxySettingsWidget()
{
    delete mHostEdit ;
    delete mPortEdit;
    delete mUserEdit;
    delete mPasswordEdit;
    delete mTypeCombo;
    delete mBox;

}


bool ProxySettingsWidget::save()
{


    QSettings settings;
    settings.beginGroup("Proxy");
    settings.setValue("type",mTypeCombo->itemData(mTypeCombo->currentIndex()).toInt());
    settings.setValue("host", mHostEdit->text());
    settings.setValue("port", mPortEdit->value());
    settings.setValue("user", mUserEdit->text());
    settings.setValue("password", mPasswordEdit->text());
    settings.endGroup();

    manager()->loadProxySettings();


    return true;


}

bool ProxySettingsWidget::load()
{

    QSettings settings;
    settings.beginGroup("Proxy");
    mTypeCombo->setCurrentIndex(settings.value("type",QNetworkProxy::NoProxy).toInt());
    mHostEdit->setText(settings.value("host").toString());
    mPortEdit->setValue(settings.value("port").toInt());
    mUserEdit->setText(settings.value("user").toString());
    mPasswordEdit->setText(settings.value("password").toString());
    settings.endGroup();

    return true;


}

bool ProxySettingsWidget::reset()
{

    mTypeCombo->setCurrentIndex(0);
    mHostEdit->setText("");
    mPortEdit->setValue(80);
    mUserEdit->setText("");
    mPasswordEdit->setText("");



    return true;
}

void ProxySettingsWidget::typeChanged(int index)
{
    bool active = true;
    if (mTypeCombo->itemData(index) == QNetworkProxy::NoProxy)
        active = false;



    mBox->setEnabled(active);


}

void ProxySettingsWidget::setTypeCombo()
{
    mTypeCombo->clear();
    mTypeCombo->addItem("Disabled", QNetworkProxy::NoProxy);
    mTypeCombo->addItem("Default", QNetworkProxy::DefaultProxy);
    mTypeCombo->addItem("Socks5", QNetworkProxy::Socks5Proxy);
    mTypeCombo->addItem("Http", QNetworkProxy::HttpProxy);
    mTypeCombo->addItem("Http Caching", QNetworkProxy::HttpCachingProxy);
    mTypeCombo->addItem("Ftp Caching", QNetworkProxy::FtpCachingProxy);


}
