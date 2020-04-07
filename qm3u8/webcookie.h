#ifndef WEBCOOKIE_H
#define WEBCOOKIE_H

#include<QMainWindow>
#include<QWebEngineView>
#include<QWebEnginePage>
#include<QWebEngineProfile>
#include<QWebEngineCookieStore>
#include<QUrl>

#include<QDateTime>

#include<iostream>
#include<ctime>
#include<string>
#include<cstring>
#include<string.h>

#include <QSqlDriver>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

class WebCookie
{
public:
    WebCookie();
    void loadCookie();
    void getLocalCookie();
};

#endif // WEBCOOKIE_H
