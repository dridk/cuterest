/*
* Copyright (c) 2015 CuteRest
* CuteRest, a json REST viewer [https://github.com/dridk/cuterest]
* This file is part of CuteRest Project.
* CuteRest is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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

void AboutLabel::setTitle(const QString &title, const QString &subTitle)
{
    mTitle = title;
    mSubtitle = subTitle;
    repaint();
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
    painter.drawText(titleArea.topLeft() + QPoint(80,32), mTitle);

    f.setFamily("Arial");
    f.setPointSize(12);
    painter.setFont(f);
    painter.setPen(QPen(Qt::lightGray));
    painter.drawText(titleArea.topLeft() + QPoint(80,56), mSubtitle);


    QRect contentArea = QRect(0, titleArea.bottom() - 40, width(), rect().bottom()).adjusted(tMargin,0,-tMargin,-tMargin);
    //    painter.drawRect(contentArea);

    painter.setPen(QPen(Qt::black));
    painter.setFont(QFont());

    QTextOption option;
    option.setWrapMode(QTextOption::WordWrap);
    painter.drawText(contentArea,text(),option);


    painter.setPen(QPen(Qt::darkGray));
    painter.drawLine(rect().bottomLeft(), rect().bottomRight());

}

