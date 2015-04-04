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
    void panelTrigger(bool show);
    void importTrigger();
    void exportTrigger();
    void aboutTrigger();
    void proxyTrigger();
    void abortTrigger();


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
    QToolButton * mPannelButton;
    QAction * mRefreshAction;
    QWidget * mMainWidget;
    Request mRequest;
    QCompleter * mCompleter;
    bool mIsLoading;
};

#endif // SEARCHBAR_H
