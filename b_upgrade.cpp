#include "b_upgrade.h"
#include "ui_b_upgrade.h"
#include"QStyleOption"
#include"QPainter"
#include"QMouseEvent"
#include"buildings.h"
#include"note.h"
#include"build_info.h"

b_upgrade::b_upgrade(Building* build, QString text, buildings *parent) :
    b(build),
    ui(new Ui::b_upgrade)
{
    ui->setupUi(this);
    p=parent;
    this->setWindowFlags(Qt::FramelessWindowHint);

    pob[0]=&po1;
    pob[1]=&po2;
    pob[2]=&po3;
    pob[3]=&po4;

    options << tr("要求佩戴口罩")<< tr("测温扫码")<< tr("关闭建筑")<< tr("设置挡板")<< tr("停止堂食")<< tr("临时封控")<< tr("封闭宿舍");

    for(int i=0;i<b->total_number_of_available;++i)
    {
        po[i]=b->available_policy[i];
    }

    connect(&po1,SIGNAL(clicked()),this,SLOT(on_po1_clicked()));
    connect(&po2,SIGNAL(clicked()),this,SLOT(on_po2_clicked()));
    connect(&po3,SIGNAL(clicked()),this,SLOT(on_po3_clicked()));
    connect(&po4,SIGNAL(clicked()),this,SLOT(on_po4_clicked()));
    show_buttons();

    QFont font;
    font.setFamily("等线");
    font.setPointSize(22);

    ui->title->setText(text);
    ui->title->setFont(font);


    set_level(b->getLevel());

    if(b->getLevel()==3)
    {
        ui->pushButton->setText(tr("MAX"));
        ui->l3->setGeometry(105,295,0,41);
        ui->l2->setGeometry(105,342,0,41);
    }

    if(b->getLevel()==2)
    {
        ui->l2->setGeometry(105,342,0,41);
    }

    if(b->kind==0)
        ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/dormitory.png)");
    else if(b->kind==1)
    {
        if(b->idx==45)
            ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/nongyuand.png)");
        else if(b->idx==46)
            ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/yiyuand.png)");
        else if(b->idx==47)
            ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/jiayuand.png)");
        else if(b->idx==48)
            ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/shaoyuand.png)");
        else if(b->idx==49)
            ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/xueyi.png)");
        else if(b->idx==50)
            ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/xuewu.png)");
    }
    else if(b->kind==2)
    {
        if(b->idx==51)
            ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/yijiao.png)");
        else if(b->idx==52)
            ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/erjiao.png)");
        else if(b->idx==53)
            ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/sanjiao.png)");
        else if(b->idx==54)
            ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/sijiao.png)");
        else if(b->idx==55)
            ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/lijiao.png)");
        else if(b->idx==56||b->idx==57)
            ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/wenshi.png)");
    }
    else if(b->kind==3)
        ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/library.png)");
    else if(b->kind==4)
        ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/hospital.png)");
    else if(b->kind==5)
        ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/playground.png)");
    else if(b->kind==6)
    {

        if(b->idx==61)
            ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/54.png)");
        else
            ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/qdb.png)");
    }
    else if(b->kind==7)
        ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/lake.png)");
    else if(b->kind==8)
        ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/liyi.png)");
    else if(b->kind==9)
    {
        if(b->idx==66)
            ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/northgate.png)");
        else if(b->idx==67)
            ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/westgate.png)");
        else if(b->idx==68)
            ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/southwestgate.png)");
        else if(b->idx==69||b->idx==70)
            ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/southeastgate.png)");
        else
            ui->picture->setStyleSheet(" border-image: url(:/new/pics/resouce/buildings/image/eastgate.png)");
    }


    //设置info显示
    info=new build_info(b,parent->_parent);
    for(int i=0;i<b->total_number_of_available;++i)
    {
        info->show_p(i+1,options[po[i]->idx],po[i]->cost);
    }

    ui->l3->raise();
    ui->l2->raise();
}

