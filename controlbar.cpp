/*
* Copyright (c) 2015 CuteRest
* CuteRest, a json REST viewer [https://github.com/dridk/cuterest]
* This file is part of CuteRest Project.
* CuteRest is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "controlbar.h"
#include "QtAwesome/QtAwesome.h"
#include <QInputDialog>
ControlBar::ControlBar(QWidget * parent):
    QToolBar(parent)
{
    mLineEdit      = new QLineEdit;
    mVerbCombo     = new VerbComboBox;
    mFavButton     = new QToolButton;
    mBackButton    = new QToolButton;
    mForwardButton = new QToolButton;
    mSettingButton = new QToolButton;
    mMainWidget    = new QWidget;
    mCompleter     = new QCompleter();
    mIsLoading     = false;

    //Create Layout
    QHBoxLayout * wLayout = new QHBoxLayout;
    wLayout->addWidget(mBackButton);
    wLayout->addWidget(mForwardButton);

    QSpacerItem * space1 = new QSpacerItem(100,0);
    wLayout->addSpacerItem(space1);

    wLayout->addWidget(mVerbCombo);
    wLayout->addWidget(mLineEdit);
    wLayout->addWidget(mFavButton);

    QSpacerItem * space2 = new QSpacerItem(100,0);
    wLayout->addSpacerItem(space2);

    wLayout->addWidget(mSettingButton);

    mMainWidget->setLayout(wLayout);
    wLayout->setContentsMargins(0,0,0,0);
    wLayout->setSpacing(0);

    addWidget(mMainWidget);

    setFloatable(false);
    setMovable(false);

    mVerbCombo->setMinimumWidth(80);
    mFavButton->setIcon((QtAwesome::instance()->icon("bookmark")));
    mBackButton->setIcon(QtAwesome::instance()->icon("arrow-left"));
    mForwardButton->setIcon(QtAwesome::instance()->icon("arrow-right"));
    mSettingButton->setIcon(QtAwesome::instance()->icon("cog"));
    mLineEdit->setPlaceholderText(tr("Enter adress..."));

    mFavButton->setToolTip(tr("Add to favorite"));
    mBackButton->setToolTip(tr("Previous request"));
    mForwardButton->setToolTip(tr("Next request"));


    QMenu   * settingMenu  = new QMenu;
    QAction * exportAction = settingMenu->addAction(QtAwesome::instance()->icon(0xf093),tr("Export favorite"));
    QAction * importAction = settingMenu->addAction(QtAwesome::instance()->icon(0xf019),tr("Import favorite"));

    settingMenu->addSeparator();

    QAction * toogleHistAction  = settingMenu->addAction(QtAwesome::instance()->icon(0xf1da),tr("Histoy"));
    QAction * toogleFavAction   = settingMenu->addAction(QtAwesome::instance()->icon(0xf02e),tr("Favorite"));
    QAction * toogleConsAction  = settingMenu->addAction(QtAwesome::instance()->icon(0xf120),tr("Console"));


    settingMenu->addSeparator();

    QAction * proxyAction = settingMenu->addAction(QtAwesome::instance()->icon(0xf0ad),tr("Settings"));
    QAction * aboutAction = settingMenu->addAction(QtAwesome::instance()->icon(0xf129),tr("About CuteRest"));


   exportAction->setShortcut(QKeySequence("Ctrl+S"));
   importAction->setShortcut(QKeySequence("Ctrl+O"));

   toogleHistAction->setCheckable(true);
   toogleFavAction->setCheckable(true);
   toogleConsAction->setCheckable(true);

   toogleHistAction->setShortcut(QKeySequence("Ctrl+H"));
   toogleFavAction->setShortcut(QKeySequence("Ctrl+F"));
   toogleConsAction->setShortcut(QKeySequence("Ctrl+T"));


    mSettingButton->setMenu(settingMenu);
    mSettingButton->setPopupMode(QToolButton::InstantPopup);

    QAction * optionAction =  mLineEdit->addAction(QtAwesome::instance()->icon("cog"),QLineEdit::LeadingPosition);
    mRefreshAction = mLineEdit->addAction(QtAwesome::instance()->icon("refresh"),QLineEdit::TrailingPosition);

    optionAction->setToolTip(tr("Custom request"));
    mRefreshAction->setToolTip(tr("Refresh request"));

    setRequest(Request(QUrl("http://api.duckduckgo.com/?q=apple&format=json&pretty=1")));
    setWindowTitle(tr("Control"));

    connect(mRefreshAction,SIGNAL(triggered()),this,SLOT(sendRequest()));
    connect(optionAction,SIGNAL(triggered()),this,SLOT(showRequestDialog()));
    connect(mLineEdit,SIGNAL(returnPressed()),this,SLOT(sendRequest()));
    connect(mFavButton,SIGNAL(clicked()),this,SLOT(sendFavorite()));
    connect(mBackButton,SIGNAL(clicked()),this,SIGNAL(backTrigger()));
    connect(mForwardButton,SIGNAL(clicked()),this,SIGNAL(forwardTrigger()));

    connect(importAction,SIGNAL(triggered()),this,SIGNAL(importTrigger()));
    connect(exportAction,SIGNAL(triggered()),this,SIGNAL(exportTrigger()));
    connect(aboutAction,SIGNAL(triggered()),this,SIGNAL(aboutTrigger()));
    connect(proxyAction,SIGNAL(triggered()),this,SIGNAL(proxyTrigger()));

    connect(toogleHistAction,SIGNAL(triggered(bool)),this,SIGNAL(historyClicked(bool)));
    connect(toogleFavAction,SIGNAL(triggered(bool)),this,SIGNAL(favoriteClicked(bool)));
    connect(toogleConsAction,SIGNAL(triggered(bool)),this,SIGNAL(consoleClicked(bool)));

}

ControlBar::~ControlBar()
{
    delete mLineEdit;
    delete mVerbCombo;
    delete mFavButton;
    delete mBackButton;
    delete mForwardButton;
    delete mSettingButton;
    delete mMainWidget;
}

void ControlBar::setUrlModel(UrlModel *model)
{
    mCompleter->setModel(model);
    mCompleter->setCompletionColumn(0);
    mCompleter->setCompletionRole(Qt::DisplayRole);
    mCompleter->setCompletionMode(QCompleter::PopupCompletion);
    mLineEdit->setCompleter(mCompleter);

}



void ControlBar::setRequest(const Request &request)
{
    qDebug()<<"set URL"<<request.url();
    mRequest = request;
    mLineEdit->setText(mRequest.url().toString());
    mVerbCombo->setCurrentText(mRequest.verb());
    //    emit requestTrigger(mRequest);



}

void ControlBar::sendRequest(const Request &request)
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
    if (mIsLoading)
    {
        emit abortTrigger();
        return;
    }

    if  (mLineEdit->text().contains(QRegularExpression("^(http|https)://"))){

    }
    else {
        QString text = mLineEdit->text();
        text.prepend("http://");
        mLineEdit->setText(text);
    }


    emit requestTrigger(createRequest());
}

void ControlBar::sendFavorite()
{
    Request r = createRequest();
    r.setName(r.url().path());
    emit favoriteTrigger(r);
}

void ControlBar::showRequestDialog()
{

    RequestDialog dialog(createRequest(),this);
    if (dialog.exec())
        setRequest(dialog.request());

}

void ControlBar::setLoading(bool loading)
{

    // Change icons ... Refresh normal and cross when loading...
    if (loading)
        mRefreshAction->setIcon(QtAwesome::instance()->icon(0xf00d));
    else
        mRefreshAction->setIcon(QtAwesome::instance()->icon("refresh"));

    mIsLoading = loading;


}

void ControlBar::edit()
{
    mLineEdit->setFocus();
    mLineEdit->selectAll();

}




