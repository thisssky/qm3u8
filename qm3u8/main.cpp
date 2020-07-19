#include "mainwindow.h"
#include <QtCore/QCoreApplication>
#include <QtWidgets/QApplication>

#include <VLCQtCore/Common.h>

#include "SimplePlayer.h"

//using namespace std;

QString getDateTime(QString dateString,QString formatter){
    // QDateTime qdatetime;
    //qdatetime.currentDateTime();
    QDateTime current= QDateTime::currentDateTime();
    dateString.toLong(NULL,10);
    QString result= current
            .toString("yyyy-MM-dd hh:mm:ss");
    qint64 ci=  current.toSecsSinceEpoch();
    QTextStream cout(stdout, QIODevice::WriteOnly);

    cout<<ci<<endl;
    //    cout<<result<<endl;
    return result;
}

int main(int argc, char *argv[])
{

    QCoreApplication::setApplicationName("VLC-Qt Simple Player");
    QCoreApplication::setAttribute(Qt::AA_X11InitThreads);

    QApplication app(argc, argv);
    VlcCommon::setPluginPath(app.applicationDirPath() + "/plugins");
//https://youku.cdn7-okzy.com/20191122/15896_e32b5e7c/1000k/hls/index.m3u8
    SimplePlayer mainWindow;
    mainWindow.show();


//    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
//    QApplication app(argc, argv);
//    QtWebEngine::initialize();
//    MainWindow w;
//    w.show();


    //    QTextStream cout(stdout, QIODevice::WriteOnly);

    //        1586168220000
    //    long date=13569379200000000;
    //    WebCookie webcookie;
    //    webcookie.loadCookie();
    //    webcookie.getLocalCookie();
    //    QString d= getDateTime("","");
    //    cout<<d<<endl;
    return app.exec();

}
