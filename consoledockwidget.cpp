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

#include "consoledockwidget.h"
#include <QHostInfo>
#include <QDateTime>
#include <QAction>
ConsoleDockWidget::ConsoleDockWidget(QWidget * parent)
    :QDockWidget(parent)
{
    setWindowTitle("Console");
    setFeatures(QDockWidget::NoDockWidgetFeatures);

    mTextEdit = new QPlainTextEdit;
    mTextEdit->setReadOnly(true);

//    setTitleBarWidget(new QWidget());

    setWidget(mTextEdit);

    QAction * clearAction = new QAction("Clear",this);

    addAction(clearAction);
}

ConsoleDockWidget::~ConsoleDockWidget()
{
    delete mTextEdit;
}

void ConsoleDockWidget::append(const Response &rep)
{

    out(QString("<b>>>Response[%3] code %1 in %2sec</b>").arg(rep.statusCode())
                                                   .arg(rep.time().toString("ss"))
                                                   .arg(QDateTime::currentDateTime().toString("hh:mm:ss")),true);

    foreach (QByteArray key , rep.rawHeaderList()) {
        out(QString("  %1 : %2").arg(QString(key)).arg(QString(rep.rawHeader(key))));
    }




}

void ConsoleDockWidget::append(const Request &req)
{

    out(QString("<b>&lt;&lt;Request[%3] %1 %2</b>").arg(req.verb())
                                                   .arg(req.url().toString())
                                                   .arg(QDateTime::currentDateTime().toString("hh:mm:ss")), true);

    foreach (QByteArray key , req.rawHeaderList()) {
        out(QString("  %1 : %2").arg(QString(key)).arg(QString(req.rawHeader(key))));
    }

    out(QString(req.paramToJson()));




}

void ConsoleDockWidget::out(const QString &message, bool rich)
{
    if (!rich)
        mTextEdit->appendPlainText(message);
    else
        mTextEdit->appendHtml(message);



}

