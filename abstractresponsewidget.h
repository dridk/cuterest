#ifndef ABSTRACTRESPONSEWIDGET_H
#define ABSTRACTRESPONSEWIDGET_H

#include <QtWidgets>
#include "response.h"
class AbstractResponseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractResponseWidget(QWidget *parent = 0);
    ~AbstractResponseWidget();

    void setWidget(QWidget * widget);
    const Response &response() const;

public slots:
    virtual void setResponse(const Response& rep) = 0;



private:
    Response mRep;

};

#endif // ABSTRACTRESPONSEWIDGET_H
