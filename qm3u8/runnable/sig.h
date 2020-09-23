#ifndef SIG_H
#define SIG_H

#include<QDebug>
class sig:public QObject
{
    Q_OBJECT
public:
    sig();
signals:
    void emitsig();

};

#endif // SIG_H
