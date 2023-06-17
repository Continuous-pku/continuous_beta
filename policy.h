#ifndef POLICY_H
#define POLICY_H

#include <QWidget>
#include"QStyleOption"
#include<QPainter>
#include"QMouseEvent"

namespace Ui {
class policy;
}

class policy : public QWidget
{
    Q_OBJECT

public:
    explicit policy(QWidget *parent = nullptr);
    ~policy();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_hesuan_clicked();

private:
    Ui::policy *ui;
};

#endif // POLICY_H
