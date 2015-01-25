#ifndef INFORESPONSEWIDGET_H
#define INFORESPONSEWIDGET_H
#include "abstractresponsewidget.h"

class InfoResponseWidget : public AbstractResponseWidget
{
public:
    InfoResponseWidget(QWidget *parent = 0);
    ~InfoResponseWidget();

    virtual void setResponse(const Response& rep);

};

#endif // INFORESPONSEWIDGET_H
