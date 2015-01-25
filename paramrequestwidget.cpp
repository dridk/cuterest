#include "paramrequestwidget.h"

ParamRequestWidget::ParamRequestWidget(QWidget * parent)
    :AbstractRequestWidget(parent)
{
    mEditor= new DictEditorWidget;

    QVBoxLayout * mainLayout = new QVBoxLayout;
    mainLayout->addWidget(mEditor);

    setLayout(mainLayout);
    setWindowTitle("Parameters");

}

ParamRequestWidget::~ParamRequestWidget()
{
    delete mEditor;
}

void ParamRequestWidget::load(Request &request)
{
    mEditor->clear();

    foreach (QString key, request.params().keys()) {
       mEditor->insert(key, request.param(key));
    }


}

void ParamRequestWidget::save(Request &request)
{
    for (int row=0; row < mEditor->count(); row++)
       request.insertParam(mEditor->key(row), mEditor->value(row));
}

