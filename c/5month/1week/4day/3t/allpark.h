#ifndef ALLPARK_H
#define ALLPARK_H

#include "cardsql.h"

#include <QMainWindow>

namespace Ui {
class AllPark;
}

class AllPark : public QMainWindow {
    Q_OBJECT

public:
    explicit AllPark(QWidget* parent = nullptr);
    ~AllPark();

private slots:
    void on_findAll_clicked();

    void on_prevBt_clicked();

    void on_findAll_pressed();

private:
    Ui::AllPark* ui;
};

#endif // ALLPARK_H
