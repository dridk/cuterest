#ifndef FINDBARWIDGET_H
#define FINDBARWIDGET_H

#include <QtWidgets>

class FindBarWidget : public QFrame
{
    Q_OBJECT
public:
    explicit FindBarWidget(QWidget *parent = 0);
    ~FindBarWidget();

signals:
    void textChanged(const QString& txt);

private:
    QLineEdit * mEdit;
    QToolButton * mRegButton;
    QPushButton * mFindButton;
};

#endif // FINDBARWIDGET_H
