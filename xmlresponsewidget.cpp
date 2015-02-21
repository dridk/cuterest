#include "xmlresponsewidget.h"
#include <QVBoxLayout>
XmlResponseWidget::XmlResponseWidget(QWidget * parent )
    :AbstractResponseWidget(parent)
{

    mView = new QTreeView;
    mModel = new DomModel();
    mView->setModel(mModel);
    setWidget(mView);


    setWindowTitle("Xml");

}

XmlResponseWidget::~XmlResponseWidget()
{

}

void XmlResponseWidget::setResponse(const Response &rep)
{

    qDebug()<<"set DOM TREE";

    mModel->loadXml(rep.body());



}

