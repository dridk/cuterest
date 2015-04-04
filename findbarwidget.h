#ifndef FINDBARWIDGET_H
#define FINDBARWIDGET_H

#include <QtWidgets>
#include "treesortfilterproxymodel.h"

class FindBarWidget : public QFrame
{
    Q_OBJECT
public:
    explicit FindBarWidget(TreeSortFilterProxyModel * model, QWidget *parent = 0);
    ~FindBarWidget();
public slots:
    void edit();
    void setFilterColumn(int row);


signals:
    void textChanged(const QString& txt);

private:
    QLineEdit * mEdit;
    QComboBox * mColBox;
    TreeSortFilterProxyModel * mModel;

};

#endif // FINDBARWIDGET_H
