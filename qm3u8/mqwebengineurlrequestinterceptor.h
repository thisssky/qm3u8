#ifndef MQWEBENGINEURLREQUESTINTERCEPTOR_H
#define MQWEBENGINEURLREQUESTINTERCEPTOR_H

#include<QWebEngineUrlRequestInterceptor>
#include<QDebug>

class MQWebEngineUrlRequestInterceptor:public QWebEngineUrlRequestInterceptor
{
public:
    MQWebEngineUrlRequestInterceptor();
    void interceptRequest(QWebEngineUrlRequestInfo &info);

};

#endif // MQWEBENGINEURLREQUESTINTERCEPTOR_H
