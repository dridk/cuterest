#ifndef HEADERREQUESTWIDGET_H
#define HEADERREQUESTWIDGET_H
#include <QWidget>
#include <QtWidgets>
#include "abstractrequestwidget.h"
#include "dicteditorwidget.h"
class HeaderRequestWidget : public AbstractRequestWidget
{
    Q_OBJECT
public:
    explicit HeaderRequestWidget(QWidget *parent = 0);
    ~HeaderRequestWidget();

    virtual void load(Request& request);
    virtual void save(Request& request) ;
    virtual void reset();

private:
    DictEditorWidget * mEditor;

};

#endif // HEADERREQUESTWIDGET_H
