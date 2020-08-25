#ifndef DOWNLOADTHREAD_H
#define DOWNLOADTHREAD_H
#include<QThread>
#include<QDebug>

class DownloadThread :public QThread
{
    Q_OBJECT
signals:
    void message(const QString&info);
    void progress(int present);
public:
    DownloadThread();
    DownloadThread(QObject* par);
    ~DownloadThread();
    void setSomething();
    void getSomething();
    void setRunCount(int count);
    void run();
    void doSomething();
private:
    int count;
};

#endif // DOWNLOADTHREAD_H
