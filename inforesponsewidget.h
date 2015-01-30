#ifndef INFORESPONSEWIDGET_H
#define INFORESPONSEWIDGET_H
#include "abstractresponsewidget.h"
#include <QTableWidget>
class InfoResponseWidget : public AbstractResponseWidget
{
public:
    InfoResponseWidget(QWidget *parent = 0);
    ~InfoResponseWidget();

    virtual void setResponse(const Response& rep);


private:
    QTreeWidget * mTableWidget;

};

#endif // INFORESPONSEWIDGET_H
