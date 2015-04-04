#include "inforesponsewidget.h"

InfoResponseWidget::InfoResponseWidget(QWidget * widget)
    :AbstractResponseWidget(widget)
{
    setWindowTitle("Info");
    mTableWidget = new QTreeWidget;
//    mListView    = new QListView;
//    mListModel   = new QStringListModel;

//    mListView->setModel(mListModel);


//    QSplitter * splitter = new QSplitter(Qt::Horizontal);

//    splitter->addWidget(mTableWidget);
//    splitter->addWidget(mListView);


    setWidget(mTableWidget);

    mTableWidget->setColumnCount(2);
    mTableWidget->setAlternatingRowColors(false);

    mTableWidget->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    mTableWidget->setHeaderLabels(QStringList()<<"Key"<<"Value");

//    connect(mTableWidget,SIGNAL(activated(QModelIndex)),this,SLOT(setListFromIndex(QModelIndex)));

}

InfoResponseWidget::~InfoResponseWidget()
{



}

void InfoResponseWidget::setResponse(const Response &rep)
{

    mTableWidget->clear();
    mTableWidget->setIndentation(0);
    foreach (QNetworkReply::RawHeaderPair pair ,rep.rawHeaderPairs())
    {

        QTreeWidgetItem * item = new QTreeWidgetItem();
        item->setText(0, pair.first);
        item->setBackgroundColor(0, QColor("#f7f7f7"));
        item->setText(1,pair.second);
        item->setFlags(Qt::ItemIsEditable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);

        mTableWidget->addTopLevelItem(item);
    }
}

void InfoResponseWidget::setListFromIndex(const QModelIndex &index)
{
//    QString value = mTableWidget->currentItem()->text(1);

//    if (value.contains(";"))
//    {
//        QStringList list = value.split(";");
//        qDebug()<<list;
//        mListModel->setStringList(list);
//    }




}

