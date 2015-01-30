#include "historydockwidget.h"
#include <QDebug>
HistoryDockWidget::HistoryDockWidget(QWidget * parent)
    :QDockWidget(parent)
{
    mModel = new HistoryModel;
    mView = new QTableView;
    mView->setModel(mModel);
    setWidget(mView);

    setFeatures(QDockWidget::NoDockWidgetFeatures);

    //For stylesheet
    mView->setObjectName("History");

    //hide titleBar
    setTitleBarWidget(new QWidget());

    mView->verticalHeader()->setDefaultSectionSize(26);
    mView->horizontalHeader()->hide();
    mView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    mView->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    mView->setSelectionBehavior(QAbstractItemView::SelectRows);
    mView->verticalHeader()->hide();
    mView->setAlternatingRowColors(true);

    connect(mView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickedReceived(QModelIndex)));

}

HistoryDockWidget::~HistoryDockWidget()
{
    delete mModel;
}

void HistoryDockWidget::append(const Response &rep)
{
    mModel->append(rep);
}

void HistoryDockWidget::doubleClickedReceived(const QModelIndex &index)
{


    emit doubleClicked(mModel->response(index).request());


}

