#ifndef REPONSE_H
#define REPONSE_H
#include <QtCore>
#include <QByteArray>

class Response
{
public:
    Response();
    ~Response();
    void setBody(const QByteArray& body);
    const QByteArray &body() const;

    void setElapsed(qint64 time);
    qint64 elapsed() const;


private:
    QByteArray mBody;
    qint64	mElapsed;


};

#endif // REPONSE_H
