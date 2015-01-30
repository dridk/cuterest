#ifndef WEBRESPONSEWIDGET_H
#define WEBRESPONSEWIDGET_H

#include <QWidget>
#include <QWebView>
#include "abstractresponsewidget.h"

class WebResponseWidget : public AbstractResponseWidget
{
    Q_OBJECT
public:
    WebResponseWidget(QWidget * parent=0);
    ~WebResponseWidget();

public slots:
    virtual void setResponse(const Response& rep) ;

private:
    QWebView * mWebView;

};

#endif // WEBRESPONSEWIDGET_H
