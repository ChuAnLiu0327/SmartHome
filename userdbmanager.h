#ifndef USERDBMANAGER_H
#define USERDBMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariantList>

struct UserInfo {
    int id;
    QString username;
    // 注意：从数据库查询时，通常不返回密码哈希到前端
};

class UserDbManager : public QObject
{
    Q_OBJECT
public:
    explicit UserDbManager(QObject *parent = nullptr);

    // 1. 连接数据库
    bool connectToDatabase(const QString &host, int port,
                           const QString &dbName, const QString &user,
                           const QString &password);

    // 2. 增：注册新用户
    bool addUser(const QString &username, const QString &password);

    // 3. 删：删除用户
    bool deleteUser(int userId);
    bool deleteUser(const QString &username);

    // 4. 改：修改密码
    bool updatePassword(int userId, const QString &newPassword);

    // 5. 查：验证用户登录 (验证用户名密码是否匹配)
    bool verifyUser(const QString &username, const QString &password);

    // 6. 查：获取所有用户列表 (不包含密码)
    QList<UserInfo> getAllUsers();

    // 获取最后一次错误信息
    QString lastError() const;

private:
    QSqlDatabase m_db;
    QString m_lastError;

    // 内部工具：简单的密码哈希 (实际项目推荐用 bcrypt 或 argon2)
    QString hashPassword(const QString &password);
};

#endif // USERDBMANAGER_H
