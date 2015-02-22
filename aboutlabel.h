#ifndef ABOUTLABEL_H
#define ABOUTLABEL_H
#include <QLabel>
#include <QPainter>

class AboutLabel : public QLabel
{
public:
    AboutLabel(QWidget * parent = 0);
    ~AboutLabel();

protected:
    virtual void paintEvent(QPaintEvent * event);
};

#endif // ABOUTLABEL_H
