
#include "widget.h"
#include "ui_widget.h"
#include"QStyleOption"
#include"QPainter"
#include"video.h"
#include"mainw.h"
#include<QVideoWidget>
#include<QMediaPlayer>
#include<QMouseEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
    QWidget::paintEvent(event);
}

void Widget::on_pushButton_2_clicked()
{
    close();
}


void Widget::on_pushButton_released()
{
    //video* t=new video(1);
    //t->player->setSource(QUrl("qrc:/new/pics/resouce/load.mp4"));
    //t->player->play();
    //t->showFullScreen();
    //while(true)
    //{
    //    if(t->player->mediaStatus()==QMediaPlayer::EndOfMedia) break;
    //    QCoreApplication::processEvents();
    //}
    mainw *w=new mainw(this);
    w->resize(width(),height());
    w->show();
    //t->close();
    w->showitems();
    //t->close();
    //delete t;
    close();
}

