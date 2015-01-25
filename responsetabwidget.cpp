#include "responsetabwidget.h"
#include "textresponsewidget.h"
#include "jsonresponsewidget.h"
#include "inforesponsewidget.h"
ResponseTabWidget::ResponseTabWidget(QWidget * parent)
    :QTabWidget(parent)
{

    addResponseWidget(new TextResponseWidget());
    addResponseWidget(new JsonResponseWidget());
    addResponseWidget(new InfoResponseWidget());


}

ResponseTabWidget::~ResponseTabWidget()
{

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

