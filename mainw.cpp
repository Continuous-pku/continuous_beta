#include "mainw.h"
#include "ui_mainw.h"
#include"QStyleOption"
#include"QPainter"
#include"class.h"
#include"QMouseEvent"
#include"menu.h"
#include"policy.h"
#include"buildings.h"
#include<cstring>

mainw::mainw(QWidget *upper, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainw),
    up(upper)
{
    //ui->label->setVisible(false);

    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    year_month=new QLabel(this);
    day=new QLabel(this);
    ap=new QLabel(this);
    sat=new QLabel(this);
    infect=ui->label;
    m=new menu(this);
    p=new policy;
    //infect=new QLabel(this);
    //infect->set
    game=new Game;
    game->win=this;
    game->gameRun();

}
int mainw::normalize_x(int x)
{
    int w=width();
    x=x*w/1056;
    return x;
}
int mainw::normalize_y(int y)
{
    int h=height();
    //qDebug()<<y;
    y=y*h/621;
    //qDebug()<<y<<' '<<h;
    return y;
}
void mainw::showitems()
{
    //qDebug()<<"building!"<<game->getBuilding(0)->getLevel();

    QFont font;
    font.setFamily("等线");
    font.setPointSize(24);

    ui->pushButton->setGeometry(normalize_x(900),normalize_y(490),
                                normalize_x(121),normalize_y(101));
    ui->exit->setGeometry(normalize_x(1000),normalize_y(10),
                          normalize_x(41),normalize_y(41));
    ui->menu_->setGeometry(normalize_x(950),normalize_y(10),
                           normalize_x(41),normalize_y(41));
    ui->pc->setGeometry(0,normalize_y(440),
                           normalize_x(301),normalize_y(91));
    ui->bu->setGeometry(0,normalize_y(530),
                           normalize_x(301),normalize_y(91));
    ui->info_dia->setGeometry(normalize_x(850),normalize_y(110),
                        normalize_x(181),normalize_y(271));
    ui->back->setGeometry(normalize_x(840),normalize_y(100),
                              normalize_x(201),normalize_y(291));
    ui->slog_->setGeometry(normalize_x(387),normalize_y(13),
                              normalize_x(281),normalize_y(44));

    year_month->setGeometry(normalize_x(55),normalize_y(80),normalize_x(121),normalize_y(31));
    year_month->setText(QString::fromUtf8(game->yam.c_str()));
    year_month->setStyleSheet("color:white;");
    year_month->setFont(font);
    year_month->show();

    day->setText(to_string(game->getdate()).c_str());
    if(game->getdate()>=10)
        day->setGeometry(normalize_x(75),normalize_y(140),normalize_x(81),normalize_y(61));
    else
        day->setGeometry(normalize_x(93),normalize_y(140),normalize_x(81),normalize_y(61));
    day->setStyleSheet("color:white;");
    font.setPointSize(72);
    day->setFont(font);
    day->show();

    sat->setText(to_string(game->getsat()).c_str());
    sat->setGeometry(normalize_x(240),normalize_y(23),normalize_x(80),normalize_y(21));
    sat->setStyleSheet("color:black;");
    font.setPointSize(22);
    sat->setFont(font);
    sat->show();

    showap();

    infect->setGeometry(normalize_x(657-game->getill()*257/40000),normalize_y(21),normalize_x(game->getill()*257/40000),normalize_y(26));
}

void mainw::a_text(QString p)
{
    QString tep=ui->infom->text();
    tep=QString::fromUtf8(game->yam.c_str())+QString::fromUtf8(to_string(game->getdate()))+' '+p+'\n'+'\n'+tep;
    ui->infom->setText(tep);
    return;
}

void mainw::showap(){

    QFont font;
    font.setPointSize(22);
    font.setFamily("等线");
    ap->setText(to_string(game->getap()).c_str());
    ap->setGeometry(normalize_x(70),normalize_y(23),normalize_x(200),normalize_y(21));
    ap->setFont(font);
    ap->show();
}

void mainw::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
    QWidget::paintEvent(event);
}

mainw::~mainw()
{
    delete ui;
}

void mainw::mousePressEvent(QMouseEvent *event)
{
    if(end)
    {
        up->show();
        this->close();
        delete this;
    }
    //QPointF pl=event->globalPosition();
    //int w=width(),h=height();
    //int x=pl.x(),y=pl.y();
    //normalize
    //x=x*1056/w;
    //y=y*621/h;
}

void mainw::on_pushButton_clicked()
{
    int i=game->start_newday();
    ++days;
    if(i==1)
    {
        QLabel* l=new QLabel;
        l->setText(tr("你赢啦！！！"));
        l->setParent(this);
        l->setGeometry(width()/2-400/2,height()/2-l->height()/2,400,height());
        l->show();
        end=true;
    }
    else if(i==-1)
    {
        QLabel* l=new QLabel;
        QString str;
        str=tr("你坚持了")+QString::fromUtf8(std::to_string(days))+tr("天，游戏结束！鼠标单击以返回开始界面，");
        l->setText(str);
        l->setParent(this);
        l->setStyleSheet(" border-image: url(:/new/pics/resouce/notice.png)");
        l->setGeometry(width()/2-400/2,height()/2-300/2,400,300);
        l->show();
        end=true;
    }
}


void mainw::e_happen(int idx){
    Event_*e=new Event_(idx,this);
    e->setGeometry((width()-e->width())/2,(height()-e->height())/2,e->width(),e->height());
    e->show();
    showitems();
}

void mainw::on_exit_clicked()
{
    close();
}


void mainw::on_menu__clicked()
{
    m->show();
}


void mainw::on_pc_clicked()
{
    p->show();
}


void mainw::on_bu_clicked()
{
    b=new buildings(game);
    b->setGeometry((width()-760)/2,(height()-483)/2,b->width(),b->height());
    b->covery();
    b->show();
}

