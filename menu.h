#ifndef MENU_H
#define MENU_H

#include <QWidget>

namespace Ui {
class menu;
}

class menu : public QWidget
{
    Q_OBJECT

public:
    explicit menu(QWidget *_parent = nullptr);
    ~menu();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    QWidget* parent;


private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_exit_clicked();

private:
    Ui::menu *ui;
};

#endif // MENU_H
