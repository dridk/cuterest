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

#include "paramrequestwidget.h"

ParamRequestWidget::ParamRequestWidget(QWidget * parent)
    :AbstractRequestWidget(parent)
{
    mEditor= new DictEditorWidget;

    QVBoxLayout * mainLayout = new QVBoxLayout;
    mainLayout->addWidget(mEditor);

    setLayout(mainLayout);
    setWindowTitle(tr("Parameters"));
    mEditor->setLabel(tr("Key:  "), tr("Value:  "));

}

ParamRequestWidget::~ParamRequestWidget()
{
    delete mEditor;
}

void ParamRequestWidget::load(Request &request)
{
    mEditor->clear();

    foreach (QString key, request.params().keys()) {
        mEditor->insert(key, request.param(key));
    }


}

void ParamRequestWidget::save(Request &request)
{
    request.clearParams();
    for (int row=0; row < mEditor->count(); row++)
        request.insertParam(mEditor->key(row), mEditor->value(row));
}

void ParamRequestWidget::reset()
{

}

