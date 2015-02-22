#include "settingsdialog.h"
#include <QVBoxLayout>
#include "proxysettingswidget.h"
#include "cookiesettingswidget.h"
SettingsDialog::SettingsDialog(Manager   * manager,QWidget *parent)
    : QDialog(parent)
{
    mManager = manager;
    mTabWidget = new QTabWidget;
    mButtonBox = new QDialogButtonBox(QDialogButtonBox::Save|
                                      QDialogButtonBox::Reset|
                                      QDialogButtonBox::Cancel);

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(mTabWidget);
    layout->addWidget(mButtonBox);

    setLayout(layout);
    resize(600,400);

    addSettingsWidget(new ProxySettingsWidget());
    addSettingsWidget(new CookieSettingsWidget());

    connect(mButtonBox,SIGNAL(accepted()),this,SLOT(save()));
    connect(mButtonBox,SIGNAL(rejected()),this,SLOT(reject()));

    load();
}

SettingsDialog::~SettingsDialog()
{
    qDeleteAll(mWidgets);
}

void SettingsDialog::addSettingsWidget(AbstractSettingsWidget *widget)
{

    widget->setManager(mManager);
    mTabWidget->addTab(widget,widget->windowIcon(), widget->windowTitle());
    mWidgets.append(widget);


}

void SettingsDialog::save()
{

    foreach( AbstractSettingsWidget * w, mWidgets)
    {
        if (!w->save())
            return;
    }
    emit accept();
}

void SettingsDialog::load()
{
    foreach( AbstractSettingsWidget * w, mWidgets)
        w->load();
}

