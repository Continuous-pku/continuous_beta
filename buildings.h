#ifndef BUILDINGS_H
#define BUILDINGS_H

#include <QWidget>
#include"class.h"

class QTreeWidgetItem;
class b_upgrade;
class mainw;

namespace Ui {
class buildings;
}

class buildings : public QWidget
{
    Q_OBJECT

public:
    explicit buildings(Game* game, mainw *parent = nullptr);
    ~buildings();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void covery();
    Game* g;
    mainw* _parent;
    QStringList options;

private slots:
    void on_treeWidget_itemPressed(QTreeWidgetItem *item, int column);

private:
    bool outl=false;
    Ui::buildings *ui;
    b_upgrade* son=nullptr;

};

#endif // BUILDINGS_H
