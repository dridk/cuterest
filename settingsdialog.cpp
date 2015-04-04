#include "settingsdialog.h"
#include <QVBoxLayout>
#include "proxysettingswidget.h"
#include "authsettingswidget.h"
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
//    addSettingsWidget(new AuthSettingsWidget());
    addSettingsWidget(new CookieSettingsWidget());

    connect(mButtonBox,SIGNAL(accepted()),this,SLOT(save()));
    connect(mButtonBox,SIGNAL(rejected()),this,SLOT(reject()));
    connect(mButtonBox,SIGNAL(clicked(QAbstractButton*)),this,SLOT(buttonClicked(QAbstractButton*)));

    load();
}

SettingsDialog::~SettingsDialog()
{
    qDeleteAll(mWidgets);

    delete mTabWidget;
    delete mButtonBox;
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

void SettingsDialog::reset()
{
    foreach( AbstractSettingsWidget * w, mWidgets)
        w->reset();
}

void SettingsDialog::buttonClicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton type = mButtonBox->standardButton(button) ;
    if (mButtonBox->standardButton(button) == QDialogButtonBox::Reset)
        reset();



}

