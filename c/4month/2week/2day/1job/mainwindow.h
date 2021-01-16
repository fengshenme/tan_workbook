#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QByteArray>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static void recursion(QString dir_path);

private slots:
    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    QString fileName;
};
#endif // MAINWINDOW_H
