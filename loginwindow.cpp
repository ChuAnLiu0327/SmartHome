#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_login_clicked()
{
    QString account = ui->lineEdit_account->text();
    QString password = ui->lineEdit_password->text();

    // 需要连接数据库(之后会更新)
    if(account == "1821" && password == "1234")
    {
        QMessageBox::information(this, "登录成功",
        QString("欢迎，%1！\n您已成功登录系统。").arg(account));
    }
    else
    {
        QMessageBox::warning(this, "警告", "输入不能为空！");
    }

}

