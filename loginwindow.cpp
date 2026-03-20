#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>
#include <winsock.h>
#include <QSqlQuery>
#include <QSqlError>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);

    qDebug() << "支持的数据库驱动：" << QSqlDatabase::drivers();

    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName("119.45.230.124");
    m_db.setPort(3306);
    m_db.setDatabaseName("user_system_db");
    m_db.setUserName("lcaDB");
    m_db.setPassword("NHARP53YX76MpXbH");

    if (m_db.open()) {
        qDebug() << "数据库连接成功";

    } else {
        QString errorMsg = QString("数据库连接失败：%1").arg(m_db.lastError().text());
        qDebug() << errorMsg;
    }
}

LoginWindow::~LoginWindow()
{
    if (m_db.isOpen()) {
        m_db.close();
        qDebug() << "数据库连接已关闭";
    }
    delete ui;
    // 销毁主窗口（避免内存泄漏）
    if (m_mainWindow) {
        delete m_mainWindow;
    }
}

void LoginWindow::on_pushButton_login_clicked()
{
    QString account = ui->lineEdit_account->text().trimmed();
    QString password = ui->lineEdit_password->text().trimmed();

    if(account.isEmpty() || password.isEmpty()){
        QMessageBox::warning(this, "输入提示", "账号和密码不能为空！");
        return;
    }

    if (!m_db.isOpen()) {
        QMessageBox::critical(this, "数据库错误", "数据库连接已断开，请重试！");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT password FROM user_info WHERE account = :account");
    query.bindValue(":account", account);

    if (!query.exec()) {
        QString errorMsg = QString("查询失败：%1").arg(query.lastError().text());
        qDebug() << errorMsg;
        QMessageBox::critical(this, "查询错误", errorMsg);
        return;
    }

    if (query.next()) {
        QString dbPassword = query.value(0).toString();
        if (dbPassword == password) {
            QMessageBox::information(this, "登录成功", QString("欢迎，%1！\n您已成功登录系统。").arg(account));

            // ========== 核心：登录成功后跳转主窗口 ==========
            // 创建主窗口
            if (!m_mainWindow) {
                m_mainWindow = new MainWindow(account); // 堆上创建，避免销毁
                //主窗口关闭时退出程序
                connect(m_mainWindow, &MainWindow::destroyed, this, &LoginWindow::close);
            }
            // 2. 隐藏登录窗口
            this->hide();

            // 3. 显示主窗口
            m_mainWindow->show();

        } else {
            QMessageBox::warning(this, "登录失败", "密码错误，请重新输入！");
        }
    } else {
        QMessageBox::warning(this, "登录失败", "该账号未注册，请检查！");
    }
}
