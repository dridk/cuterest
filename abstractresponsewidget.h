#ifndef ABSTRACTRESPONSEWIDGET_H
#define ABSTRACTRESPONSEWIDGET_H

#include <QtWidgets>
class AbstractResponseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractResponseWidget(QWidget *parent = 0);
    ~AbstractResponseWidget();

    void setWidget(QWidget * widget);


};

#endif // ABSTRACTRESPONSEWIDGET_H
