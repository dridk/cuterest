#include "jsonresponsewidget.h"

JsonResponseWidget::JsonResponseWidget(QWidget * parent)
    :AbstractResponseWidget(parent)
{
    setWindowTitle("Tree");

    mView = new QTreeView;
    mModel = new QJsonModel;
    mSearchEdit = new QLineEdit;

    QVBoxLayout * mainLayout = new QVBoxLayout;

    mainLayout->addWidget(mView);
    mainLayout->addWidget(mSearchEdit);

    mainLayout->setContentsMargins(0,0,0,0);

    //For stylesheet
    mView->setObjectName("Json");
    mView->header()->hide();
    mView->setModel(mModel);
    mView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);


    mSearchEdit->setVisible(false);

    mModel->load("/home/sacha/test.json");

    setLayout(mainLayout);
}

JsonResponseWidget::~JsonResponseWidget()
{

}

void JsonResponseWidget::keyPressEvent(QKeyEvent *event)
{
   if (event->matches(QKeySequence::Find)){
       mSearchEdit->setVisible(!mSearchEdit->isVisible());

       if (mSearchEdit->isVisible())
           mSearchEdit->setFocus();
       else
           setFocus();
   }



}

void JsonResponseWidget::setResponse(const Response &rep)
{

    mModel->loadJson(rep.body());


}

