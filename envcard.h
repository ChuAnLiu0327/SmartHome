#ifndef ENVCARD_H
#define ENVCARD_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap> // 新增：用于加载图片

class EnvCard : public QWidget
{
    Q_OBJECT
public:
    // 构造函数修改：第一个参数改成「图标资源路径」，比如 ":/icons/temp_icon.png"
    explicit EnvCard(const QString& iconPath, const QString& title, const QString& unit, QWidget *parent = nullptr);

    // 对外暴露的设置接口
    void setValue(const QString& value); // 设置数值
    void setStatus(const QString& text, int statusType); // 设置状态 0=正常 1=警告 2=危险

private:
    QLabel *m_iconLabel;     // 图标标签（修改为显示图片）
    QLabel *m_valueLabel;    // 数值标签
    QLabel *m_unitLabel;     // 单位标签
    QLabel *m_statusLabel;   // 状态标签
};

#endif // ENVCARD_H
