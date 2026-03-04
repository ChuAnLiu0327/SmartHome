#ifndef AICHAT_H
#define AICHAT_H

#include <QObject>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class AiChat : public QObject
{
    Q_OBJECT
public:
    explicit AiChat(QObject *parent = nullptr);

    void sendGetRequest();

public slots:
    void ChatToAi(QString messageFromUser);
    void handleReadyRead();
    void handleError(QNetworkReply::NetworkError error);

signals:
    void SendToUserAnsower(QString Ansower);

private:
    QNetworkAccessManager *m_networkManager;
    QNetworkRequest m_baseRequest;  // 基础请求对象
    QJsonObject m_baseRequestBody;  // 基础请求体
    QNetworkReply *m_currentReply;  // 当前活动的回复对象

};

#endif // AICHAT_H
