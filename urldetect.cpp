#include "urldetect.h"
UrlDetect::UrlDetect()
{

}

UrlDetect::~UrlDetect()
{

}

bool UrlDetect::isValid(const QString &text)
{

    QRegularExpression regex("^(http|https|\/)(.+\/)+");
    return text.contains(regex);

}

