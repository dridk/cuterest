#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QTabWidget>
#include "abstractsettingswidget.h"
class SettingsDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

    void addSettingsWidget(AbstractSettingsWidget* widget);

private:
    QList<AbstractSettingsWidget*> mWidgets;
    QTabWidget * mTabWidget;
};

#endif // SETTINGSDIALOG_H
