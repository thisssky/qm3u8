#include "mainwindow.h"
#include <QtCore/QCoreApplication>
#include <QtWidgets/QApplication>
#include "browser.h"
#include "browserwindow.h"
#include "tabwidget.h"
#include <QApplication>
#include <QWebEngineProfile>
#include <QWebEngineSettings>


//#include <VLCQtCore/Common.h>

//#include "SimplePlayer.h"

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
QUrl commandLineUrlArgument()
{
    const QStringList args = QCoreApplication::arguments();
    for (const QString &arg : args.mid(1)) {
        if (!arg.startsWith(QLatin1Char('-')))
            return QUrl::fromUserInput(arg);
    }
    return QUrl(QStringLiteral("https://www.qt.io"));
}
void old(){

    //    QCoreApplication::setApplicationName("VLC-Qt Simple Player");
    //    QCoreApplication::setAttribute(Qt::AA_X11InitThreads);

    //    QApplication app(argc, argv);
    //    VlcCommon::setPluginPath(app.applicationDirPath() + "/plugins");
    //https://youku.cdn7-okzy.com/20191122/15896_e32b5e7c/1000k/hls/index.m3u8
    //    SimplePlayer mainWindow;
    //    mainWindow.show();


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

    //    MyWindow myWindow;
    //    myWindow.show();
    //    return app.exec();
}
int start(int argc, char *argv[]){

    QCoreApplication::setOrganizationName("QtExamples");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(QStringLiteral(":AppLogoColor.png")));

    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
#if QT_VERSION >= QT_VERSION_CHECK(5, 13, 0)
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::DnsPrefetchEnabled, true);
    QWebEngineProfile::defaultProfile()->setUseForGlobalCertificateVerification();
    MQWebEngineUrlRequestInterceptor *requestInterceptor=new MQWebEngineUrlRequestInterceptor();
    QWebEngineProfile::defaultProfile()->setRequestInterceptor(requestInterceptor);

#endif

    //    QUrl url = commandLineUrlArgument();
    QUrl url=QUrl("https://www.baidu.com");
    Browser browser;
    BrowserWindow *window = browser.createWindow();
    window->tabWidget()->setUrl(url);

    return app.exec();
}
int main(int argc, char *argv[])
{
    int result=start(argc,argv);

    return result;
}
