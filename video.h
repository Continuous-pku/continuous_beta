#include<QMediaPlayer>
#include<QVideoWidget>
#include <QMouseEvent>
#include<QKeyEvent>
//#include<QMediaPlaylist>
#ifndef VIDEO_H
#define VIDEO_H


#include <QWidget>

class QMediaPlayer;
class QVideoWidget;

class video : public QVideoWidget
{
public:
    video(int s);
    QMediaPlayer *player;
    int state;
    void mousePressEvent(QMouseEvent *event);

signals:

};

#endif // VIDEO_H
