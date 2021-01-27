#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QByteArray>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     void recursion(QString dir_path);

private slots:


    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_actionopen_triggered();
    void open_file(QString allpath);
    void save_file(QString allpath);

    void on_actionsave_triggered();

private:
    Ui::MainWindow *ui;
    QString d_path;
    QString allpath;

};
#endif // MAINWINDOW_H
