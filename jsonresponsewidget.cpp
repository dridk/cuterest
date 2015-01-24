#include "jsonresponsewidget.h"

JsonResponseWidget::JsonResponseWidget(QWidget * parent)
    :AbstractResponseWidget(parent)
{
    setWindowTitle("Tree");

    mView = new QTreeView;
    mModel = new QJsonModel;
    mView->setModel(mModel);
    mView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);



    mModel->load("/home/sacha/test.json");

    setWidget(mView);
}

JsonResponseWidget::~JsonResponseWidget()
{

}

void JsonResponseWidget::setResponse(const Response &rep)
{

    mModel->loadJson(rep.body());


}

