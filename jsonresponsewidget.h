#ifndef JSONRESPONSEWIDGET_H
#define JSONRESPONSEWIDGET_H

#include <QtWidgets>
#include <QKeyEvent>
#include "treesortfilterproxymodel.h"
#include "qjsonmodel.h"
#include "abstractresponsewidget.h"
#include "request.h"

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
    void createActions();
    void doubleClicked(const QModelIndex& index);


signals:
    void requestTrigger(const Request& request);
private:
    QTreeView * mView;
    QJsonModel * mModel;
    TreeSortFilterProxyModel * mProxyModel;
    QLineEdit * mSearchEdit;
};

#endif // JSONRESPONSEWIDGET_H
