#include "xmlresponsewidget.h"
#include <QVBoxLayout>
#include "QtAwesome/QtAwesome.h"
XmlResponseWidget::XmlResponseWidget(QWidget * parent )
    :AbstractResponseWidget(parent)
{

    mView = new QTreeView;
    mModel = new DomModel();
    mToolBar = new QToolBar;
    mSearchEdit = new FindBarWidget;
    mView->setModel(mModel);



    mToolBar->setIconSize(QSize(16,16));
    mToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);


    QAction * expandAction   = mToolBar->addAction(QtAwesome::instance()->icon(0xf067),tr("Expand all"));
    QAction * collapseAction = mToolBar->addAction(QtAwesome::instance()->icon(0xf068),tr("Expand all"));

    QWidget* spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mToolBar->addWidget(spacer);

    QAction * searchAction = mToolBar->addAction(QtAwesome::instance()->icon(0xf002),tr("Search"));
    QAction * copyKeyAction = mToolBar->addAction(QtAwesome::instance()->icon(0xf0ea),tr("Copy key"));
    QAction * copyAttributAction = mToolBar->addAction(QtAwesome::instance()->icon(0xf0ea),tr("Copy attribut"));
    QAction * copyValueAction = mToolBar->addAction(QtAwesome::instance()->icon(0xf0ea),tr("Copy value"));

    searchAction->setShortcut(QKeySequence("Ctrl+F"));

    searchAction->setCheckable(true);

    QWidget * mainWidget = new QWidget;
    QVBoxLayout * vLayout = new QVBoxLayout;

    vLayout->addWidget(mToolBar);
    vLayout->addWidget(mView);
    vLayout->addWidget(mSearchEdit);

    mSearchEdit->hide();
    vLayout->setSpacing(0);
    vLayout->setContentsMargins(0,0,0,0);
    mainWidget->setLayout(vLayout);
    setWidget(mainWidget);

    mView->header()->setSectionResizeMode(QHeaderView::Interactive);

    setWindowTitle("Xml");

    mCopyNameAction = new QAction(tr("Copy name"),this);
    mCopyAttributeAction = new QAction(tr("Copy attributes"),this);
    mCopyValueAction = new QAction(tr("Copy value"),this);

    addAction(mCopyNameAction);
    addAction(mCopyAttributeAction);
    addAction(mCopyValueAction);

    setContextMenuPolicy(Qt::ActionsContextMenu);

    connect(copyKeyAction, SIGNAL(triggered()),this,SLOT(copyKey()));
    connect(copyAttributAction, SIGNAL(triggered()),this,SLOT(copyAttribut()));
    connect(copyValueAction, SIGNAL(triggered()),this,SLOT(copyValue()));
    connect(searchAction,SIGNAL(triggered(bool)),this,SLOT(showSearch(bool)));
    connect(collapseAction,SIGNAL(triggered()),mView,SLOT(collapseAll()));
    connect(expandAction,SIGNAL(triggered()),mView,SLOT(expandAll()));


}

XmlResponseWidget::~XmlResponseWidget()
{

}

void XmlResponseWidget::setResponse(const Response &rep)
{
    qDebug()<<"set DOM TREE";
    mModel->loadXml(rep.body());

}

void XmlResponseWidget::copyKey()
{
    QString tmp = mView->selectionModel()->selectedRows(0).first().data().toString();
    qApp->clipboard()->setText(tmp);

}

void XmlResponseWidget::copyAttribut()
{
    QString tmp = mView->selectionModel()->selectedRows(1).first().data().toString();
    qApp->clipboard()->setText(tmp);
}

void XmlResponseWidget::copyValue()
{
    QString tmp = mView->selectionModel()->selectedRows(2).first().data().toString();
    qApp->clipboard()->setText(tmp);
}

void XmlResponseWidget::showSearch(bool visible)
{
    mSearchEdit->setVisible(visible);
}