void b_upgrade::show_buttons()
{
    int l1=0,l2=0,l3=0;
    for(int i=0;i<b->total_number_of_available;++i)
    {
        switch(po[i]->idx)
        {
        case 0:{++l1;break;}
        case 1:{++l2;break;}
        case 2:{++l3;break;}
        case 3:{++l1;break;}
        case 4:{++l3;break;}
        case 5:{++l2;break;}
        case 6:{++l3;break;}
        };
    }
    int x=0,y=0;
    for(int i=0;i<b->total_number_of_available;++i)
    {
        switch(po[i]->idx)
        {
        case 0:{x=1;y=395;break;}
        case 1:{x=2;y=350;break;}
        case 2:{x=3;y=305;break;}
        case 3:{x=1;y=395;break;}
        case 4:{x=3;y=305;break;}
        case 5:{x=2;y=350;break;}
        case 6:{x=3;y=305;break;}
        };
        pob[i]->setParent(this);
        pob[i]->setText(options[po[i]->idx]);
        if(x==1)
        {
            if(l1==1) x=180;
            else if(l1==2) {x=120;l1=-1;}
            else if(l1==-1) x=230;
        }
        else if(x==2)
        {
            if(l2==1) x=180;
            else if(l2==2) {x=120;l1=-1;}
            else if(l2==-1) x=230;
        }
        else if(x==3)
        {
            if(l3==1) x=180;
            else if(l3==2) {x=120;l1=-1;}
            else if(l3==-1) x=230;
        }
        pob[i]->setGeometry(x,y,101,29);
        pob[i]->show();
        if (b->policy_state[i] == 2)
        {
            QLabel* a=new QLabel;
            a->setParent(this);
            a->setStyleSheet(" border-image: url(:/new/pics/resouce/have_done.png)");
            a->setGeometry(x,y-20,91,61);
            a->show();
        }
    }
}

b_upgrade::~b_upgrade()
{
    delete ui;
}

void b_upgrade::set_level(int level)
{
    if(level==1)
        ui->level->setGeometry(50,385,51,43);
    else if(level==2)
        ui->level->setGeometry(50,340,51,88);
    else if(level==3)
        ui->level->setGeometry(50,300,51,128);
}

void b_upgrade::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
    QWidget::paintEvent(event);
}

void b_upgrade::mousePressEvent(QMouseEvent *event)
{
    QPointF pl=event->globalPosition();
    int x=pl.x(),y=pl.y();
    QRect tep=this->geometry();
    x=x-tep.x();
    y=y-tep.y();

    //qDebug()<<x<<' '<<y;

    if(x>=400&&x<=430&&y>=10&&y<=40)
    {
        close();
        p->close();
        info->close();
        delete info;
        delete p;
        delete this;
    }
}


void b_upgrade::on_pushButton_clicked()
{
    if(b->getLevel()==3) return;
    if (p->g->cost_ap(b->upgrade_cost[b->level]))
    {
    p->g->cost_ap(b->upgrade_cost[b->level]);
    b->upgrade();
    set_level(b->getLevel());
    if(b->getLevel()==3)
        ui->pushButton->setText(tr("MAX"));
    if(b->getLevel()==3)
    {
            ui->l3->setGeometry(105,295,0,41);
            ui->l2->setGeometry(105,342,0,41);
    }

    if(b->getLevel()==2)
    {
            ui->l2->setGeometry(105,342,0,41);
    }
    info->show_i();
    QString tep=p->options[b->idx]+tr("升级到了")+QString::fromUtf8(to_string(b->getLevel()))+tr("级");
                  if(b->kind==0) tep+='\n'+tr("这个宿舍每天提供的行动力增加了");
    b->g->win->a_text(tep);
    }
    else{
        note* n=new note(this);
        n->Note(this,b->upgrade_cost[b->level],500);
        n->setGeometry(83,160,n->width(),n->height());
        n->show();
    }
}


