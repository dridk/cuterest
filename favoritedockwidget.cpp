#include "favoritedockwidget.h"
#include <QHeaderView>
#include <QStandardPaths>
FavoriteDockWidget::FavoriteDockWidget(QWidget * parent)
    :QDockWidget(parent, Qt::Window | Qt::CustomizeWindowHint )
{

    mView = new FavoriteTreeView;

    setWidget(mView);

    mView->setObjectName("Favorite");

    setFeatures(QDockWidget::NoDockWidgetFeatures);



    setWindowTitle(tr("Favorite"));

    connect(mView,SIGNAL(doubleClicked(Request)),this,SIGNAL(doubleClicked(Request)));


}

FavoriteDockWidget::~FavoriteDockWidget()
{
    delete mView;

}

void FavoriteDockWidget::append(const Request &request)
{
    mView->favoriteModel()->append(request);
}

void FavoriteDockWidget::importFavorite(const QString &path)
{
    mView->favoriteModel()->load(path);
}

void FavoriteDockWidget::exportFavorite(const QString &path)
{
    mView->favoriteModel()->save(path);
}


