#include "textresponsewidget.h"

TextResponseWidget::TextResponseWidget(QWidget * parent)
    :AbstractResponseWidget(parent)
{

    setWindowTitle("Text");

    mEdit = new QTextEdit;
    mEdit->setAcceptRichText(true);
    setWidget(mEdit);



mHighlighter = new JsonSyntaxHighlighter(mEdit->document());








}

TextResponseWidget::~TextResponseWidget()
{

}

