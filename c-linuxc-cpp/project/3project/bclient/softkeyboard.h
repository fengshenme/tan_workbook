#ifndef SOFTKEYBOARD_H
#define SOFTKEYBOARD_H


#include <QWidget>
#include <QPushButton>
#include <QKeyEvent>
#include <QCoreApplication>
#include <QApplication>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class SoftKeyBoard;
}
QT_END_NAMESPACE

class SoftKeyBoard : public QWidget
{
    Q_OBJECT

public:
     SoftKeyBoard(QWidget *parent = nullptr);
    ~SoftKeyBoard();
    bool transflags;

public slots:
    void transUpperOrLower();
    void keyEvent();

signals:
    void trans();

private:
    Ui::SoftKeyBoard *ui;
    QList<QPushButton *> mblist;
};

#endif // SOFTKEYBOARD_H
