#include "xmlresponsewidget.h"
#include <QVBoxLayout>
XmlResponseWidget::XmlResponseWidget(QWidget * parent )
    :AbstractResponseWidget(parent)
{

    mView = new QTreeView;
    mModel = new DomModel();
    mView->setModel(mModel);
    setWidget(mView);

    mView->header()->setSectionResizeMode(QHeaderView::Interactive);

    setWindowTitle("Xml");

    mCopyNameAction = new QAction(tr("Copy name"),this);
    mCopyAttributeAction = new QAction(tr("Copy attributes"),this);
    mCopyValueAction = new QAction(tr("Copy value"),this);

    addAction(mCopyNameAction);
    addAction(mCopyAttributeAction);
    addAction(mCopyValueAction);

    setContextMenuPolicy(Qt::ActionsContextMenu);

    connect(mCopyNameAction, SIGNAL(triggered()),this,SLOT(copy()));
    connect(mCopyAttributeAction, SIGNAL(triggered()),this,SLOT(copy()));
    connect(mCopyValueAction, SIGNAL(triggered()),this,SLOT(copy()));



}

XmlResponseWidget::~XmlResponseWidget()
{

}

void XmlResponseWidget::setResponse(const Response &rep)
{
    qDebug()<<"set DOM TREE";
    mModel->loadXml(rep.body());





}

void XmlResponseWidget::copy()
{


    if (mView->selectionModel()->selectedRows().count() > 0) {

        QString tmp;

        if (sender() == mCopyNameAction)
            tmp = mView->selectionModel()->selectedRows(0).first().data().toString();

        if (sender() == mCopyAttributeAction)
            tmp = mView->selectionModel()->selectedRows(1).first().data().toString();


        if (sender() == mCopyValueAction)
            tmp = mView->selectionModel()->selectedRows(2).first().data().toString();

        qApp->clipboard()->setText(tmp);




    }





}

