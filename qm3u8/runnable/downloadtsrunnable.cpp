#include "downloadtsrunnable.h"

DownloadTsRunnable::DownloadTsRunnable()
{

}

void DownloadTsRunnable::run(){
    qDebug() << "child thread id: " << QThread::currentThreadId();
    int i = 5;
    while(i--)
    {
        qDebug() << QString("hello world %1").arg(i);
    }

}

void DownloadTsRunnable::test(QString m3u8){
    qDebug()<<m3u8<<endl;
}
