#ifndef JSONRESPONSEWIDGET_H
#define JSONRESPONSEWIDGET_H

#include <QtWidgets>
#include <QKeyEvent>
#include "qjsonmodel.h"
#include "abstractresponsewidget.h"

class JsonResponseWidget : public AbstractResponseWidget
{
public:
    JsonResponseWidget(QWidget * parent = 0);
    ~JsonResponseWidget();

    void keyPressEvent(QKeyEvent *event);

public slots:
    void setResponse(const Response& rep);

private:
    QTreeView * mView;
    QJsonModel * mModel;
    QLineEdit * mSearchEdit;
};

#endif // JSONRESPONSEWIDGET_H
