#include "searchbar.h"

SearchBar::SearchBar(QWidget * parent):
    QToolBar(parent)
{
    mLineEdit = new QLineEdit;
    mVerbCombo = new QComboBox;
    mToolButton = new QToolButton;
    mSearchButton = new QPushButton(tr("Search"));
    mMainWidget = new QWidget;

    QHBoxLayout * layout = new QHBoxLayout;

    layout->addWidget(mVerbCombo);
    layout->addWidget(mLineEdit);
    layout->addWidget(mToolButton);
    layout->addWidget(mSearchButton);

    mMainWidget->setLayout(layout);
    layout->setContentsMargins(0,0,0,0);

    addWidget(mMainWidget);


    mVerbCombo->setMinimumWidth(80);
    mToolButton->setIcon(QIcon(":gear.png"));



    // Set verbs

    QStringList verbs;
    verbs<<"GET"<<"POST"<<"PUT"<<"DELETE";
    setVerbs(verbs);


}

SearchBar::~SearchBar()
{

}

void SearchBar::setVerbs(const QStringList &list)
{

    foreach (QString verb, list){

        mVerbCombo->addItem(verb);

    }




}


