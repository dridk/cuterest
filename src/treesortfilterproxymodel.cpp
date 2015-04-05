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

#include "treesortfilterproxymodel.h"

TreeSortFilterProxyModel::TreeSortFilterProxyModel(QObject * parent)
    :QSortFilterProxyModel(parent)
{

}

TreeSortFilterProxyModel::~TreeSortFilterProxyModel()
{

}

bool TreeSortFilterProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{

       if(filterRegExp().isEmpty()==false)
       {
           // get source-model index for current row
           QModelIndex source_index = sourceModel()->index(source_row, this->filterKeyColumn(), source_parent) ;
           if(source_index.isValid())
           {
               // if any of children matches the filter, then current index matches the filter as well
               int i, nb = sourceModel()->rowCount(source_index) ;
               for(i=0; i<nb; ++i)
               {
                   if(filterAcceptsRow(i, source_index))
                   {
                       return true ;
                   }
               }
               // check current index itself :
               QString key = sourceModel()->data(source_index, filterRole()).toString();
               return key.contains(filterRegExp()) ;
           }
       }
       // parent call for initial behaviour
       return QSortFilterProxyModel::filterAcceptsRow(source_row, source_parent) ;




}



