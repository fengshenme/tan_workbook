#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void mysignal();

//槽函数的声明;
private slots:
    void asfunc(QString, int);

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

    void on_lineEdit_editingFinished();


    void on_lineEdit_returnPressed();

    void on_lineEdit_selectionChanged();

    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    int count;
    bool lflags;
};

#endif // MAINWINDOW_H
