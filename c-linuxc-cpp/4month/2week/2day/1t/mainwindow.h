#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QByteArray>
#include <QMenuBar>
#include <QMenu>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openfile();

private:
    Ui::MainWindow *ui;

     QString fileName;

};
#endif // MAINWINDOW_H
