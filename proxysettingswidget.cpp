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
    settings.setValue("type", mTypeCombo->currentData().toInt());
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
