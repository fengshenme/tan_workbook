#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>

namespace Ui {
class MainWin;
}

class MainWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWin(QWidget *parent = nullptr);
    ~MainWin();

private slots:
    void on_retbt_clicked();
    void funca(QString, QString);

    void on_airWin_clicked();

    void on_conLampWin_clicked();

private:
    Ui::MainWin *ui;

};

#endif // MAINWIN_H
