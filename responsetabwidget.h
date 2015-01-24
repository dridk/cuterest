#ifndef RESPONSETABWIDGET_H
#define RESPONSETABWIDGET_H
#include <QTabWidget>
#include "abstractresponsewidget.h"
#include "response.h"
class ResponseTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    ResponseTabWidget(QWidget * parent =0);
    ~ResponseTabWidget();

    void addResponseWidget(AbstractResponseWidget * widget);

public slots:
    void setResponse(const Response& rep);


private:
    QList<AbstractResponseWidget*> mList;

};

#endif // RESPONSETABWIDGET_H
