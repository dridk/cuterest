#ifndef JSONRESPONSEWIDGET_H
#define JSONRESPONSEWIDGET_H

#include <QtWidgets>
#include <QKeyEvent>
#include "qjsonmodel.h"
#include "abstractresponsewidget.h"

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

protected:
    void createActions();

private:
    QTreeView * mView;
    QJsonModel * mModel;
    QLineEdit * mSearchEdit;
};

#endif // JSONRESPONSEWIDGET_H
