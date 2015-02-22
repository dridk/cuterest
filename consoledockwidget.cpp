#include "consoledockwidget.h"

ConsoleDockWidget::ConsoleDockWidget(QWidget * parent)
    :QDockWidget(parent)
{
    setWindowTitle("Console");
    setFeatures(QDockWidget::NoDockWidgetFeatures);

    mTextEdit = new QPlainTextEdit;
    mTextEdit->setReadOnly(true);

    setWidget(mTextEdit);
}

ConsoleDockWidget::~ConsoleDockWidget()
{

}

void ConsoleDockWidget::append(const Response &rep)
{

    mTextEdit->appendPlainText(">>Response");
    mTextEdit->appendPlainText(rep.body());




}

void ConsoleDockWidget::append(const Request &req)
{

mTextEdit->appendPlainText("<<Request");
mTextEdit->appendPlainText(req.url().toString());






}

