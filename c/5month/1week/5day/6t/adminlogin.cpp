#include "adminlogin.h"
#include "ui_adminlogin.h"

AdminLogin::AdminLogin(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminLogin)
{
    ui->setupUi(this);

    setWindowTitle("管理员登录");

    ui->skboard->hide();

    count = 3;
    this->setStyleSheet("AdminLogin{background-image: url(:/new/prefix1/img/27.jpg);}");
    show_head();
    ui->skboard->show();
}

AdminLogin::~AdminLogin()
{
    delete ui;
}

void AdminLogin::show_head()
{

    // 圆形显示
    QPixmap pap(":/new/prefix1/img/23.jpg");
    //        pap.loadFromData(byar);
    pap.scaled(QSize(100, 100), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    pap = PixmapToRound(pap, 50);
    ui->label_3->setPixmap(pap);
}

QPixmap AdminLogin::PixmapToRound(const QPixmap& src, int radius)
{
    if (src.isNull()) {
        return QPixmap();
    }
    QSize size(2 * radius, 2 * radius);
    QBitmap mask(size);
    QPainter painter(&mask);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.fillRect(0, 0, size.width(), size.height(), Qt::white);
    painter.setBrush(QColor(0, 0, 0));
    painter.drawRoundedRect(0, 0, size.width(), size.height(), 99, 99);
    QPixmap image = src.scaled(size);
    image.setMask(mask);
    return image;
}

void AdminLogin::closeEvent(QCloseEvent*)
{
    this->parentWidget()->show();
}

void AdminLogin::on_loginG_clicked()
{
    QString name = ui->usele->text();
    QString passw = ui->passwle->text();

    QString usestat = QString("m:login:%1:%2").arg(name).arg(passw);
    qDebug() << usestat;

    if (name == "admin" && passw == "123456") {
        qDebug() << "login success";

        Admin* ad = new Admin(this);

        //登录成功到主界面
        //        connect(this,SIGNAL(messma(QByteArray)), newwin, SLOT(func2(QByteArray)));
        //                ad->setAttribute(Qt::WA_DeleteOnClose); // 关闭及删除
        ad->show();
        ui->passwle->clear();
        ui->usele->clear();
        this->hide();

    } else {
        count--;

        QString text = QString("账号密码错误 ,还可以尝试 %1 次").arg(count);
        QMessageBox::StandardButton ifl = QMessageBox::information(this, "登录提示", text, QMessageBox::Ok | QMessageBox::Cancel);
        if (ifl == QMessageBox::Ok) {
            qDebug() << "success";
        } else if (ifl == QMessageBox::Cancel) {
            qDebug() << "Cancel";
        }

        if (count <= 0) {
            count = 3;

            ui->usele->setEnabled(false);
            ui->passwle->setEnabled(false);
            ui->loginG->setEnabled(false);
        }
    }
}

void AdminLogin::on_softkeyboard_clicked()
{
    if (ui->skboard->isHidden()) {
        ui->skboard->show();
    } else {
        ui->skboard->hide();
    }
}

void AdminLogin::on_pushButton_clicked()
{
    this->parentWidget()->show();
    this->close();
}
