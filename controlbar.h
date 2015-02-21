#ifndef SEARCHBAR_H
#define SEARCHBAR_H
#include <QtWidgets>
#include "request.h"
#include "requestdialog.h"
#include "verbcombobox.h"
class ControlBar : public QToolBar
{
    Q_OBJECT
public:
    ControlBar(QWidget * parent=0);
    ~ControlBar();

public slots:
    void setRequest(const Request& request);

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
protected:
    Request createRequest();

protected slots:
    void sendRequest();
    void sendFavorite();
    void showRequestDialog();



private:
    QLineEdit * mLineEdit;
    VerbComboBox * mVerbCombo;
    QToolButton * mToolButton;
    QToolButton * mFavButton;
    QToolButton * mBackButton;
    QToolButton * mForwardButton;
    QToolButton * mSettingButton;
    QToolButton * mPannelButton;


    QToolButton * mRefreshButton;
    QWidget * mMainWidget;
    Request mRequest;
};

#endif // SEARCHBAR_H
