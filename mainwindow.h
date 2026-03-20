#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTextEdit>
#include <QThread>
#include <QListWidgetItem>
#include "envcard.h"
#include "chartmanager.h"
#include "networkmanage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(const QString& loginAccount = "",QWidget *parent = nullptr);
    ~MainWindow();
    void UI_init();

    void ImageTabWidget(const QString &imagePath,const QString &tabText,const QString &contentText,const QSize &imageSize);
    void appendAiBubbleText(QListWidgetItem* aiItem, const QString& appendChar);

private slots:
    void on_pushButton_ai_send_clicked();
    void GetAiAnsower(QString message);
    void sendMessageToNetWorkManage();
    void showOneMessage(QString message);

private:
    Ui::MainWindow *ui;
    QListWidgetItem* m_currentAiItem;
    // 【核心】新增成员变量：存储登录账号
    QString m_loginAccount;
    NetWorkManage *m_networkmanage;
    QThread *m_networkmanagethread;


    QWidget* createUserBubble(const QString& text);
    QWidget* createAiBubble(const QString& text);

    QListWidgetItem* createEmptyAiBubble();
    ChartManager* m_chartmanager;


    void addChatMessage(const QString& text, bool isUser);
    // 在这里加上函数声明！
    void addCardToWidget(QWidget *containerWidget, EnvCard *card);

    QWidget* createOneChatRecvBubble(const QString& text);
    QWidget* createOneChatSendBubble(const QString& text);
    void addOneChatMessage(const QString& text, bool isUser);

signals:
    void SendUserMessage(QString message);
    void sendAccount(QString account);
    void sendOneMessage(QString target_user,QString message);
};
#endif // MAINWINDOW_H
