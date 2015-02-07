#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QTabWidget>
#include <QDialogButtonBox>
#include <QNetworkProxy>
#include "abstractsettingswidget.h"
class SettingsDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

    void addSettingsWidget(AbstractSettingsWidget* widget);
public slots:
    void save();
    void load();
private:
    QList<AbstractSettingsWidget*> mWidgets;
    QTabWidget * mTabWidget;
    QDialogButtonBox * mButtonBox;
};

#endif // SETTINGSDIALOG_H
