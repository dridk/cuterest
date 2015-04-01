#ifndef JSONRESPONSEWIDGET_H
#define JSONRESPONSEWIDGET_H

#include <QtWidgets>
#include <QKeyEvent>
#include <QDomDocument>
#include "treesortfilterproxymodel.h"
#include "qjsonmodel.h"
#include "dommodel.h"
#include "abstractresponsewidget.h"
#include "request.h"
#include "findbarwidget.h"
#include "jsonitemdelegate.h"
class JsonResponseWidget : public AbstractResponseWidget
{
    Q_OBJECT
public:
    JsonResponseWidget(QWidget * parent = 0);
    ~JsonResponseWidget();

    void keyPressEvent(QKeyEvent *event);

public slots:
    void setResponse(const Response& rep);
    void copy();

protected slots:
    void doubleClicked(const QModelIndex& index);

protected:
   // void contextMenuEvent(QContextMenuEvent * event);


signals:
    void requestTrigger(const Request& request);
private:
    QTreeView * mView;
    QJsonModel * mJsonModel;
    TreeSortFilterProxyModel * mProxyModel;
    FindBarWidget * mSearchEdit;
    JsonItemDelegate * mDelegate;
    QStringList mDomType;
    QStringList mJsonType;
    QAction * mCopyKeyAction;
    QAction * mCopyValueAction;
    Response mCurrentResponse;
};

#endif // JSONRESPONSEWIDGET_H
