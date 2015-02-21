#ifndef HISTORYDOCKWIDGET_H
#define HISTORYDOCKWIDGET_H
#include <QDockWidget>
#include <QtWidgets>
#include "historymodel.h"
#include "response.h"
class HistoryDockWidget : public QDockWidget
{
    Q_OBJECT
public:
    HistoryDockWidget(QWidget * parent = 0);
    ~HistoryDockWidget();

public slots:
    void append(const Response& rep);
    void setBack();
    void setForward();
    void clear();

signals:
    void doubleClicked(const Request& request);


protected slots:
    void doubleClickedReceived(const QModelIndex& index);




private:
    HistoryModel * mModel;
    QTableView *mView;
};

#endif // HISTORYDOCKWIDGET_H
