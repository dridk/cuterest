#include "proxysettingswidget.h"

ProxySettingsWidget::ProxySettingsWidget(QWidget * parent)
    :AbstractSettingsWidget(parent)
{
    mHostEdit    = new QLineEdit();
    mPortEdit    = new QLineEdit();
    mUserEdit    = new QLineEdit();
    mPasswordEdit= new QLineEdit();
    mTypeCombo   = new QComboBox();



    QFormLayout * layout = new QFormLayout;

    layout->addRow(tr("Host"), mHostEdit);
    layout->addRow(tr("Port"), mPortEdit);
    layout->addRow(tr("User"), mUserEdit);
    layout->addRow(tr("Password"), mPasswordEdit);
    layout->addRow(tr("Proxy type"), mTypeCombo);


    setLayout(layout);


    setWindowTitle("Proxy");
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

