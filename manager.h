#ifndef MANAGER_H
#define MANAGER_H
#include <QtNetwork>

class Manager : public QNetworkAccessManager
{
    Q_OBJECT
public:
    Manager(QObject * parent = 0);
    ~Manager();
};

#endif // MANAGER_H
