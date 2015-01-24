#ifndef TEXTRESPONSEWIDGET_H
#define TEXTRESPONSEWIDGET_H
#include "abstractresponsewidget.h"
#include <QTextEdit>

class TextResponseWidget : public AbstractResponseWidget
{
public:
    TextResponseWidget(QWidget * parent=0);
    ~TextResponseWidget();

private:
    QTextEdit * mEdit;
};

#endif // TEXTRESPONSEWIDGET_H