void b_upgrade::show_policy_up(int i)
{
    QString tep=p->options[b->idx]+tr("已颁布政策")+options[po[i]->idx]+'\n';
switch(po[i]->idx)
    {
    case 0:{tep+=tr("场所的防疫能力大幅提升了");break;}
    case 1:{tep+=tr("场所防疫能力小幅提升");break;}
    case 2:{;break;}
    case 3:{tep+=tr("场所防疫能力大幅提升了");break;}
    case 4:{;break;}
    case 5:{;break;}
    }

    b->g->win->a_text(tep);
}

void b_upgrade::on_po1_clicked()
{
    //qDebug()<<"po1!";
    if (b->policy_state[0] == 0||b->policy_state[0] == 2) {
        return;
    }
    else {
        if (p->g->cost_ap(po[0]->cost))
        {
        b->enactPolcy(0);
        if (b->isShutDown())
            p->g->is_building_shut_down = true;

        QLabel* a=new QLabel;
        a->setParent(this);
        a->setStyleSheet(" border-image: url(:/new/pics/resouce/have_done.png)");
        a->setGeometry(po1.x(),po1.y()-20,91,61);
        a->show();
        show_policy_up(0);
        }
        else
        {
        note* n=new note(this);
        n->Note(this,po[0]->cost,500);
        n->setGeometry(83,160,n->width(),n->height());
        n->show();
        }
    }
}

void b_upgrade::on_po2_clicked()
{
    //qDebug()<<"po1!";
    if (b->policy_state[1] == 0||b->policy_state[1] == 0) {
        return;
    }
    else {
        if (p->g->cost_ap(po[1]->cost))
        {
        b->enactPolcy(1);
        if (b->isShutDown())
            p->g->is_building_shut_down = true;
        QLabel* a=new QLabel;
        a->setParent(this);
        a->setStyleSheet(" border-image: url(:/new/pics/resouce/have_done.png)");
        a->setGeometry(po2.x(),po2.y()-20,91,61);
        a->show();
        show_policy_up(1);
        }
        else
        {
        note* n=new note(this);
        n->Note(this,po[1]->cost,500);
        n->setGeometry(83,160,n->width(),n->height());
        n->show();
        }
    }

}

void b_upgrade::on_po3_clicked()
{
    //qDebug()<<"po1!";
    if (b->policy_state[2] == 0||b->policy_state[2] == 2) {
        return;
    }
    else {
        if (p->g->cost_ap(po[2]->cost))
        {
        b->enactPolcy(2);
        if (b->isShutDown())
            p->g->is_building_shut_down = true;
        QLabel* a=new QLabel;
        a->setParent(this);
        a->setStyleSheet(" border-image: url(:/new/pics/resouce/have_done.png)");
        a->setGeometry(po3.x(),po3.y()-20,91,61);
        a->show();
        show_policy_up(2);
        }
        else
        {
        note* n=new note(this);
        n->Note(this,po[2]->cost,500);
        n->setGeometry(83,160,n->width(),n->height());
        n->show();
        }
    }

}

void b_upgrade::on_po4_clicked()
{
    //qDebug()<<"po1!";
    if (b->policy_state[3] == 0) {
        return;
    }
    else {
        if (p->g->cost_ap(po[3]->cost))
        {
        b->enactPolcy(3);
        if (b->isShutDown())
            p->g->is_building_shut_down = true;
        QLabel* a=new QLabel;
        a->setParent(this);
        a->setStyleSheet(" border-image: url(:/new/pics/resouce/have_done.png)");
        a->setGeometry(po4.x(),po4.y()-20,91,61);
        a->show();
        show_policy_up(3);
        }
        else
        {
        note* n=new note(this);
        n->Note(this,po[3]->cost,500);
        n->setGeometry(83,160,n->width(),n->height());
        n->show();
        }
    }
}
