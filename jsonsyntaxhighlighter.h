/****************************************************************************
**
** Copyright (C) 2010-2012 B.D. Mihai.
**
** This file is part of JSON Viewer.
**
** JSON Viewer is free software: you can redistribute it and/or modify it
** under the terms of the GNU Lesser Public License as published by the Free
** Software Foundation, either version 3 of the License, or (at your option)
** any later version.
**
** JSON Viewer is distributed in the hope that it will be useful, but
** WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
** or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser Public License for
** more details.
**
** You should have received a copy of the GNU Lesser Public License along
** with JSON Viewer.  If not, see http://www.gnu.org/licenses/.
**
****************************************************************************/

#ifndef JSONSYNTAXHIGHLIGHTER_H
#define JSONSYNTAXHIGHLIGHTER_H
#include <QSyntaxHighlighter>
#include <QTextCharFormat>
class JsonSyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    JsonSyntaxHighlighter(QTextDocument * parent = 0);
    ~JsonSyntaxHighlighter();

protected:
    void highlightBlock(const QString &text);

  private:

    enum BlockState
    {
      valueState,
      nameState,
      otherState
    };

    QTextCharFormat symbolFormat;
    QTextCharFormat nameFormat;
    QTextCharFormat valueFormat;


};

#endif // JSONSYNTAXHIGHLIGHTER_H
