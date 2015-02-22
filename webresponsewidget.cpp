#include "webresponsewidget.h"
WebResponseWidget::WebResponseWidget(QWidget * parent)
    :AbstractResponseWidget(parent)
{
    mWebView = new QWebView;
    mTreeWidget = new QTreeWidget;

    QSplitter * splitter = new QSplitter(Qt::Horizontal);

    splitter->addWidget(mTreeWidget);
    splitter->addWidget(mWebView);
    setWidget(splitter);

    setWindowTitle("Web");

    connect(mTreeWidget,SIGNAL(clicked(QModelIndex)),this,SLOT(elementClicked(QModelIndex)));
}

WebResponseWidget::~WebResponseWidget()
{
    delete mWebView;
    delete mTreeWidget;
}

void WebResponseWidget::setResponse(const Response &rep)
{
    mWebView->setHtml("<html></html>");
    mWebView->setHtml(rep.body());

    mTreeWidget->clear();
    QWebElement document = mWebView->page()->mainFrame()->documentElement();
    examineChildElements(document, mTreeWidget->invisibleRootItem());
}

void WebResponseWidget::elementClicked(const QModelIndex &index)
{



}

void WebResponseWidget::examineChildElements(const QWebElement &parentElement,
                                             QTreeWidgetItem *parentItem)
{
    QWebElement element = parentElement.firstChild();
    while (!element.isNull()) {

        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText(0, element.tagName());


        parentItem->addChild(item);

        examineChildElements(element, item);

        element = element.nextSibling();
    }
}
