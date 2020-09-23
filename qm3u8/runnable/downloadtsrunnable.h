#ifndef DOWNLOADTSRUNNABLE_H
#define DOWNLOADTSRUNNABLE_H

#include <QRunnable>
#include <QDebug>
#include <QThread>
class DownloadTsRunnable:public QObject,public QRunnable
{
    Q_OBJECT
public:
    DownloadTsRunnable();
    void run() override;
    void  test(QString m3u8);
};

#endif // DOWNLOADTSRUNNABLE_H
