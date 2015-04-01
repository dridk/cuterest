#include "responsetabwidget.h"
ResponseTabWidget::ResponseTabWidget(QWidget * parent)
    :QTabWidget(parent)
{

    mTextWidget = new TextResponseWidget();
    mJsonWidget = new JsonResponseWidget();
    mInfoWidget = new InfoResponseWidget();
    mWebWidget  = new WebResponseWidget();
    mXmlWidget  = new XmlResponseWidget();

    addResponseWidget(mTextWidget);
    addResponseWidget(mJsonWidget);
    addResponseWidget(mXmlWidget);
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

//    setCurrentWidget(widgetFromType(rep.rawHeader("Content-Type")));



}

void ResponseTabWidget::nextTab()
{
    setCurrentIndex(currentIndex() == count()-1 ? 0 : currentIndex()+1);
}

void ResponseTabWidget::previousTab()
{
    setCurrentIndex(currentIndex() == 0 ? count()-1 : currentIndex()-1);

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

