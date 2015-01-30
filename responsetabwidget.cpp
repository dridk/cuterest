#include "responsetabwidget.h"
#include "textresponsewidget.h"
#include "jsonresponsewidget.h"
#include "inforesponsewidget.h"
#include "webresponsewidget.h"
ResponseTabWidget::ResponseTabWidget(QWidget * parent)
    :QTabWidget(parent)
{

    TextResponseWidget* textWidget = new TextResponseWidget();
    JsonResponseWidget* jsonWidget = new JsonResponseWidget();
    InfoResponseWidget *infoWidget = new InfoResponseWidget();
    WebResponseWidget * webWidget  = new WebResponseWidget();

    addResponseWidget(textWidget);
    addResponseWidget(jsonWidget);
    addResponseWidget(infoWidget);
    addResponseWidget(webWidget);

    connect(jsonWidget,SIGNAL(requestTrigger(Request)),this,SIGNAL(requestTrigger(Request)));



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



}

