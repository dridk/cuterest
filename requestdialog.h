#ifndef REQUESTDIALOG_H
#define REQUESTDIALOG_H
#include <QDialog>
#include <QtWidgets>
#include "abstractrequestwidget.h"
#include "headerrequestwidget.h"
#include "paramrequestwidget.h"
#include "verbcombobox.h"
#include "request.h"
class RequestDialog : public QDialog
{
    Q_OBJECT
public:
    RequestDialog(const Request& request, QWidget * parent = 0);
    ~RequestDialog();
    void addRequestWidget(AbstractRequestWidget * widget);



    const Request& request() const;
    void setRequest(const Request &request);

protected slots:
    void save();
    void load();

private:
    QTabWidget * mTabWidget;
    QDialogButtonBox * mButtonBox;
    QList<AbstractRequestWidget*> mWidgets;
    Request mRequest;

};

#endif // REQUESTDIALOG_H
