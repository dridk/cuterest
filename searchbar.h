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
    QPushButton * mSearchButton;
    QWidget * mMainWidget;
};

#endif // SEARCHBAR_H
