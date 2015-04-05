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

#include "aboutdialog.h"

AboutDialog::AboutDialog(QWidget * parent)
    :QDialog(parent)
{
    mButtonBox = new QDialogButtonBox();

    mButtonBox->addButton(tr("Credits"), QDialogButtonBox::HelpRole);
    mButtonBox->addButton(QDialogButtonBox::Ok);
    mContentLabel = new AboutLabel;
    mContentLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    mContentLabel->setText("Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod"
                           "tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,"
                           "quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo"
                           "consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse"
                           "cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non"
                           "proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
                           "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod"
                           "tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,"
                           " uis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo"
                           "consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse"
                           "cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non"
                           "proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");


    QVBoxLayout * v = new QVBoxLayout;

    v->addWidget(mContentLabel);
    v->addWidget(mButtonBox);

    v->setContentsMargins(0,0,0,0);
    mButtonBox->setContentsMargins(10,10,10,10);
    setLayout(v);

    setFixedWidth(mContentLabel->width());
    setFixedHeight(500);

}

AboutDialog::~AboutDialog()
{
    delete mButtonBox;
    delete mContentLabel;
}

