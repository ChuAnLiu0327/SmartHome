#include "UserDbManager.h"
#include <QCryptographicHash>
#include <QDebug>

UserDbManager::UserDbManager(QObject *parent) : QObject(parent)
{
}

bool UserDbManager::connectToDatabase(const QString &host, int port,
                                      const QString &dbName, const QString &user,
                                      const QString &password)
{
    // 1. 注意这里改成 "QODBC"！
    if (QSqlDatabase::contains("user_connection")) {
        m_db = QSqlDatabase::database("user_connection");
    } else {
        m_db = QSqlDatabase::addDatabase("QODBC", "user_connection");
    }

    // 2. 构建 ODBC 连接字符串 (DSN)
    // 注意：如果你安装的 ODBC 版本不是 8.0，需要去 ODBC 数据源里看一下具体名字
    QString dsn = QString("DRIVER={MySQL ODBC 9.6 Unicode Driver};"
                          "SERVER=%1;"
                          "PORT=%2;"
                          "DATABASE=%3;"
                          "UID=%4;"
                          "PWD=%5;"
                          "OPTION=3;")
                      .arg(host)
                      .arg(port)
                      .arg(dbName)
                      .arg(user)
                      .arg(password);

    // 3. ODBC 模式下，把整个连接字符串 setDatabaseName 即可
    m_db.setDatabaseName(dsn);

    if (!m_db.open()) {
        m_lastError = m_db.lastError().text();
        qDebug() << "ODBC 连接失败:" << m_lastError;
        return false;
    }

    qDebug() << "ODBC 数据库连接成功!";
    return true;
}

QString UserDbManager::hashPassword(const QString &password)
{
    // 示例：使用 SHA256 进行哈希 (实际项目建议加盐并使用更安全的算法)
    QByteArray data = password.toUtf8();
    QByteArray hash = QCryptographicHash::hash(data, QCryptographicHash::Sha256);
    return QString(hash.toHex());
}

bool UserDbManager::addUser(const QString &username, const QString &password)
{
    if (!m_db.isOpen()) return false;

    QSqlQuery query(m_db);
    // 使用预处理语句防止 SQL 注入
    query.prepare("INSERT INTO users (username, password_hash) VALUES (:username, :pwd)");
    query.bindValue(":username", username);
    query.bindValue(":pwd", hashPassword(password)); // 存储哈希值

    if (!query.exec()) {
        m_lastError = query.lastError().text();
        // 这里可以判断是否是因为用户名重复导致的错误
        if (m_lastError.contains("Duplicate entry")) {
            m_lastError = "用户名已存在";
        }
        return false;
    }
    return true;
}

bool UserDbManager::deleteUser(int userId)
{
    if (!m_db.isOpen()) return false;

    QSqlQuery query(m_db);
    query.prepare("DELETE FROM users WHERE id = :id");
    query.bindValue(":id", userId);

    if (!query.exec()) {
        m_lastError = query.lastError().text();
        return false;
    }
    return query.numRowsAffected() > 0; // 返回是否真的删除了数据
}

bool UserDbManager::deleteUser(const QString &username)
{
    if (!m_db.isOpen()) return false;

    QSqlQuery query(m_db);
    query.prepare("DELETE FROM users WHERE username = :name");
    query.bindValue(":name", username);

    if (!query.exec()) {
        m_lastError = query.lastError().text();
        return false;
    }
    return query.numRowsAffected() > 0;
}

bool UserDbManager::updatePassword(int userId, const QString &newPassword)
{
    if (!m_db.isOpen()) return false;

    QSqlQuery query(m_db);
    query.prepare("UPDATE users SET password_hash = :pwd WHERE id = :id");
    query.bindValue(":pwd", hashPassword(newPassword));
    query.bindValue(":id", userId);

    if (!query.exec()) {
        m_lastError = query.lastError().text();
        return false;
    }
    return query.numRowsAffected() > 0;
}

bool UserDbManager::verifyUser(const QString &username, const QString &password)
{
    if (!m_db.isOpen()) return false;

    QSqlQuery query(m_db);
    query.prepare("SELECT password_hash FROM users WHERE username = :name");
    query.bindValue(":name", username);

    if (!query.exec()) {
        m_lastError = query.lastError().text();
        return false;
    }

    if (query.next()) {
        QString storedHash = query.value(0).toString();
        QString inputHash = hashPassword(password);
        return storedHash == inputHash; // 比对哈希值
    }

    return false; // 用户名不存在
}

QList<UserInfo> UserDbManager::getAllUsers()
{
    QList<UserInfo> list;
    if (!m_db.isOpen()) return list;

    QSqlQuery query(m_db);
    query.exec("SELECT id, username FROM users ORDER BY id DESC");

    while (query.next()) {
        UserInfo info;
        info.id = query.value(0).toInt();
        info.username = query.value(1).toString();
        list.append(info);
    }
    return list;
}

QString UserDbManager::lastError() const
{
    return m_lastError;
}
