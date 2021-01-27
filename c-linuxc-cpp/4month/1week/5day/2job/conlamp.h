#ifndef CONLAMP_H
#define CONLAMP_H

#include <QMainWindow>

namespace Ui {
class ConLamp;
}

class ConLamp : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConLamp(QWidget *parent = nullptr);
    ~ConLamp();

private slots:
    void on_pushButton_clicked();

    void on_switchON_clicked();

private:
    Ui::ConLamp *ui;
    bool flag_lamp;
};

#endif // CONLAMP_H
