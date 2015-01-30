#include "jsonresponsewidget.h"
#include <QClipboard>
#include <QApplication>
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

    createActions();

}

JsonResponseWidget::~JsonResponseWidget()
{

}
void JsonResponseWidget::createActions()
{
    setContextMenuPolicy(Qt::ActionsContextMenu);
    QAction* copyAction = new QAction(tr("Copy"),this);
    connect(copyAction,SIGNAL(triggered()),this,SLOT(copy()));
    addAction(copyAction);

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

void JsonResponseWidget::copy()
{
    if (mView->selectionModel()->selectedRows().count() > 0) {
        int row = mView->currentIndex().row();

        QString value = mModel->index(row,1,mView->currentIndex().parent()).data().toString();        
        qApp->clipboard()->setText(value);


    }


}

