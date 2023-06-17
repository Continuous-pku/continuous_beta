#include "menu.h"
#include "ui_menu.h"
#include"QStyleOption"
#include"QPainter"
#include"QMouseEvent"
#include"QDebug"

menu::menu(QWidget *_parent) :
    QWidget(),
    ui(new Ui::menu)
{
    parent=_parent;
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->label->close();
}

menu::~menu()
{
    delete ui;
}

void menu::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
    QWidget::paintEvent(event);
}

void menu::mousePressEvent(QMouseEvent *event)
{
    QPointF pl=event->globalPosition();
    int x=pl.x(),y=pl.y();
    QRect tep=this->geometry();
    x=x-tep.x();
    y=y-tep.y();

    //qDebug()<<x<<' '<<y;

    if(x<=0||y<=0||x>=width()||y>=height())
    {
        close();
    }
}

void menu::on_pushButton_3_clicked()
{
    close();
}


void menu::on_pushButton_2_clicked()
{
    close();
    parent->close();
    delete this;
}


void menu::on_pushButton_clicked()
{
    ui->label->show();
}


void menu::on_exit_clicked()
{
    close();
}

