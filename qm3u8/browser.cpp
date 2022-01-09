#include "browser.h"
#include "browserwindow.h"

Browser::Browser()
{
    // Quit application if the download manager window is the only remaining window
    m_downloadManagerWidget.setAttribute(Qt::WA_QuitOnClose, false);

    QObject::connect(
                QWebEngineProfile::defaultProfile(), &QWebEngineProfile::downloadRequested,
                &m_downloadManagerWidget, &DownloadManagerWidget::downloadRequested);

    //添加过滤
    m_requestInterceptor = new MQWebEngineUrlRequestInterceptor();
    QWebEngineProfile::defaultProfile()->setRequestInterceptor(m_requestInterceptor);
//    QWebEngineProfile::defaultProfile()->setUrlRequestInterceptor(m_requestInterceptor);

}

BrowserWindow *Browser::createWindow(bool offTheRecord)
{
    if (offTheRecord && !m_otrProfile) {
        m_otrProfile.reset(new QWebEngineProfile);
        QObject::connect(
                    m_otrProfile.get(), &QWebEngineProfile::downloadRequested,
                    &m_downloadManagerWidget, &DownloadManagerWidget::downloadRequested);
    }
    auto profile = offTheRecord ? m_otrProfile.get() : QWebEngineProfile::defaultProfile();

    auto mainWindow = new BrowserWindow(this, profile, false);

    m_windows.append(mainWindow);
    QObject::connect(mainWindow, &QObject::destroyed, [this, mainWindow]() {
        m_windows.removeOne(mainWindow);
    });
    mainWindow->show();
    return mainWindow;
}

BrowserWindow *Browser::createDevToolsWindow()
{
    auto profile = QWebEngineProfile::defaultProfile();
    auto mainWindow = new BrowserWindow(this, profile, true);
    m_windows.append(mainWindow);
    QObject::connect(mainWindow, &QObject::destroyed, [this, mainWindow]() {
        m_windows.removeOne(mainWindow);
    });
    mainWindow->show();
    return mainWindow;
}

void Browser::show(){
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

void Browser::show2(){
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
