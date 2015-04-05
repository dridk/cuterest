#ifndef ABSTRACTREQUESTWIDGET_H
#define ABSTRACTREQUESTWIDGET_H

#include <QWidget>
#include "request.h"
class AbstractRequestWidget : public QWidget
{
public:
    AbstractRequestWidget(QWidget * parent = 0);
    ~AbstractRequestWidget();


    virtual void load(Request& request) = 0;
    virtual void save(Request& request) = 0;
    virtual void reset() = 0;




};

#endif // ABSTRACTREQUESTWIDGET_H
