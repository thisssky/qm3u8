#include "mainwindow.h"
#include "ui_mainwindow.h"
//using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    browser=new QWebEngineView();
//    ui->centralwidget->setLayout(

QHBoxLayout *hboxLayout=new QHBoxLayout();
//backLabel=new QLabel("ss");
//hboxLayout->addWidget(backLabel);


    txtUrl=new QLineEdit();
    tableWidget=new QTableWidget();
    downloadButton=new QPushButton("下载");
    hboxLayout->addWidget(txtUrl);
    hboxLayout->addWidget(downloadButton);
    hboxLayout->addWidget(tableWidget);


    this->centralWidget()->setLayout(hboxLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showWeb(){
    /*browser*/ browser;
//    browser.show();
//    localplayer localplayer;

}

void MainWindow::test(){
    QTextStream cout(stdout, QIODevice::WriteOnly);

    QWebEngineView *view=new QWebEngineView();
    view->load(QUrl("https://kyfw.12306.cn"));
    QWebEngineProfile *profile=   view->page()->profile()->defaultProfile();
    QString sn= profile->storageName();
    cout<<sn<<endl;

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

    view->show();
}
