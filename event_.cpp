#include "event_.h"
#include "ui_event_.h"
#include"QStyleOption"
#include"QPainter"
#include"QMouseEvent"

Event_::Event_(int _idx, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Event_),
    idx(_idx)
{
    ui->setupUi(this);
    QStringList options;
    options<<tr("未名湖边的小情侣")<<tr("未名湖畔好读书");

    txts<<tr("未名湖畔，博雅塔下，正是一番风花雪月。只是不知，亲密无间的接触，是否也会带来疾病传播的风险？")
         <<tr("是日也，天朗气清，惠风和畅，正适合携古籍一二，湖畔执卷而读。");

    re<<tr("传播风险增加   学生满意度增加")
         <<tr("传播风险增加   学生满意度增加");

    ui->title->setText(options[idx]);
    ui->text->setText(txts[idx]);
    ui->result->setText(re[idx]);

    switch(idx)
    {
    case 0:{ui->pic->setStyleSheet(" border-image: url(:/new/pics/resouce/affair/a0.png)");break;}
    case 1:{ui->pic->setStyleSheet(" border-image: url(:/new/pics/resouce/affair/a1.png)");break;}
    }

}

Event_::~Event_()
{
    delete ui;
}

void Event_::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
    QWidget::paintEvent(event);
}

void Event_::mousePressEvent(QMouseEvent *event)
{
    QPointF pl=event->globalPosition();
    int x=pl.x(),y=pl.y();
    QRect tep=this->geometry();
    x=x-tep.x();
    y=y-tep.y();

    //qDebug()<<x<<' '<<y;

    if(x>=450&&x<=580&&y>=10&&y<=50)
    {
        close();
        delete this;
    }
    if(x<=0||y<=0||x>=width()||y>=height())
    {
        close();
        delete this;
    }
}

void Event_::on_con_clicked()
{
    close();
    delete this;
}

