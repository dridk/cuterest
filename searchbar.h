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
    void triggerRequest(const Request& request);

protected:
    void setVerbs(const QStringList& list);

protected slots:
    void createRequest();



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
