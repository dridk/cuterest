#ifndef ABSTRACTSETTINGSWIDGET_H
#define ABSTRACTSETTINGSWIDGET_H

#include <QWidget>

class AbstractSettingsWidget : public QWidget
{
    Q_OBJECT
public:
    AbstractSettingsWidget(QWidget * parent=0);
    ~AbstractSettingsWidget();

public slots:
    virtual void save() = 0;
    virtual void load() = 0;
};

#endif // ABSTRACTSETTINGSWIDGET_H
