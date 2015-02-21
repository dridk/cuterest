#ifndef FAVORITEDOCKWIDGET_H
#define FAVORITEDOCKWIDGET_H
#include <QDockWidget>
#include <QTreeView>
#include "favoritemodel.h"
#include "favoritetreeview.h"
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

signals:
    void doubleClicked(const Request& request);


private:
    FavoriteTreeView * mView;

};

#endif // FAVORITEDOCKWIDGET_H
