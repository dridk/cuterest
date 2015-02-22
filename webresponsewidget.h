#ifndef WEBRESPONSEWIDGET_H
#define WEBRESPONSEWIDGET_H

#include <QtWidgets>
#include <QWebView>
#include <QWebFrame>
#include <QWebElement>
#include "abstractresponsewidget.h"

class WebResponseWidget : public AbstractResponseWidget
{
    Q_OBJECT
public:
    WebResponseWidget(QWidget * parent=0);
    ~WebResponseWidget();

  protected:
    void examineChildElements(const QWebElement &parentElement,
                                      QTreeWidgetItem *parentItem);

public slots:
    virtual void setResponse(const Response& rep) ;
    void elementClicked(const QModelIndex& index);




private:
    QWebView * mWebView;
    QTreeWidget * mTreeWidget;

};

#endif // WEBRESPONSEWIDGET_H
