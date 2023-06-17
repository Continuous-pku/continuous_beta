#ifndef PCHOICE_H
#define PCHOICE_H

#include <QWidget>

namespace Ui {
class pchoice;
}

class pchoice : public QWidget
{
    Q_OBJECT

public:
    explicit pchoice(QWidget *parent = nullptr);
    ~pchoice();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    //void set_title(QString& s);
    //void set_picture

private:
    Ui::pchoice *ui;
};

#endif // PCHOICE_H
