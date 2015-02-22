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

    connect(mTypeCombo,SIGNAL(activated(int)),this,SLOT(typeChanged(int)));
}

ProxySettingsWidget::~ProxySettingsWidget()
{

}

bool ProxySettingsWidget::save()
{


    QNetworkProxy proxy;
    proxy.setType(QNetworkProxy::ProxyType(mTypeCombo->currentData().toInt()));
    proxy.setHostName(mHostEdit->text());
    proxy.setPort(mPortEdit->value());
    proxy.setUser(mUserEdit->text());
    proxy.setPassword(mPasswordEdit->text());

    manager()->setProxy(proxy);

    return true;


}

bool ProxySettingsWidget::load()
{

    QNetworkProxy proxy = manager()->proxy();

    for (int i=0; i<mTypeCombo->count(); ++i){
        if (mTypeCombo->itemData(i).toInt() == proxy.type())
            mTypeCombo->setCurrentIndex(i);
    }

    mHostEdit->setText(proxy.hostName());
    mPortEdit->setValue(proxy.port());
    mUserEdit->setText(proxy.user());
    mPasswordEdit->setText(proxy.password());


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

