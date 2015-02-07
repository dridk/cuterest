#include "searchbar.h"
#include "QtAwesome/QtAwesome.h"
#include <QInputDialog>
SearchBar::SearchBar(QWidget * parent):
    QToolBar(parent)
{
    mLineEdit = new QLineEdit;
    mVerbCombo = new VerbComboBox;
    mToolButton = new QToolButton;
    mFavButton= new QToolButton;
    mSearchButton = new QPushButton(tr("Send"));
    mMainWidget = new QWidget;

    QHBoxLayout * wLayout = new QHBoxLayout;

    wLayout->addWidget(mVerbCombo);
    wLayout->addWidget(mLineEdit);
    wLayout->addWidget(mToolButton);
    wLayout->addWidget(mFavButton);

    wLayout->addWidget(mSearchButton);

    mMainWidget->setLayout(wLayout);
    wLayout->setContentsMargins(0,0,0,0);
    wLayout->setSpacing(0);

    addWidget(mMainWidget);

    setFloatable(false);
    setMovable(false);


    mVerbCombo->setMinimumWidth(80);
    mToolButton->setIcon(QtAwesome::instance()->icon("cogs"));
    mFavButton->setIcon((QtAwesome::instance()->icon("bookmark")));

//    layout()->setContentsMargins(0,0,0,0);

    //temp test

    setRequest(Request(QUrl("http://api.duckduckgo.com")));





    connect(mSearchButton,SIGNAL(clicked()),this,SLOT(sendRequest()));
    connect(mLineEdit,SIGNAL(returnPressed()),this,SLOT(sendRequest()));
    connect(mFavButton,SIGNAL(clicked()),this,SLOT(sendFavorite()));
    connect(mToolButton,SIGNAL(clicked()),this,SLOT(showRequestDialog()));


}

SearchBar::~SearchBar()
{

}

void SearchBar::setRequest(const Request &request)
{
    qDebug()<<"set URL"<<request.url();
    mRequest = request;
    mLineEdit->setText(mRequest.url().toString());
    mVerbCombo->setCurrentText(mRequest.verb());
    emit requestTrigger(mRequest);



}


Request SearchBar::createRequest()
{

    mRequest.setUrl(mLineEdit->text());
    mRequest.setVerb(mVerbCombo->currentText());

    return mRequest;
}

void SearchBar::sendRequest()
{
    emit requestTrigger(createRequest());
}

void SearchBar::sendFavorite()
{
    QString name = QInputDialog::getText(this,"enter name", "name");
    Request r = createRequest();
    r.setName(name);

    emit favoriteTrigger(r);
}

void SearchBar::showRequestDialog()
{

    RequestDialog dialog(createRequest(),this);
    if (dialog.exec())
        setRequest(dialog.request());

}


