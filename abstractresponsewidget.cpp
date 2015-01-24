#include "abstractresponsewidget.h"

AbstractResponseWidget::AbstractResponseWidget(QWidget *parent)
    : QWidget(parent)
{

}

AbstractResponseWidget::~AbstractResponseWidget()
{

}

void AbstractResponseWidget::setWidget(QWidget *widget)
{

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(widget);

    setLayout(layout);

    layout->setContentsMargins(0,0,0,0);

}

