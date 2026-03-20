#include "envcard.h"
#include <QGraphicsDropShadowEffect>

EnvCard::EnvCard(const QString& iconPath, const QString& title, const QString& unit, QWidget *parent)
    : QWidget(parent)
{
    // 卡片基础样式保持不变
    this->setStyleSheet(R"(
        EnvCard {
            background-color: white;
            border-radius: 12px;
        }
    )");
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(15);
    shadow->setColor(QColor(0,0,0,10));
    shadow->setOffset(0,2);
    this->setGraphicsEffect(shadow);

    // 整体垂直布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(24, 24, 24, 24);
    mainLayout->setSpacing(16);

    // ========== 核心修改：顶部图标+标题行，改成显示图片 ==========
    QHBoxLayout *titleLayout = new QHBoxLayout();
    titleLayout->setSpacing(8);

    // 1. 图标标签：加载并显示图标文件
    m_iconLabel = new QLabel();
    // 加载图标，缩放到32x32像素，保持比例，平滑抗锯齿
    QPixmap iconPixmap(iconPath);
    m_iconLabel->setPixmap(iconPixmap.scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // 2. 标题标签
    QLabel *titleLabel = new QLabel(title);
    titleLabel->setStyleSheet("font-size: 18px; color: #333;");

    titleLayout->addWidget(m_iconLabel);
    titleLayout->addWidget(titleLabel);
    titleLayout->addStretch();

    // 数值+单位行（保持不变）
    QHBoxLayout *valueLayout = new QHBoxLayout();
    valueLayout->setSpacing(4);
    m_valueLabel = new QLabel("--");
    m_valueLabel->setStyleSheet("font-size: 32px; font-weight: bold; color: #222;");
    m_unitLabel = new QLabel(unit);
    m_unitLabel->setStyleSheet("font-size: 18px; color: #666; padding-top: 12px;");
    valueLayout->addWidget(m_valueLabel);
    valueLayout->addWidget(m_unitLabel);
    valueLayout->addStretch();

    // 状态标签（保持不变）
    m_statusLabel = new QLabel("正常");
    m_statusLabel->setStyleSheet(R"(
        background-color: #ecfdf5;
        color: #059669;
        padding: 4px 12px;
        border-radius: 16px;
        font-size: 14px;
    )");

    // 组装布局
    mainLayout->addLayout(titleLayout);
    mainLayout->addLayout(valueLayout);
    mainLayout->addWidget(m_statusLabel);
    mainLayout->addStretch();
}

// 下面两个函数完全不用改，保持原样
void EnvCard::setValue(const QString& value)
{
    m_valueLabel->setText(value);
}

void EnvCard::setStatus(const QString& text, int statusType)
{
    m_statusLabel->setText(text);
    QString style;
    if(statusType == 0) { // 正常/安全
        style = R"(
            background-color: #ecfdf5;
            color: #059669;
            padding: 4px 12px;
            border-radius: 16px;
            font-size: 14px;
        )";
    } else if(statusType == 1) { // 警告/轻度污染
        style = R"(
            background-color: #fff7ed;
            color: #ea580c;
            padding: 4px 12px;
            border-radius: 16px;
            font-size: 14px;
        )";
    } else { // 危险/超标
        style = R"(
            background-color: #fef2f2;
            color: #dc2626;
            padding: 4px 12px;
            border-radius: 16px;
            font-size: 14px;
        )";
    }
    m_statusLabel->setStyleSheet(style);
}
