#include "pchoice.h"
#include "ui_pchoice.h"
#include"QStyleOption"
#include"QPainter"
#include"QMouseEvent"

pchoice::pchoice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pchoice)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

pchoice::~pchoice()
{
    delete ui;
}


void pchoice::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
    QWidget::paintEvent(event);
}

void pchoice::mousePressEvent(QMouseEvent *event)
{
    QPointF pl=event->globalPosition();
    int x=pl.x(),y=pl.y();
    QRect tep=this->geometry();
    x=x-tep.x();
    y=y-tep.y();

    //qDebug()<<x<<' '<<y;

    if(x>=470&&x<=500&&y>=10&&y<=50)
    {
        close();
        delete this;
    }
}
