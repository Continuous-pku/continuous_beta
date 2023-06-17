#include "policy.h"
#include"pchoice.h"
#include "ui_policy.h"

policy::policy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::policy)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setModal
}

void policy::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
    QWidget::paintEvent(event);
}

void policy::mousePressEvent(QMouseEvent *event)
{
    QPointF pl=event->globalPosition();
    int x=pl.x(),y=pl.y();
    QRect tep=this->geometry();
    x=x-tep.x();
    y=y-tep.y();

    //qDebug()<<"x,y:"<<x<<' '<<y;

    if(x>=760 && x<=790 && y>=10 && y<=40)
    {
        close();
    }
}

policy::~policy()
{
    delete ui;
}

void policy::on_hesuan_clicked()
{
    //pchoice* pc=new pchoice;

}

