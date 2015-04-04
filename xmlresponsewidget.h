#ifndef DOMRESPONSEWIDGET_H
#define DOMRESPONSEWIDGET_H

#include <QWidget>
#include <QDomDocument>
#include "abstractresponsewidget.h"
#include "dommodel.h"
#include "findbarwidget.h"

class XmlResponseWidget : public AbstractResponseWidget
{
    Q_OBJECT
public:
    XmlResponseWidget(QWidget * parent = 0);
    ~XmlResponseWidget();
    void setResponse(const Response& rep);

protected slots:
    void copyKey();
    void copyAttribut();
    void copyValue();
    void showSearch(bool visible);


private:
    QDomDocument mDoc;
    DomModel * mModel;
    QTreeView * mView;
    QToolBar * mToolBar;
    QAction * mCopyNameAction;
    QAction * mCopyAttributeAction;
    QAction * mCopyValueAction;
    FindBarWidget * mSearchEdit;




};

#endif // DOMRESPONSEWIDGET_H
