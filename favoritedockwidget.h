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


public slots:
    void append(const Request& request);
    void importFavorite(const QString& path);
    void exportFavorite(const QString& path);


protected slots:
    void doubleClickedReceived(const QModelIndex& index);

signals:
    void doubleClicked(const Request& request);


private:
    QTreeView * mView;
    FavoriteModel * mModel;
};

#endif // FAVORITEDOCKWIDGET_H
