#include "buildings.h"
#include "ui_buildings.h"
#include"QStyleOption"
#include"QPainter"
#include"QMouseEvent"
#include"QDebug"
#include"b_upgrade.h"
#include<string>
#include<qstringlist.h>
#include"mainw.h"
#include"build_info.h"

buildings::buildings(Game* game, mainw *parent) :
    g(game),
    _parent(parent),
    ui(new Ui::buildings)
{
    //qDebug()<<"building!"<<game->getBuilding(0)->getLevel();
    ui->setupUi(this);
    ui->cover->setGeometry(260,0,0,41);
    this->setWindowFlags(Qt::FramelessWindowHint);
    options << tr("1号宿舍楼")<< tr("2号宿舍楼")<< tr("3号宿舍楼")<< tr("4号宿舍楼")<< tr("5号宿舍楼")<< tr("6号宿舍楼")
            << tr("7号宿舍楼")<< tr("8号宿舍楼")<< tr("9号宿舍楼")<< tr("10号宿舍楼")<< tr("11号宿舍楼")<< tr("12号宿舍楼")
            << tr("13号宿舍楼")<< tr("14号宿舍楼")<< tr("15号宿舍楼")<< tr("16号宿舍楼")<< tr("17号宿舍楼")<< tr("18号宿舍楼")
            << tr("19号宿舍楼")<< tr("20号宿舍楼")<< tr("21号宿舍楼")<< tr("22号宿舍楼")<< tr("23号宿舍楼")<< tr("24号宿舍楼")
            << tr("25号宿舍楼")<< tr("26号宿舍楼")<< tr("27号宿舍楼")<< tr("28号宿舍楼")<< tr("29号宿舍楼")<< tr("30号宿舍楼")
            << tr("31号宿舍楼")<< tr("32号宿舍楼")<< tr("33号宿舍楼")<< tr("34号宿舍楼")<< tr("35号宿舍楼")<< tr("36号宿舍楼")
            << tr("37号宿舍楼")<< tr("38号宿舍楼")<< tr("39号宿舍楼")<< tr("40号宿舍楼")<< tr("41号宿舍楼")<< tr("42号宿舍楼")
            << tr("43号宿舍楼")<< tr("44号宿舍楼")<< tr("45号宿舍楼")<< tr("农园食堂")<< tr("艺院食堂")<< tr("家园食堂")
            << tr("勺园食堂")<< tr("学一食堂")<< tr("学五食堂")<< tr("第一教学楼")<< tr("第二教学楼")<< tr("第三教学楼")
            << tr("第四教学楼")<< tr("理科教学楼")<< tr("文史楼")<< tr("地学楼")<< tr("图书馆")<< tr("校医院")
            << tr("五四操场")<< tr("五四体育馆")<< tr("邱徳拔体育馆")<< tr("未名湖")<< tr("理科实验楼")<< tr("东门")
            << tr("南门")<< tr("西门")<< tr("西南门")<< tr("东南门")<< tr("东北门");
}

buildings::~buildings()
{
    delete ui;
}
void buildings::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
    QWidget::paintEvent(event);
}

void buildings::covery()
{
    outl=false;
    ui->cover->setGeometry(260,0,0,41);
}

void buildings::mousePressEvent(QMouseEvent *event)
{
    QPointF pl=event->globalPosition();
    int x=pl.x(),y=pl.y();
    QRect tep=this->geometry();
    x=x-tep.x();
    y=y-tep.y();

    //qDebug()<<x<<' '<<y;

    if(x>=280&&x<=310&&y>=10&&y<=40)
    {
        if(!outl)
            close();
        delete this;
    }
    if(x<=0||y<=0||x>=width()||y>=height())
    {
        close();
    }
}

void buildings::on_treeWidget_itemPressed(QTreeWidgetItem *item, int column)
{
    QString str =item->text(column);
    int temp=options.indexOf(str);
    if(temp==-1) return;
    Building* tep=g->getBuilding(temp);
    //qDebug()<<"a";
    if(son!=nullptr)
    {
        son->close();
        son->info->close();
        delete son->info;
        delete son;
    }
    //qDebug()<<"b";
    son=new b_upgrade(tep,str,this);
    //qDebug()<<"c";
    son->setGeometry(this->geometry().x()+320,this->geometry().y(),son->width(),son->height());
    outl=true;
    ui->cover->setGeometry(260,0,61,41);
    son->show();
    son->info->setGeometry(this->geometry().x()+320+son->width(),this->geometry().y()+76,son->info->width(),son->info->height());
    son->info->show();
}

