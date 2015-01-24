#include "historydockwidget.h"
#include <QDebug>
HistoryDockWidget::HistoryDockWidget(QWidget * parent)
    :QDockWidget(parent)
{
    mModel = new HistoryModel;
    mView = new QTableView;
    mView->setModel(mModel);
    setWidget(mView);

    mView->horizontalHeader()->hide();
    mView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    mView->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    mView->setSelectionBehavior(QAbstractItemView::SelectRows);
//    mView->setAlternatingRowColors(true);

}

HistoryDockWidget::~HistoryDockWidget()
{
    delete mModel;
}

void HistoryDockWidget::append(const Response &rep)
{


  mModel->append(rep);
}

