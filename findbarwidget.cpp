#include "findbarwidget.h"
#include <QtAwesome/QtAwesome.h>
FindBarWidget::FindBarWidget(TreeSortFilterProxyModel * model,QWidget *parent)
    : QFrame(parent)
{
    mEdit = new QLineEdit;
    mColBox = new QComboBox();
    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget(mEdit);
    layout->addWidget(mColBox);
    setLayout(layout);

    mModel = model;

    for (int i=0; i< mModel->columnCount(); ++i)
        mColBox->addItem(mModel->headerData(i,Qt::Horizontal).toString());



    connect(mEdit,SIGNAL(textChanged(QString)),this,SIGNAL(textChanged(QString)));
    connect(mEdit,SIGNAL(textChanged(QString)),mModel,SLOT(setFilterFixedString(QString)));
    connect(mColBox,SIGNAL(currentIndexChanged(int)),this,SLOT(setFilterColumn(int)));


}

FindBarWidget::~FindBarWidget()
{

}



void FindBarWidget::edit()
{
    mEdit->setFocus();
    mEdit->selectAll();

}

void FindBarWidget::setFilterColumn(int row)
{
    mModel->setFilterKeyColumn(row);
}

