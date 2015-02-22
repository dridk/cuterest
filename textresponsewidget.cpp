#include "textresponsewidget.h"

TextResponseWidget::TextResponseWidget(QWidget * parent)
    :AbstractResponseWidget(parent)
{

    setWindowTitle("Raw");

    mEdit = new QTextEdit;
    mEdit->setAcceptRichText(false);
    mEdit->setReadOnly(false);
    setWidget(mEdit);



mHighlighter = new JsonSyntaxHighlighter(mEdit->document());





}

TextResponseWidget::~TextResponseWidget()
{

}

void TextResponseWidget::setResponse(const Response &rep)
{
    mEdit->clear();
    mEdit->setPlainText(rep.body());


}

