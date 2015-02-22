#ifndef TEXTRESPONSEWIDGET_H
#define TEXTRESPONSEWIDGET_H
#include "abstractresponsewidget.h"
#include <QTextEdit>
#include "jsonsyntaxhighlighter.h"
#include "xmlsyntaxhighlighter.h"
class TextResponseWidget : public AbstractResponseWidget
{
public:
    TextResponseWidget(QWidget * parent=0);
    ~TextResponseWidget();

public slots:
    void setResponse(const Response& rep);




private:
    QTextEdit * mEdit;
    QSyntaxHighlighter * mHighlighter;
};

#endif // TEXTRESPONSEWIDGET_H
