#include "settingsdialog.h"
#include <QVBoxLayout>
#include "proxysettingswidget.h"
SettingsDialog::SettingsDialog(QWidget *parent) : QDialog(parent)
{
    mTabWidget = new QTabWidget;

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(mTabWidget);

    setLayout(layout);

    resize(600,400);

    addSettingsWidget(new ProxySettingsWidget());
}

SettingsDialog::~SettingsDialog()
{
    qDeleteAll(mWidgets);
}

void SettingsDialog::addSettingsWidget(AbstractSettingsWidget *widget)
{

    mTabWidget->addTab(widget,widget->windowIcon(), widget->windowTitle());
    mWidgets.append(widget);


}

