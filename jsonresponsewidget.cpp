#include "jsonresponsewidget.h"
#include <QClipboard>
#include <QRegularExpression>
#include <QApplication>
#include "QtAwesome/QtAwesome.h"
#include "urldetect.h"
JsonResponseWidget::JsonResponseWidget(QWidget * parent)
    :AbstractResponseWidget(parent)
{
    setWindowTitle("Json");

    mView = new QTreeView;
    mDelegate = new JsonItemDelegate;
    mJsonModel = new QJsonModel;
    mSearchEdit = new FindBarWidget;
    mProxyModel = new TreeSortFilterProxyModel;
    mToolBar = new QToolBar;


    mToolBar->setIconSize(QSize(16,16));
    mToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QAction * expandAction   = mToolBar->addAction(QtAwesome::instance()->icon(0xf067),tr("Expand all"));
    QAction * collapseAction = mToolBar->addAction(QtAwesome::instance()->icon(0xf068),tr("Expand all"));

    QWidget* spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mToolBar->addWidget(spacer);

    QAction * searchAction = mToolBar->addAction(QtAwesome::instance()->icon(0xf002),tr("Search"));
    QAction * copyKeyAction = mToolBar->addAction(QtAwesome::instance()->icon(0xf0ea),tr("Copy key"));
    QAction * copyValueAction = mToolBar->addAction(QtAwesome::instance()->icon(0xf0ea),tr("Copy value"));

    searchAction->setShortcut(QKeySequence("Ctrl+F"));
    searchAction->setCheckable(true);

    QVBoxLayout * mainLayout = new QVBoxLayout;

    mainLayout->addWidget(mToolBar);
    mainLayout->addWidget(mView);
    mainLayout->addWidget(mSearchEdit);

    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);


    //    mView->header()->hide();
    mView->setModel(mProxyModel);
    mView->setItemDelegate(mDelegate);
    //    mView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);


    mSearchEdit->setVisible(false);


    setLayout(mainLayout);




    //double click.. for link ... !
    connect(mView,SIGNAL(doubleClicked(QModelIndex)), this,SLOT(doubleClicked(QModelIndex)));
    connect(mSearchEdit,SIGNAL(textChanged(QString)),mProxyModel,SLOT(setFilterFixedString(QString)));
    connect(copyKeyAction,SIGNAL(triggered()),this,SLOT(copyKey()));
    connect(copyValueAction,SIGNAL(triggered()),this,SLOT(copyValue()));
    connect(searchAction,SIGNAL(triggered(bool)),this,SLOT(showSearch(bool)));
    connect(expandAction,SIGNAL(triggered()),mView,SLOT(expandAll()));
    connect(collapseAction,SIGNAL(triggered()),mView,SLOT(collapseAll()));

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

    qDebug()<<index.row();
    qDebug()<<index.column();
    qDebug()<<index.parent();
    qDebug()<<index.model();

    QModelIndex selectedIndex  = mJsonModel->index(index.row(),1, index.parent());

    if (selectedIndex.isValid())
    {
        //Get the selected string
        QString value = selectedIndex.data().toString();

        if (UrlDetect::isValid(value)) {
            // Create a copy of the actual request
            Request request = mCurrentResponse.request();

            // Test if its a relative or absolute url
            if (value.contains(QRegularExpression("^(http|https)"))){
                request.setUrl(QUrl(value));

            }
            else {
                QUrl tempUrl = request.url();
                tempUrl.setPath(value);
                request.setUrl(tempUrl);
            }

            emit requestTrigger(request);

        }







    }

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
    mCurrentResponse = rep;
    mJsonModel->clear();
    if (mJsonModel->loadJson(rep.body()))
    {
        mView->setModel(mJsonModel);
        setEnabled(true);
    }
    else
        setEnabled(false);
}

void JsonResponseWidget::copyKey()
{
    QString tmp = mView->selectionModel()->selectedRows(0).first().data().toString();
    qApp->clipboard()->setText(tmp);

}

void JsonResponseWidget::copyValue()
{

    QString tmp = mView->selectionModel()->selectedRows(1).first().data().toString();
    qApp->clipboard()->setText(tmp);
}

void JsonResponseWidget::showSearch(bool visible)
{
    mSearchEdit->setVisible(visible);

}




