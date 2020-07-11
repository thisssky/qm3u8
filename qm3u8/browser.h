#ifndef BROWSER_H
#define BROWSER_H

#include <QObject>
#include<QWebEngineView>
#include<QWebEngineSettings>
#include<QWebEngineProfile>
#include<QDebug>
#include<mqwebengineurlrequestinterceptor.h>

#include<QMediaPlayer>
#include<QVideoWidget>
#include<QVBoxLayout>

class browser : public QObject
{
    Q_OBJECT
public:
    explicit browser(QObject *parent = nullptr);
    void show();
    void show2();
signals:

};

#endif // BROWSER_H
