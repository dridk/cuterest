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


