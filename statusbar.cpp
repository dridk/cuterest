#include "statusbar.h"

StatusBar::StatusBar(QWidget * parent)
    :QStatusBar(parent)
{


    mLoadingLabel = new QLabel;
    mLoadingLabel->setMovie(new QMovie(":/loading.gif"));
    insertPermanentWidget(0, mLoadingLabel);


}

StatusBar::~StatusBar()
{
delete mLoadingLabel;
}

void StatusBar::setLoading(bool loading)
{
    mLoadingLabel->setVisible(loading);

    if (loading){
        mLoadingLabel->movie()->start();

    }
    else {
        mLoadingLabel->movie()->stop();

    }

}

void StatusBar::setResponse(const Response &response)
{


    showMessage(response.rawHeader("Content-Type"));


}

