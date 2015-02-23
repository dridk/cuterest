#include "jsonresponsewidget.h"
#include <QClipboard>
#include <QRegularExpression>
#include <QApplication>
JsonResponseWidget::JsonResponseWidget(QWidget * parent)
    :AbstractResponseWidget(parent)
{
    setWindowTitle("Json");

    mView = new QTreeView;
    mJsonModel = new QJsonModel;
    mSearchEdit = new FindBarWidget;
    mProxyModel = new TreeSortFilterProxyModel;

    mProxyModel->setSourceModel(mJsonModel);

    QVBoxLayout * mainLayout = new QVBoxLayout;

    mainLayout->addWidget(mView);
    mainLayout->addWidget(mSearchEdit);

    mainLayout->setContentsMargins(0,0,0,0);


    //    mView->header()->hide();
    mView->setModel(mProxyModel);
    mView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);


    mSearchEdit->setVisible(false);


    setLayout(mainLayout);

    mCopyKeyAction = new QAction(tr("Copy key"), this);
    mCopyValueAction = new QAction(tr("Copy value"), this);

    addAction(mCopyKeyAction);
    addAction(mCopyValueAction);
    setContextMenuPolicy(Qt::ActionsContextMenu);



    //double click.. for link ... !
    connect(mView,SIGNAL(doubleClicked(QModelIndex)), this,SLOT(doubleClicked(QModelIndex)));
    connect(mSearchEdit,SIGNAL(textChanged(QString)),mProxyModel,SLOT(setFilterFixedString(QString)));
    connect(mCopyKeyAction,SIGNAL(triggered()),this,SLOT(copy()));
    connect(mCopyValueAction,SIGNAL(triggered()),this,SLOT(copy()));


}

JsonResponseWidget::~JsonResponseWidget()
{
    delete mView ;
    delete mJsonModel;
    delete mSearchEdit;
    delete mProxyModel ;
}


void JsonResponseWidget::doubleClicked(const QModelIndex &index)
{
    // This methods allow to send new request from endpoint clicked from view..
//    // That's mean all url "http://" and relative url..

//    QString path = mJsonModel->index(mProxyModel->mapToSource(index).row(),1, mProxyModel->mapToSource(index).parent()).data().toString();
//    QRegularExpression regExp("^(https?://)?[\da-z\.-]+/");
//    if (path.contains(regExp)){

//        Request request = response().request();
//        qDebug()<<response().request().verb();

//        if (path.contains(QRegularExpression("^https?://")))
//            request.setUrl(QUrl(path));
//        else
//        {
//            QUrl url;
//            url.setAuthority(request.url().authority());
//            url.setPath(path);
//            request.setUrl(url);
//        }

//        emit requestTrigger(request);
//    }
}


void JsonResponseWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->matches(QKeySequence::Find)){
        mSearchEdit->setVisible(!mSearchEdit->isVisible());

        if (mSearchEdit->isVisible()){
            mSearchEdit->setFocus();
            mView->expandAll();

        }
        else{
            setFocus();
            mProxyModel->setFilterFixedString(QString());
            mView->collapseAll();
        }
    }




}

void JsonResponseWidget::setResponse(const Response &rep)
{
    mJsonModel->clear();
    if (mJsonModel->loadJson(rep.body()))
    {
        mView->setModel(mJsonModel);
        setEnabled(true);
    }
    else
        setEnabled(false);
}

void JsonResponseWidget::copy()
{
    if (mView->selectionModel()->selectedRows().count() > 0) {
        QString tmp;

        if (sender() == mCopyKeyAction)
            tmp = mView->selectionModel()->selectedRows(0).first().data().toString();

        if (sender() == mCopyValueAction)
            tmp = mView->selectionModel()->selectedRows(1).first().data().toString();

        qDebug()<<tmp;
        qApp->clipboard()->setText(tmp);


    }


}



