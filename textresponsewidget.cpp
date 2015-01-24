#include "textresponsewidget.h"

TextResponseWidget::TextResponseWidget(QWidget * parent)
    :AbstractResponseWidget(parent)
{

    setWindowTitle("Text");

    mEdit = new QTextEdit;

    setWidget(mEdit);

}

TextResponseWidget::~TextResponseWidget()
{

}

