#ifndef RESPONSETABWIDGET_H
#define RESPONSETABWIDGET_H
#include <QTabWidget>
#include "abstractresponsewidget.h"
#include "response.h"
#include "responsetabwidget.h"
#include "textresponsewidget.h"
#include "jsonresponsewidget.h"
#include "inforesponsewidget.h"
#include "webresponsewidget.h"
#include "xmlresponsewidget.h"
class ResponseTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    ResponseTabWidget(QWidget * parent =0);
    ~ResponseTabWidget();

    void addResponseWidget(AbstractResponseWidget * widget);

public slots:
    void setResponse(const Response& rep);
    void nextTab();
    void previousTab();

signals:
    void requestTrigger(const Request& request);

protected:
    AbstractResponseWidget *widgetFromType(const QByteArray& array);


private:
    QList<AbstractResponseWidget*> mList;

    TextResponseWidget* mTextWidget ;
    JsonResponseWidget* mJsonWidget;
    InfoResponseWidget* mInfoWidget ;
    WebResponseWidget*  mWebWidget ;
    XmlResponseWidget * mXmlWidget;

};

#endif // RESPONSETABWIDGET_H
