#include "verbcombobox.h"

VerbComboBox::VerbComboBox(QWidget * parent)
    :QComboBox(parent)
{
    QStringList verbs;
    verbs<<"GET"<<"POST"<<"PUT"<<"DELETE"<<"HEAD"<<"PATCH"<<"OPTIONS";
    addItems(verbs);

}

VerbComboBox::~VerbComboBox()
{

}

