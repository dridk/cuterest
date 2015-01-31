#include "findbarwidget.h"
#include <QtAwesome/QtAwesome.h>
FindBarWidget::FindBarWidget(QWidget *parent) : QFrame(parent)
{
    mEdit = new QLineEdit;
    mRegButton = new QToolButton;
    mFindButton = new QPushButton(tr("Search"));

    mRegButton->setAutoRaise(true);
    mRegButton->setCheckable(true);
    mRegButton->setIcon(QtAwesome::instance()->icon(0xf0e7));

    QMenu * menu = new QMenu(this);
    menu->addAction(tr("key"));
    menu->addAction(tr("value"));


    mFindButton->setMenu(menu);

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget(mRegButton);
    layout->addWidget(mEdit);
    layout->addWidget(mFindButton);

    setLayout(layout);

    connect(mEdit,SIGNAL(textChanged(QString)),this,SIGNAL(textChanged(QString)));


}

FindBarWidget::~FindBarWidget()
{

}

