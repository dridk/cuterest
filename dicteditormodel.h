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

#ifndef DICTEDITORMODEL_H
#define DICTEDITORMODEL_H
#include <QAbstractTableModel>
#include <QtCore>

class DictEditorModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    DictEditorModel(QObject * parent =0);
    ~DictEditorModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role) const;
    const QString &key(int row);
    const QVariant &value(int row);
    void setHeaders(const QStringList& list);

public slots:
    void clear();
    void insert(const QString& key, const QVariant& value);
    void remove(int row);


private:
    QList< QPair<QString, QVariant> > mData;
    QStringList mHeaders;


};

#endif // DICTEDITORMODEL_H
