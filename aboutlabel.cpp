#include "aboutlabel.h"

AboutLabel::AboutLabel(QWidget * parent)
    :QLabel(parent)
{

    setFixedSize(400,460);
    setMaximumSize(400,460);
}

AboutLabel::~AboutLabel()
{

}

void AboutLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);

    QPainter painter(this);


    painter.setPen(QPen(Qt::black));

    painter.drawPixmap(0,0,QPixmap(":/about_bg.png"));

    int tMargin = 15;
    QRect titleArea = QRect(0,0,width(), 150).adjusted(tMargin,tMargin,-tMargin,-tMargin);


    //   QLinearGradient gradient(0,0,0,150);
    //   gradient.setColorAt(0,QColor("#97A1AD"));
    //   gradient.setColorAt(0.5,Qt::transparent);
    //   painter.setBrush(QBrush(gradient));
    //   painter.setPen(Qt::NoPen);

    //    painter.drawRect(titleArea.adjusted(-tMargin,-tMargin,tMargin,tMargin));

    painter.drawPixmap(titleArea.topLeft(), QPixmap(":/logo_64.png"));

    QFont f = font();
    f.setPointSize(28);
    f.setFamily("American Captain");
    painter.setFont(f);
    painter.drawText(titleArea.topLeft() + QPoint(80,32), "CUTE REST");

    f.setFamily("Arial");
    f.setPointSize(12);
    painter.setFont(f);
    painter.setPen(QPen(Qt::lightGray));
    painter.drawText(titleArea.topLeft() + QPoint(80,56), "version 1.0");


    QRect contentArea = QRect(0, titleArea.bottom() - 40, width(), rect().bottom()).adjusted(tMargin,0,-tMargin,-tMargin);
    //    painter.drawRect(contentArea);

    f.setPointSize(8);
    painter.setPen(QPen(Qt::black));
    painter.setFont(f);

    QTextOption option;
    option.setWrapMode(QTextOption::WordWrap);
    painter.drawText(contentArea,text(),option);


    painter.setPen(QPen(Qt::darkGray));
    painter.drawLine(rect().bottomLeft(), rect().bottomRight());

}

