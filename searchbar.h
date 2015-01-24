#ifndef SEARCHBAR_H
#define SEARCHBAR_H
#include <QtWidgets>
class SearchBar : public QToolBar
{
    Q_OBJECT
public:
    SearchBar(QWidget * parent=0);
    ~SearchBar();


protected:
    void setVerbs(const QStringList& list);


private:
    QLineEdit * mLineEdit;
    QComboBox * mVerbCombo;
    QToolButton * mToolButton;
    QPushButton * mSearchButton;
    QWidget * mMainWidget;
};

#endif // SEARCHBAR_H
