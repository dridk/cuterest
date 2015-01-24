#ifndef TEXTRESPONSEWIDGET_H
#define TEXTRESPONSEWIDGET_H
#include "abstractresponsewidget.h"
#include <QTextEdit>
#include "jsonsyntaxhighlighter.h"

class TextResponseWidget : public AbstractResponseWidget
{
public:
    TextResponseWidget(QWidget * parent=0);
    ~TextResponseWidget();

private:
    QTextEdit * mEdit;
    JsonSyntaxHighlighter * mHighlighter;
};

#endif // TEXTRESPONSEWIDGET_H
