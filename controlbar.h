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

#ifndef SEARCHBAR_H
#define SEARCHBAR_H
#include <QtWidgets>
#include "request.h"
#include "requestdialog.h"
#include "verbcombobox.h"
#include "historymodel.h"
#include "urlmodel.h"

class ControlBar : public QToolBar
{
    Q_OBJECT
public:
    ControlBar(QWidget * parent=0);
    ~ControlBar();

    void setUrlModel(UrlModel * model);


public slots:
    void setRequest(const Request& request);
    void sendRequest(const Request& request);

signals:
    void requestTrigger(const Request& request);
    void favoriteTrigger(const Request& request);
    void backTrigger();
    void forwardTrigger();
    void importTrigger();
    void exportTrigger();
    void aboutTrigger();
    void proxyTrigger();
    void abortTrigger();

    void historyClicked(bool checked);
    void favoriteClicked(bool checked);
    void consoleClicked(bool checked);



protected:
    Request createRequest();

protected slots:
    void sendRequest();
    void sendFavorite();
    void showRequestDialog();
    void setLoading(bool loading);
    void edit();


private:
    QLineEdit * mLineEdit;
    VerbComboBox * mVerbCombo;
    QToolButton * mFavButton;
    QToolButton * mBackButton;
    QToolButton * mForwardButton;
    QToolButton * mSettingButton;
    QAction * mRefreshAction;
    QWidget * mMainWidget;
    Request mRequest;
    QCompleter * mCompleter;
    bool mIsLoading;
};

#endif // SEARCHBAR_H
