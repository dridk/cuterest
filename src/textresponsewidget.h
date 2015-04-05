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

#ifndef TEXTRESPONSEWIDGET_H
#define TEXTRESPONSEWIDGET_H
#include "abstractresponsewidget.h"
#include <QTextEdit>
#include "jsonsyntaxhighlighter.h"
#include "xmlsyntaxhighlighter.h"
class TextResponseWidget : public AbstractResponseWidget
{
    Q_OBJECT
public:
    TextResponseWidget(QWidget * parent=0);
    ~TextResponseWidget();

public slots:
    void setResponse(const Response& rep);
    void setSyntaxHighlighter(const QString& key);
    void saveAs();

protected :
    void addSyntaxHighlighter(const QString& key, QSyntaxHighlighter* highlighter);



private:
    QTextEdit * mEdit;
    QComboBox * mSyntaxBox;
    QToolBar * mToolBar;

    QHash<QString, QSyntaxHighlighter*> mHighlighters;

};

#endif // TEXTRESPONSEWIDGET_H
