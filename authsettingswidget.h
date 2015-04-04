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
