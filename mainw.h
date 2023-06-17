#ifndef MAINW_H
#define MAINW_H

#include <QWidget>
#include "ui_mainw.h"
#include"event_.h"

class Game;
class buildings;
class menu;
class policy;


namespace Ui {
class mainw;
}

class mainw : public QWidget
{
    Q_OBJECT

public:
    explicit mainw(QWidget *upper,QWidget *parent = nullptr);
    ~mainw();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    QString yearmonth;
    int normalize_x(int x);
    int normalize_y(int y);
    void a_text(QString s);
    void showitems();
    void showap();
    void e_happen(int idx);

    Game* game;
    QLabel*year_month,*day,*sat,*ap,*infect;
    buildings* b;
    menu *m;
    policy *p;

    int days=0;

private slots:
    void on_pushButton_clicked();

    void on_exit_clicked();

    void on_menu__clicked();

    void on_pc_clicked();

    void on_bu_clicked();

private:
    Ui::mainw *ui;
    bool end=false;
    QWidget* up;
};

#endif // MAINW_H
