
#include "video.h"
#include<QMediaPlayer>
#include<QVideoWidget>
#include <QMouseEvent>
#include"QTime"
#include"QCoreApplication"

video::video(int s)
{
    state=s;
    player=new QMediaPlayer;
    setFocus();
    setWindowFlag(Qt::FramelessWindowHint);
    //resize(802,456);
    player->setVideoOutput(this);
    if(s==0)
        player->setSource(QUrl("qrc:/new/pics/resouce/open.mp4"));
    if(s==1)
        player->setSource(QUrl("qrc:/new/pics/resouce/load.mp4"));
    //player->play();
    //showFullScreen();
    //show();
}


void video::mousePressEvent(QMouseEvent *event)
{
    if(state==1)
    {
        //close();
        //delete this;
        return;
    }
    if(state==0)
    {
        state=-1;
        player->setSource(QUrl("qrc:/new/pics/resouce/start_page.mp4"));
        player->play();
        while(true)
        {
            if(player->mediaStatus()==QMediaPlayer::EndOfMedia) break;
            QCoreApplication::processEvents();
        }
        //_sleep(3000);
        close();
        delete this;
        qDebug()<<tr("happens");
    }
    return;
}
