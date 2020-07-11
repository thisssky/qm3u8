#include "mainwindow.h"

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
//    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    QApplication a(argc, argv);
//    QtWebEngine::initialize();
    MainWindow w;
    w.show();


    //    QTextStream cout(stdout, QIODevice::WriteOnly);

    //        1586168220000
    //    long date=13569379200000000;
    //    WebCookie webcookie;
    //    webcookie.loadCookie();
    //    webcookie.getLocalCookie();
    //    QString d= getDateTime("","");
    //    cout<<d<<endl;
    return a.exec();

}
