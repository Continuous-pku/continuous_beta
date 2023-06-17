#ifndef B_UPGRADE_H
#define B_UPGRADE_H

#include <QWidget>
#include"class.h"

class buildings;
class build_info;

namespace Ui {
class b_upgrade;
}

class b_upgrade : public QWidget
{
    Q_OBJECT

public:
    explicit b_upgrade(Building* build, QString text, buildings *parent = nullptr);
    ~b_upgrade();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    buildings* p;
    Building* b;
    build_info* info;
    QPushButton *pob[4],po1,po2,po3,po4;
    Policy *po[10];
    void show_policy_up(int i);

private slots:

    void on_pushButton_clicked();
    void on_po1_clicked();
    void on_po2_clicked();
    void on_po3_clicked();
    void on_po4_clicked();

private:
    Ui::b_upgrade *ui;
    void set_level(int i);
    void show_buttons();
    QStringList options;
};

#endif // B_UPGRADE_H
