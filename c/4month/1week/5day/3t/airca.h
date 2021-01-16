#ifndef AIRCA_H
#define AIRCA_H

#include <QMainWindow>

namespace Ui {
class Airca;
}

class Airca : public QMainWindow
{
    Q_OBJECT

public:
    explicit Airca(QWidget *parent = nullptr);
    ~Airca();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Airca *ui;
};

#endif // AIRCA_H
