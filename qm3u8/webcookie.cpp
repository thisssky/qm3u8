#include "webcookie.h"


WebCookie::WebCookie()
{

}

void WebCookie::loadCookie(){

    QWebEngineView *view=new QWebEngineView();
    view->load(QUrl("https://kyfw.12306.cn"));
    QWebEngineProfile *profile=   view->page()->profile()->defaultProfile();
    QString sn= profile->storageName();
//    cout<<sn.toStdString()<<endl;
    QString psp= profile->persistentStoragePath();
//    cout<<psp.toStdString()<<endl;

    profile->cookieStore()->loadAllCookies();
    QWebEngineCookieStore *cs= profile->cookieStore();
    QObjectList list= cs->children();
    for (int i=0,len=list.size(); i<len;i++ ) {
        QObject *ssobj= list.at(i);
        QString on= ssobj->objectName();
//        cout<<on.toStdString()<<endl;
    }
    //view->show();
}



void WebCookie::getLocalCookie(){
    QStringList qlist=QSqlDatabase::drivers();
    foreach(QString qlists,qlist){
//        cout<<qlists.toStdString()<<endl;
//        cout<<"-----------------------------"<<endl;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/zhouyu/.local/share/qm3u8/QtWebEngine/Default/Cookies");
    bool ok = db.open(); // 连接数据库, 然后就可以使用了.
    if(ok){

        QSqlQuery query;
        if (query.exec("select * from cookies "))   //尝试列出  表的所有记录
        {  //本次查询成功
            int numRows = 0;  //询问数据库驱动，是否驱动含有某种特性
            if (db.driver()->hasFeature(QSqlDriver::QuerySize))
            {
//                cout<<numRows<<endl;
                numRows = query.size();  //如果支持结果影响的行数，那么直接记录下来
            }
            else
            {
                query.last(); //否则定位到结果最后，qt 文档说，这个方法非常慢
                numRows = query.at() + 1;
                query.seek(-1);
            }
        }
        //尝试列出  表的所有记录
        while (query.next()) {
            QString name=    query.value("name").toString();
            QString value=    query.value("value").toString();
            QString path=    query.value("path").toString();
            QString host_key=    query.value("host_key").toString();
            QString expires_utc=    query.value("expires_utc").toString();
            QString last_access_utc=    query.value("last_access_utc").toString();

//            cout<<"name:"+name.toStdString()<<endl;
//            cout<<"value:"+value.toStdString()<<endl;
//            cout<<"path:"+path.toStdString()<<endl;
//            cout<<"host_key:"+host_key.toStdString()<<endl;
//            cout<<"expires_utc:"+expires_utc.toStdString()<<endl;

//            cout<<"last_access_utc:"+last_access_utc.toStdString()<<endl;
//            QDateTime last=    QDateTime::fromString(last_access_utc,"yyyy-MM-dd hh:mm:ss");
//            cout<<"last:"+last.toString("yyyy-MM-dd hh:mm:ss").toStdString()<<endl;
//            cout<<"================="<<endl;
        }
    }
    else{
        //qDebug() << "cannot open database.";
        printf( "cannot open database.");
    }

}
