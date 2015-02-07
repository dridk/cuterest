#include "webresponsewidget.h"

WebResponseWidget::WebResponseWidget(QWidget * parent)
    :AbstractResponseWidget(parent)
{
    mWebView = new QWebView;
    setWidget(mWebView);

    setWindowTitle("Web");
}

WebResponseWidget::~WebResponseWidget()
{

}

void WebResponseWidget::setResponse(const Response &rep)
{
    mWebView->setHtml("<html></html>");
    mWebView->setHtml(rep.body());

}

