#ifndef URLDETECT_H
#define URLDETECT_H
#include <QString>
#include <QRegularExpression>

class UrlDetect
{
private:
    UrlDetect();
    ~UrlDetect();

public :
    static bool isValid(const QString& text);


};

#endif // URLDETECT_H
