#ifndef MQWEBENGINEURLREQUESTINTERCEPTOR_H
#define MQWEBENGINEURLREQUESTINTERCEPTOR_H

#include<QWebEngineUrlRequestInterceptor>
#include<QDebug>

class MQWebEngineUrlRequestInterceptor:public QWebEngineUrlRequestInterceptor
{Q_OBJECT
public:
    MQWebEngineUrlRequestInterceptor();
    void interceptRequest(QWebEngineUrlRequestInfo &info);
signals:
    void signalRequest( QWebEngineUrlRequestInfo &info);
};

#endif // MQWEBENGINEURLREQUESTINTERCEPTOR_H
