#include "downloadthread.h"
//https://blog.csdn.net/u012372584/article/details/80509217
DownloadThread::DownloadThread()
{

}
DownloadThread::DownloadThread(QObject* par) : QThread(par)
  ,count(20)
{

}
DownloadThread::~DownloadThread(){

}

void DownloadThread::setSomething()
{
    msleep(500);
    QString str = QString("%1->%2,thread id:%3").arg(__FUNCTION__).arg(__FILE__).arg((int)QThread::currentThreadId());
    emit message(str);
}

void DownloadThread::getSomething()
{
    msleep(500);
    emit message(QString("%1->%2,thread id:%3").arg(__FUNCTION__).arg(__FILE__).arg((int)QThread::currentThreadId()));
}

void DownloadThread::setRunCount(int count)
{
    count =this->count;
    emit message(QString("%1->%2,thread id:%3").arg(__FUNCTION__).arg(__FILE__).arg((int)QThread::currentThreadId()));
}

void DownloadThread::run()
{
    int count = 0;
    QString str = QString("%1->%2,thread id:%3").arg(__FILE__).arg(__FUNCTION__).arg((int)QThread::currentThreadId());
    emit message(str);
    while(1)
    {
        sleep(1);
        ++count;
        emit progress(((float)count / count) * 100);
        emit message(QString("ThreadFromQThread::run times:%1").arg(count));
        doSomething();
        if(count == this->count)
        {
            break;
        }
    }
}

void DownloadThread::doSomething()
{
    msleep(500);
    emit message(QString("%1->%2,thread id:%3").arg(__FUNCTION__).arg(__FILE__).arg((int)QThread::currentThreadId()));
}
