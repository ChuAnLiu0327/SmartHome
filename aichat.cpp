#include "aichat.h"
#include <QNetworkProxyFactory>

#define GLM_API_KEY ""
#define GLM_STREAM_URL "https://open.bigmodel.cn/api/paas/v4/chat/completions"

AiChat::AiChat(QObject *parent)
    : QObject{parent}
    , m_currentReply(nullptr)
{
    m_networkManager = new QNetworkAccessManager(this);

    // 2. 创建并配置基础请求对象
    m_baseRequest = QNetworkRequest(QUrl("https://open.bigmodel.cn/api/paas/v4/chat/completions"));
    m_baseRequest.setRawHeader("Authorization", GLM_API_KEY);
    m_baseRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    m_baseRequest.setRawHeader("Accept", "text/event-stream");
    m_baseRequest.setRawHeader("Connection", "keep-alive");
    m_baseRequest.setPriority(QNetworkRequest::HighPriority);

    // 3. 设置基础请求体模板
    m_baseRequestBody["model"] = "glm-4.7";
    m_baseRequestBody["stream"] = true;

    // 4. 添加thinking参数（按需启用或禁用）
    QJsonObject thinkingObj;
    thinkingObj["type"] = "disabled";  // 启用思考过程
    // thinkingObj["type"] = "disabled";  // 禁用思考过程
    m_baseRequestBody["thinking"] = thinkingObj;

}


void AiChat::ChatToAi(QString messageFromUser)
{
    qDebug() << messageFromUser;

    // 如果当前有未完成的请求，先取消它
    if (m_currentReply && m_currentReply->isRunning()) {
        m_currentReply->abort();
        m_currentReply->deleteLater();
        m_currentReply = nullptr;
    }

    // 1. 复制基础请求对象
    QNetworkRequest request = m_baseRequest;

    QJsonObject requestBody = m_baseRequestBody;  // 复制基础体

    QJsonArray messages;
    QJsonObject message;
    message["role"] = "user";
    message["content"] = messageFromUser;
    messages.append(message);
    requestBody["messages"] = messages;

    // 3. 发送POST请求
    QByteArray postData = QJsonDocument(requestBody).toJson();
    m_currentReply = m_networkManager->post(request, postData);

    // 4. 连接信号槽处理响应
    connect(m_currentReply, &QNetworkReply::readyRead, this, &AiChat::handleReadyRead);
    connect(m_currentReply, &QNetworkReply::finished, this, [this]() {
        if (m_currentReply) {
            m_currentReply->deleteLater();
            m_currentReply = nullptr;
        }
        qDebug() << "请求完成";
    });

    // 5. 错误处理
    connect(m_currentReply, &QNetworkReply::errorOccurred, this, &AiChat::handleError);
}

void AiChat::handleReadyRead()
{
    if (!m_currentReply) return;

    // 读取所有数据
    QByteArray data = m_currentReply->readAll();

    // 按行分割处理（SSE格式）
    QStringList lines = QString(data).split("\n", Qt::SkipEmptyParts);

    for (const QString& line : lines)
    {
        if (line.startsWith("data: "))
        {
            QString jsonStr = line.mid(6); // 去掉"data: "

            // 检查流是否结束
            if (jsonStr.trimmed() == "[DONE]")
            {
                qDebug() << "流传输完成";
                return;
            }

            // 解析JSON
            QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8());
            if (!doc.isNull() && doc.isObject())
            {
                QJsonObject obj = doc.object();
                QJsonArray choices = obj["choices"].toArray();

                if (!choices.isEmpty())
                {
                    QJsonObject delta = choices[0].toObject()["delta"].toObject();
                    QString content = delta["content"].toString();

                    if (!content.isEmpty())
                    {
                        emit SendToUserAnsower(content);
                        qDebug() << "AI回复:" << content;
                    }
                }
            }
        }
    }
}

void AiChat::handleError(QNetworkReply::NetworkError error)
{
    if (!m_currentReply) return;

    qDebug() << "网络错误:" << error << m_currentReply->errorString();

    // 根据错误类型处理
    if (error == QNetworkReply::OperationCanceledError) {
        qDebug() << "请求被取消";
    } else {
        emit SendToUserAnsower("网络错误: " + m_currentReply->errorString());
    }
}
