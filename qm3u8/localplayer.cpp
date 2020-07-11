#include "localplayer.h"

localplayer::localplayer()
{


    QMediaPlayer *player;//私有对象
        QVideoWidget *videoWidget;//私有对象
    //在构造函数中添加
    //播放视频
    player=new QMediaPlayer();
    videoWidget=new QVideoWidget();
    videoWidget->resize(600,300);
    player->setVideoOutput(videoWidget);

//    player->setMedia(QUrl("http://ivi.bupt.edu.cn/hls/cctv1.m3u8"));

    player->setMedia(QUrl("https://dapian.video-yongjiu.com/20190826/9266_f5e17db5/1000k/hls/index.m3u8"));
    player->play();

}
