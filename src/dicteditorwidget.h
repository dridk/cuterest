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

#ifndef DICTEDITORWIDGET_H
#define DICTEDITORWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include "dicteditormodel.h"
class DictEditorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DictEditorWidget(QWidget *parent = 0);
    ~DictEditorWidget();

    void setCompleter(const QStringList& keys);
    void insert(const QString& key, const QVariant& value);
    const QString &key(int row) const;
    const QVariant &value(int row) const;
    int count() const;
    void clear();
    void setLabel(const QString& typeName, const QString& valueName);


public slots:
    void addClicked();
    void removeClicked();

private:
    QTableView *mView;
    DictEditorModel * mModel;
    QComboBox * mKeyEdit;
    QLineEdit * mValueEdit;
    QToolButton* mAddButton;
    QToolButton* mRemButton;
    QLabel * mTypeLabel;
    QLabel * mValueLabel;
};

#endif // DICTEDITORWIDGET_H
