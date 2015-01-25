#include "verbcombobox.h"

VerbComboBox::VerbComboBox(QWidget * parent)
    :QComboBox(parent)
{
    QStringList verbs;
    verbs<<"GET"<<"POST"<<"PUT"<<"DELETE";
    addItems(verbs);
}

VerbComboBox::~VerbComboBox()
{

}

