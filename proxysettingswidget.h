#ifndef PROXYSETTINGSWIDGET_H
#define PROXYSETTINGSWIDGET_H
#include "abstractsettingswidget.h"
#include <QtWidgets>
#include <QNetworkProxy>
class ProxySettingsWidget : public AbstractSettingsWidget
{
public:
    ProxySettingsWidget(QWidget * parent=0);
    ~ProxySettingsWidget();

public slots:
    void save();
    void load();



private:
    QLineEdit * mHostEdit;
    QLineEdit * mPortEdit;
    QLineEdit * mUserEdit;
    QLineEdit * mPasswordEdit;
    QComboBox * mTypeCombo;
};

#endif // PROXYSETTINGSWIDGET_H
