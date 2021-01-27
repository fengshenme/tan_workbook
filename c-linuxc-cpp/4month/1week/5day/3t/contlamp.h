#ifndef CONTLAMP_H
#define CONTLAMP_H

#include <QMainWindow>

namespace Ui {
class ContLamp;
}

class ContLamp : public QMainWindow
{
    Q_OBJECT

public:
    explicit ContLamp(QWidget *parent = nullptr);
    ~ContLamp();

private:
    Ui::ContLamp *ui;
};

#endif // CONTLAMP_H
