#include "responsetabwidget.h"
ResponseTabWidget::ResponseTabWidget(QWidget * parent)
    :QTabWidget(parent)
{

    mTextWidget = new TextResponseWidget();
    mJsonWidget = new TreeResponseWidget();
    mInfoWidget = new InfoResponseWidget();
    mWebWidget  = new WebResponseWidget();
    mDomWidget  = new XmlResponseWidget();

    addResponseWidget(mTextWidget);
    addResponseWidget(mJsonWidget);
    addResponseWidget(mDomWidget);
    addResponseWidget(mInfoWidget);
    addResponseWidget(mWebWidget);

    connect(mJsonWidget,SIGNAL(requestTrigger(Request)),this,SIGNAL(requestTrigger(Request)));

    setObjectName("response");

}

ResponseTabWidget::~ResponseTabWidget()
{
    qDeleteAll(mList);
}

void ResponseTabWidget::addResponseWidget(AbstractResponseWidget *widget)
{



    addTab(widget, widget->windowTitle());
    mList.append(widget);



}

void ResponseTabWidget::setResponse(const Response &rep)
{

    foreach (AbstractResponseWidget * w, mList) {
        w->setResponse(rep);

    }

    setCurrentWidget(widgetFromType(rep.rawHeader("Content-Type")));



}

AbstractResponseWidget *ResponseTabWidget::widgetFromType(const QByteArray &array)
{
    AbstractResponseWidget * w = mTextWidget;

    if (array.contains("html"))
        w = mWebWidget;
    if (array.contains("json"))
        w = mJsonWidget;

    return w;





}

