#include "consoledockwidget.h"

ConsoleDockWidget::ConsoleDockWidget(QWidget * parent)
    :QDockWidget(parent)
{
    setWindowTitle("Console");
    setFeatures(QDockWidget::NoDockWidgetFeatures);

    mTextEdit = new QTextEdit;

    setWidget(mTextEdit);
}

ConsoleDockWidget::~ConsoleDockWidget()
{

}

