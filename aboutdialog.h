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

#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "aboutlabel.h"



class AboutDialog : public QDialog
{
    Q_OBJECT
public:
    AboutDialog(QWidget * parent = 0);
    ~AboutDialog();


protected slots:
    void buttonClicked(QAbstractButton * button);

private:
    QDialogButtonBox * mButtonBox;
    QPushButton * mTwitterButton;
    QPushButton * mGithubButton;
    AboutLabel * mContentLabel;
};

#endif // ABOUTDIALOG_H
