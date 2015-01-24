#ifndef RESPONSETABWIDGET_H
#define RESPONSETABWIDGET_H
#include <QTabWidget>
#include "abstractresponsewidget.h"
class ResponseTabWidget : public QTabWidget
{
public:
    ResponseTabWidget(QWidget * parent =0);
    ~ResponseTabWidget();

    void addResponseWidget(AbstractResponseWidget * widget);


private:

};

#endif // RESPONSETABWIDGET_H
