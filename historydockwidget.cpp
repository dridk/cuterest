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

    setWindowTitle("History");

    mView->verticalHeader()->setDefaultSectionSize(26);
    mView->horizontalHeader()->hide();
    mView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    mView->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    mView->setSelectionBehavior(QAbstractItemView::SelectRows);
    mView->verticalHeader()->hide();
    mView->setAlternatingRowColors(true);


    //set contextual menu

    QAction * clearAction = new QAction(tr("Clear history"), this);

    mView->addAction(clearAction);
    mView->setContextMenuPolicy(Qt::ActionsContextMenu);

    connect(clearAction,SIGNAL(triggered()),this,SLOT(clear()));
    connect(mView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickedReceived(QModelIndex)));


}

HistoryDockWidget::~HistoryDockWidget()
{
    delete mModel;
}

void HistoryDockWidget::append(const Response &rep)
{
    mModel->append(rep);
    mView->selectRow(0);
}

void HistoryDockWidget::setBack()
{

    int row = mView->currentIndex().row();
    if ( row < mModel->rowCount() - 1){
        QModelIndex index = mModel->index(++row,0);
        mView->setCurrentIndex(index);
        emit doubleClicked(mModel->response(index).request());
    }


}

void HistoryDockWidget::setForward()
{


    int row = mView->currentIndex().row();
    if ( row > 0){
        QModelIndex index = mModel->index(--row,0);
        mView->setCurrentIndex(index);
        emit doubleClicked(mModel->response(index).request());
    }
}

void HistoryDockWidget::clear()
{
    mModel->clear();
}

void HistoryDockWidget::doubleClickedReceived(const QModelIndex &index)
{


    emit doubleClicked(mModel->response(index).request());


}

