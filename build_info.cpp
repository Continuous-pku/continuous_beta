#include "build_info.h"
#include "ui_build_info.h"

build_info::build_info(Building *build,QWidget *parent) :
    QWidget(parent),
    b(build),
    ui(new Ui::build_info)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    show_i();
}

build_info::~build_info()
{
    delete ui;
}

void build_info::show_i()
{
    ui->act->setText(QString::fromUtf8(to_string(b->getaction_point_per_day())));
    if(b->level==1)
        ui->level_cost->setText(QString::fromUtf8(to_string(10)));
    else if(b->level==2)
        ui->level_cost->setText(QString::fromUtf8(to_string(20)));
    else ui->level_cost->setText(tr("已满级"));
    if(b->change_in_infection_likelihood==0) ui->protect->setText(tr("较差"));
    else if(b->change_in_infection_likelihood>0) ui->protect->setText(tr("差"));
    else if(b->change_in_infection_likelihood>=-0.00005) ui->protect->setText(tr("中等"));
    else if(b->change_in_infection_likelihood>=-0.0001) ui->protect->setText(tr("较好"));
    else ui->protect->setText(tr("极好"));
}

void build_info::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
    QWidget::paintEvent(event);
}

void build_info::show_p(int idx,QString name,int cost)
{

    QString tep=name+tr(":消耗")+QString::fromUtf8(to_string(cost))+tr("点行动力");
    QLabel* l=new QLabel();
    l->setParent(this);
    l->setText(tep);
    l->setGeometry(40,220+idx*15,200,17);
    l->show();
}
