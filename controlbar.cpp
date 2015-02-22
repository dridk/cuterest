#include "controlbar.h"
#include "QtAwesome/QtAwesome.h"
#include <QInputDialog>
ControlBar::ControlBar(QWidget * parent):
    QToolBar(parent)
{
    mLineEdit = new QLineEdit;
    mVerbCombo = new VerbComboBox;
    mToolButton = new QToolButton;
    mFavButton= new QToolButton;
    mBackButton = new QToolButton;
    mForwardButton = new QToolButton;
    mRefreshButton = new QToolButton;
    mSettingButton = new QToolButton;
    mPannelButton = new QToolButton;
    mMainWidget = new QWidget;

    QHBoxLayout * wLayout = new QHBoxLayout;

    wLayout->addWidget(mBackButton);
    wLayout->addWidget(mForwardButton);

    QSpacerItem * space1 = new QSpacerItem(100,0);
    wLayout->addSpacerItem(space1);

    wLayout->addWidget(mVerbCombo);
    wLayout->addWidget(mLineEdit);
    wLayout->addWidget(mToolButton);
    wLayout->addWidget(mRefreshButton);
    wLayout->addWidget(mFavButton);

    mPannelButton->setCheckable(true);

    QSpacerItem * space2 = new QSpacerItem(100,0);
    wLayout->addSpacerItem(space2);

    wLayout->addWidget(mPannelButton);
    wLayout->addWidget(mSettingButton);


    mMainWidget->setLayout(wLayout);
    wLayout->setContentsMargins(0,0,0,0);
    wLayout->setSpacing(0);

    addWidget(mMainWidget);

    setFloatable(false);
    setMovable(false);


    mVerbCombo->setMinimumWidth(80);
    mToolButton->setIcon(QtAwesome::instance()->icon("cogs"));
    mFavButton->setIcon((QtAwesome::instance()->icon("bookmark")));
    mRefreshButton->setIcon(QtAwesome::instance()->icon("refresh"));
    mBackButton->setIcon(QtAwesome::instance()->icon("arrow-left"));
    mForwardButton->setIcon(QtAwesome::instance()->icon("arrow-right"));
    mSettingButton->setIcon(QtAwesome::instance()->icon("cog"));
    mPannelButton->setIcon(QtAwesome::instance()->icon("columns"));




    QMenu * settingMenu  = new QMenu;
    QAction * importAction = settingMenu->addAction(tr("Import"));
    QAction * exportAction = settingMenu->addAction(tr("export"));
    settingMenu->addSeparator();
    QAction * proxyAction = settingMenu->addAction(tr("Settings"));
    QAction * aboutAction = settingMenu->addAction(tr("About CuteRest"));

    mSettingButton->setMenu(settingMenu);
    mSettingButton->setPopupMode(QToolButton::InstantPopup);



    setRequest(Request(QUrl("http://api.duckduckgo.com")));





    connect(mRefreshButton,SIGNAL(clicked()),this,SLOT(sendRequest()));
    connect(mLineEdit,SIGNAL(returnPressed()),this,SLOT(sendRequest()));
    connect(mFavButton,SIGNAL(clicked()),this,SLOT(sendFavorite()));
    connect(mToolButton,SIGNAL(clicked()),this,SLOT(showRequestDialog()));
    connect(mBackButton,SIGNAL(clicked()),this,SIGNAL(backTrigger()));
    connect(mForwardButton,SIGNAL(clicked()),this,SIGNAL(forwardTrigger()));
    connect(mPannelButton,SIGNAL(clicked(bool)),this,SIGNAL(panelTrigger(bool)));

    connect(importAction,SIGNAL(triggered()),this,SIGNAL(importTrigger()));
    connect(exportAction,SIGNAL(triggered()),this,SIGNAL(exportTrigger()));
    connect(aboutAction,SIGNAL(triggered()),this,SIGNAL(aboutTrigger()));
    connect(proxyAction,SIGNAL(triggered()),this,SIGNAL(proxyTrigger()));


}

ControlBar::~ControlBar()
{
    delete mLineEdit;
    delete mVerbCombo;
    delete mToolButton;
    delete mFavButton;
    delete mBackButton;
    delete mForwardButton;
    delete mRefreshButton;
    delete mSettingButton;
    delete mPannelButton;
    delete mMainWidget;
}

void ControlBar::setRequest(const Request &request)
{
    qDebug()<<"set URL"<<request.url();
    mRequest = request;
    mLineEdit->setText(mRequest.url().toString());
    mVerbCombo->setCurrentText(mRequest.verb());
    emit requestTrigger(mRequest);



}


Request ControlBar::createRequest()
{

    mRequest.setUrl(mLineEdit->text());
    mRequest.setVerb(mVerbCombo->currentText());

    return mRequest;
}

void ControlBar::sendRequest()
{
    emit requestTrigger(createRequest());
}

void ControlBar::sendFavorite()
{
    QString name = QInputDialog::getText(this,"enter name", "name");
    Request r = createRequest();
    r.setName(name);

    emit favoriteTrigger(r);
}

void ControlBar::showRequestDialog()
{

    RequestDialog dialog(createRequest(),this);
    if (dialog.exec())
        setRequest(dialog.request());

}


