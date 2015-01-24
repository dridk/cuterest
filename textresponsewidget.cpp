#include "textresponsewidget.h"

TextResponseWidget::TextResponseWidget(QWidget * parent)
    :AbstractResponseWidget(parent)
{

    setWindowTitle("Text");

    mEdit = new QTextEdit;
    mEdit->setAcceptRichText(true);
    mEdit->setReadOnly(true);
    setWidget(mEdit);



mHighlighter = new JsonSyntaxHighlighter(mEdit->document());








}

TextResponseWidget::~TextResponseWidget()
{

}

void TextResponseWidget::setResponse(const Response &rep)
{

    mEdit->setText(rep.body());


}

