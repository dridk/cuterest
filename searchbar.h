#ifndef SEARCHBAR_H
#define SEARCHBAR_H
#include <QtWidgets>
#include "request.h"
class SearchBar : public QToolBar
{
    Q_OBJECT
public:
    SearchBar(QWidget * parent=0);
    ~SearchBar();

public slots:
    void setRequest(const Request& request);

signals:
    void requestTrigger(const Request& request);
    void favoriteTrigger(const Request& request);

protected:
    void setVerbs(const QStringList& list);
    Request createRequest();

protected slots:
    void sendRequest();
    void sendFavorite();



private:
    QLineEdit * mLineEdit;
    QComboBox * mVerbCombo;
    QToolButton * mToolButton;
    QToolButton * mFavButton;

    QPushButton * mSearchButton;
    QWidget * mMainWidget;
    Request mRequest;
};

#endif // SEARCHBAR_H
