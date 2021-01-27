#ifndef AIRWIN_H
#define AIRWIN_H

#include <QMainWindow>

namespace Ui {
class AirWin;
}

class AirWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit AirWin(QWidget *parent = nullptr);
    ~AirWin();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_retpb_clicked();

private:
    Ui::AirWin *ui;
};

#endif // AIRWIN_H
