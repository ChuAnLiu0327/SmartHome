#include "loginwindow.h"  // 替换为登录窗口头文件
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 启动登录窗口（而非直接启动主窗口）
    LoginWindow w;
    w.show();
    return a.exec();
}
