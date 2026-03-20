#include "networkmanage.h"
#include <QJsonObject>
#include <QJsonDocument>

NetWorkManage::NetWorkManage(QObject *parent)
    : QObject{parent}
{
    m_socket = new QTcpSocket(this);
    // ====================== 连接服务器 ======================
    QString serverIP = "119.45.230.124"; // 你的服务器IP
    quint16 port = 50000;                // 你的端口
    m_socket->connectToHost(QHostAddress(serverIP), port);
    // 绑定信号槽
    connect(m_socket, &QTcpSocket::connected,this, &NetWorkManage::onConnected);
    connect(m_socket, &QTcpSocket::disconnected,this, &NetWorkManage::onDisconnected);
    connect(m_socket,&QTcpSocket::readyRead,this,&NetWorkManage::getMessage);
}

void NetWorkManage::recvAccount(QString account)
{
    m_account = account;
    qDebug() << "NetWorkManage已接收账户信息：" << m_account;
}

// 连接成功
void NetWorkManage::onConnected()
{
    qDebug() << "已连接到服务器！";
    // 连接成功后，如果已有账户信息，立即发送
    if (!m_account.isEmpty()) {
        sendAccountToServer();
    }
}

// 断开连接
void NetWorkManage::onDisconnected()
{
    qDebug() << "与服务器断开连接";
}

void NetWorkManage::sendAccountToServer()
{
    if (m_account.isEmpty()) {
        qWarning() << "账户信息为空，无法发送";
        return;
    }
    if (m_socket->state() != QTcpSocket::ConnectedState) {
        qWarning() << "Socket未连接，发送账户信息失败";
        return;
    }
    // 发送账户信息（建议加标识，方便服务器解析，比如前缀"LOGIN:"）
    QByteArray sendData = QString("LOGIN:%1").arg(m_account).toUtf8();
    qint64 writeLen = m_socket->write(sendData);
    if (writeLen == -1) {
        qCritical() << "发送账户信息失败：" << m_socket->errorString();
    } else {
        qDebug() << "成功向服务器发送账户信息，字节数：" << writeLen << "，内容：" << sendData;
        // 可选：立即刷新缓冲区，确保数据发送出去
        m_socket->flush();
    }
}

void NetWorkManage::getMessageFromMainWindow(QString target_user,QString message)
{
    qDebug() << "Net: " + message;
    QJsonObject jsonObj;
    jsonObj["to"] = target_user;
    jsonObj["msg"] = message;
    QJsonDocument jsonDoc(jsonObj);
    QByteArray jsonData = jsonDoc.toJson(QJsonDocument::Compact); // 无格式JSON
    m_socket->write(jsonData);
}

void NetWorkManage::getMessage()
{
    QString message = m_socket->readAll();
    qDebug() << "getmessage: "+message;
    emit sendGetOneMessageToMainWindow(message);
}
