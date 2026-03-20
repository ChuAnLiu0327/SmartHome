#ifndef NETWORKMANAGE_H
#define NETWORKMANAGE_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>

class NetWorkManage : public QObject
{
    Q_OBJECT
public:
    explicit NetWorkManage(QObject *parent = nullptr);

public slots:
    void onConnected();       // 连接成功
    void onDisconnected();    // 断开连接
    void recvAccount(QString account);
    void sendAccountToServer();
    void getMessageFromMainWindow(QString target_user,QString message);
    void getMessage();

private:
    QTcpSocket* m_socket;
    QString m_account;

signals:
    void sendMessageToMainWindow(QString message);
    void sendGetOneMessageToMainWindow(QString message);
};

#endif // NETWORKMANAGE_H
