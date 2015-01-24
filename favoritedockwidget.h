#ifndef FAVORITEDOCKWIDGET_H
#define FAVORITEDOCKWIDGET_H
#include <QDockWidget>
#include <QTreeView>
#include "favoritemodel.h"
class FavoriteDockWidget : public QDockWidget
{
    Q_OBJECT
public:
    FavoriteDockWidget(QWidget * parent= 0);
    ~FavoriteDockWidget();


protected slots:
    void doubleClickedReceived(const QModelIndex& index);

signals:
    void clicked(const Request& request);
    void doubleClicked(const Request& request);


private:
    QTreeView * mView;
    FavoriteModel * mModel;
};

#endif // FAVORITEDOCKWIDGET_H
