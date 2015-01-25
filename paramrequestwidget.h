#ifndef PARAMREQUESTWIDGET_H
#define PARAMREQUESTWIDGET_H
#include <QtWidgets>
#include "abstractrequestwidget.h"
#include "dicteditorwidget.h"

class ParamRequestWidget : public AbstractRequestWidget
{
public:
    ParamRequestWidget(QWidget * parent = 0);
    ~ParamRequestWidget();


    virtual void load(Request& request);
    virtual void save(Request& request) ;


private:
    DictEditorWidget * mEditor;
};

#endif // PARAMREQUESTWIDGET_H
