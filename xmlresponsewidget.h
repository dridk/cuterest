#ifndef DOMRESPONSEWIDGET_H
#define DOMRESPONSEWIDGET_H

#include <QWidget>
#include <QDomDocument>
#include "abstractresponsewidget.h"
#include "dommodel.h"

class XmlResponseWidget : public AbstractResponseWidget
{
    Q_OBJECT
public:
    XmlResponseWidget(QWidget * parent = 0);
    ~XmlResponseWidget();
    void setResponse(const Response& rep);

private:
    QDomDocument mDoc;
    DomModel * mModel;
    QTreeView * mView;


};

#endif // DOMRESPONSEWIDGET_H
