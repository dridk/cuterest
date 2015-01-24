#include "searchbar.h"

SearchBar::SearchBar(QWidget * parent):
    QToolBar(parent)
{
    mLineEdit = new QLineEdit;
    mVerbCombo = new QComboBox;
    mToolButton = new QToolButton;
    mFavButton= new QToolButton;
    mSearchButton = new QPushButton(tr("Search"));
    mMainWidget = new QWidget;

    QHBoxLayout * layout = new QHBoxLayout;

    layout->addWidget(mVerbCombo);
    layout->addWidget(mLineEdit);
    layout->addWidget(mToolButton);
    layout->addWidget(mFavButton);

    layout->addWidget(mSearchButton);

    mMainWidget->setLayout(layout);
    layout->setContentsMargins(0,0,0,0);

    addWidget(mMainWidget);


    mVerbCombo->setMinimumWidth(80);
    mToolButton->setIcon(QIcon(":gear.png"));
    mFavButton->setIcon(QIcon(":fav_on.png"));

    //temp test
    mLineEdit->setText("http://wingo.labsquare.org/config");




    // Set verbs

    QStringList verbs;
    verbs<<"GET"<<"POST"<<"PUT"<<"DELETE";
    setVerbs(verbs);

    connect(mSearchButton,SIGNAL(clicked()),this,SLOT(createRequest()));
    connect(mLineEdit,SIGNAL(returnPressed()),this,SLOT(createRequest()));


}

SearchBar::~SearchBar()
{

}

void SearchBar::setRequest(const Request &request)
{

    mRequest = request;
    mLineEdit->setText(mRequest.url().toString());
    emit triggerRequest(mRequest);



}

void SearchBar::setVerbs(const QStringList &list)
{

    foreach (QString verb, list){

        mVerbCombo->addItem(verb);

    }




}

void SearchBar::createRequest()
{

    Request request;
    request.setUrl(mLineEdit->text());
    request.setVerb(mVerbCombo->currentText());

    emit triggerRequest(request);


}


