#include "proxysettingswidget.h"

ProxySettingsWidget::ProxySettingsWidget(QWidget * parent)
    :AbstractSettingsWidget(parent)
{
    mHostEdit    = new QLineEdit();
    mPortEdit    = new QLineEdit();
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


    QVBoxLayout * mainLayout = new QVBoxLayout;
    mainLayout->addWidget(mTypeCombo);
    mainLayout->addWidget(mBox);

    setLayout(mainLayout);
    setWindowTitle("Proxy");

    connect(mTypeCombo,SIGNAL(activated(int)),this,SLOT(typeChanged(int)));
}

ProxySettingsWidget::~ProxySettingsWidget()
{

}

void ProxySettingsWidget::save()
{

}

void ProxySettingsWidget::load()
{

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

