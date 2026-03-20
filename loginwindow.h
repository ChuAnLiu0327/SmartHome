#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QDialog>
#include "mainwindow.h"
#include <QThread>


namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();


private slots:
    void on_pushButton_login_clicked();

private:
    Ui::LoginWindow *ui;
    QSqlDatabase m_db;
    // 2. 声明主窗口指针（避免栈创建导致窗口销毁）
    MainWindow *m_mainWindow = nullptr;
signals:


};

#endif // LOGINWINDOW_H
