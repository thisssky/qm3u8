#include "browser.h"

browser::browser(QObject *parent) : QObject(parent)
{

}

void browser::show(){
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
   QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
   QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::PlaybackRequiresUserGesture, true);
   QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::DnsPrefetchEnabled, true);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::FullScreenSupportEnabled, true);

    QWebEngineView *view=new QWebEngineView();
    view->load(QUrl("http://miao101.com"));
    QWebEngineProfile *profile=  QWebEngineProfile::defaultProfile();
    profile->setPersistentCookiesPolicy(QWebEngineProfile::PersistentCookiesPolicy::AllowPersistentCookies);
    MQWebEngineUrlRequestInterceptor *webInterceptor = new MQWebEngineUrlRequestInterceptor();
    profile->setRequestInterceptor(webInterceptor);
    qDebug()<<"----"<<profile->httpUserAgent();
    view->show();

//    view->page()->setDevToolsPage(pdev->page());
}

void browser::show2(){
    QWidget wi;
        QMediaPlayer* player = new QMediaPlayer(0, QMediaPlayer::VideoSurface);
        QVideoWidget* vw = new QVideoWidget;
        QVBoxLayout* lay =  new QVBoxLayout;
        lay->addWidget(vw);
        vw->setMinimumSize(400, 300);
        lay->setSizeConstraint(QLayout::SetMinimumSize);
        wi.setLayout(lay);

        player->setVideoOutput(vw);

        QNetworkRequest req(QUrl("https://feifei.feifeizuida.com/20190827/17072_15b78ee4/1000k/hls/index.m3u8"));

        QMediaContent c(req);
        player->setMedia(c);
        player->play();
}
