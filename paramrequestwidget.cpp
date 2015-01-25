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
    QPair<QString, QString> q;

    foreach (q, request.query().queryItems()) {
       mEditor->insert(q.first,q.second);
    }


}

void ParamRequestWidget::save(Request &request)
{
    QUrlQuery query;

    for (int row=0; row < mEditor->count(); row++)
        query.addQueryItem(mEditor->key(row), mEditor->value(row).toString());


    request.setQuery(query);


}

