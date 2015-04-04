#ifndef INFORESPONSEWIDGET_H
#define INFORESPONSEWIDGET_H
#include "abstractresponsewidget.h"
#include <QTableWidget>
class InfoResponseWidget : public AbstractResponseWidget
{
    Q_OBJECT
public:
    InfoResponseWidget(QWidget *parent = 0);
    ~InfoResponseWidget();

    virtual void setResponse(const Response& rep);

protected slots:
    void setListFromIndex(const QModelIndex& index);

private:
    QTreeWidget * mTableWidget;
    QListView * mListView;
    QStringListModel * mListModel;

};

#endif // INFORESPONSEWIDGET_H
