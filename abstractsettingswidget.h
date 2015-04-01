#ifndef ABSTRACTSETTINGSWIDGET_H
#define ABSTRACTSETTINGSWIDGET_H

#include <QWidget>
#include <QSettings>
#include "manager.h"
class AbstractSettingsWidget : public QWidget
{
    Q_OBJECT
public:
    AbstractSettingsWidget(QWidget * parent=0);
    ~AbstractSettingsWidget();

    void setManager(Manager * manager);
    Manager *manager();

public slots:
    virtual bool save() = 0;
    virtual bool load() = 0;
    virtual bool reset() = 0;

private:
    Manager * mManager;

};

#endif // ABSTRACTSETTINGSWIDGET_H
