#include "inforesponsewidget.h"

InfoResponseWidget::InfoResponseWidget(QWidget * widget)
    :AbstractResponseWidget(widget)
{
    setWindowTitle("Info");
    mTableWidget = new QTreeWidget;
    setWidget(mTableWidget);

    mTableWidget->setColumnCount(2);
    mTableWidget->setAlternatingRowColors(true);

    mTableWidget->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    mTableWidget->setHeaderLabels(QStringList()<<"Key"<<"Value");

}

InfoResponseWidget::~InfoResponseWidget()
{



}

void InfoResponseWidget::setResponse(const Response &rep)
{

    mTableWidget->clear();
    foreach (QNetworkReply::RawHeaderPair pair ,rep.rawHeaderPairs())
    {

        QTreeWidgetItem * item = new QTreeWidgetItem();

        item->setText(0, pair.first);
        item->setText(1,pair.second);
        item->setFlags(Qt::ItemIsEditable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);

        mTableWidget->addTopLevelItem(item);


    }





}

