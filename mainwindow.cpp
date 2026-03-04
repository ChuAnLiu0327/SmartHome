#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aichat.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    UI_init();


    AiChat *aichat = new AiChat; // ai聊天对象
    QThread *aichat_thread = new QThread;

    aichat->moveToThread(aichat_thread); // 移动到线程池中

    connect(this,&MainWindow::SendUserMessage,aichat,&AiChat::ChatToAi);
    connect(aichat,&AiChat::SendToUserAnsower,this,&MainWindow::GetAiAnsower);


    aichat_thread->start();


}

#define AI_ICON_PATH ":/new/prefix1/ai_new.png"
#define USER_ICON_PATH ":/new/prefix1/yh.png"

// 创建AI侧气泡
QWidget* MainWindow::createAiBubble(const QString& text)
{
    QWidget* bubbleWidget = new QWidget;
    QHBoxLayout* layout = new QHBoxLayout(bubbleWidget);
    layout->setContentsMargins(15, 8, 15, 8); // 气泡整体边距

    QLabel* iconLabel = new QLabel;
    // 加载icon并设置固定尺寸（40x40，可根据需求调整）
    QPixmap aiIcon(AI_ICON_PATH);
    if (!aiIcon.isNull()) { // 判空，避免icon加载失败导致崩溃
        iconLabel->setPixmap(aiIcon.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    iconLabel->setFixedSize(40, 40); // 固定icon大小，防止拉伸
    iconLabel->setStyleSheet("border-radius: 20px;"); // 可选：设置圆形icon（40x40对应20圆角）

    QLabel* textLabel = new QLabel(text);
    textLabel->setObjectName("AiBubbleLabel");
    textLabel->setWordWrap(true);
    textLabel->setMaximumWidth(ui->listWidget_chat->width() * 0.7);

    textLabel->setStyleSheet("QLabel#AiBubbleLabel { background-color: #e5e5e5;border-radius: 12px;padding: 12px 16px;color: #333333;font-size: 16px;}");

    layout->addWidget(iconLabel); // 左侧icon
    layout->addSpacing(10); // icon和文本之间的间距（10px）
    layout->addWidget(textLabel); // 文本气泡
    layout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum)); // 右对齐留白

    return bubbleWidget;
}


// 1. 创建初始的AI空气泡（流式输出前先创建，返回对应的ListWidgetItem和文本Label）
QListWidgetItem* MainWindow::createEmptyAiBubble()
{
    // 1. 创建ListWidgetItem
    QListWidgetItem* item = new QListWidgetItem(ui->listWidget_chat);

    // 2. 创建气泡容器Widget
    QWidget* bubbleWidget = new QWidget;
    QHBoxLayout* layout = new QHBoxLayout(bubbleWidget);
    layout->setContentsMargins(15, 8, 15, 8); // 气泡整体边距

    // 3. 创建头像Icon
    QLabel* iconLabel = new QLabel;
    QPixmap aiIcon(AI_ICON_PATH);
    if (!aiIcon.isNull()) {
        iconLabel->setPixmap(aiIcon.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    iconLabel->setFixedSize(40, 40);
    iconLabel->setStyleSheet("border-radius: 20px;");

    // 4. 创建空的文本Label（核心：初始文本为空，后续增量更新）
    QLabel* textLabel = new QLabel(""); // 初始空文本
    textLabel->setObjectName("AiBubbleLabel");
    textLabel->setWordWrap(true);
    textLabel->setMaximumWidth(ui->listWidget_chat->width() * 0.7);
    // 样式直接设置（和原代码一致）
    textLabel->setStyleSheet("QLabel#AiBubbleLabel { background-color: #e5e5e5;border-radius: 12px;padding: 12px 16px;color: #333333;font-size: 16px;}");

    // 5. 组装布局
    layout->addWidget(iconLabel);
    layout->addSpacing(10);
    layout->addWidget(textLabel);
    layout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));

    // 6. 绑定Widget到Item，并自适应尺寸
    item->setSizeHint(bubbleWidget->sizeHint());
    ui->listWidget_chat->setItemWidget(item, bubbleWidget);
    ui->listWidget_chat->scrollToBottom(); // 滚动到底部

    return item; // 返回Item，后续更新时通过Item找到文本Label
}

void MainWindow::appendAiBubbleText(QListWidgetItem* aiItem, const QString& appendChar)
{
    if (!aiItem) return; // 空判断

    // 1. 从Item中获取对应的气泡Widget
    QWidget* bubbleWidget = ui->listWidget_chat->itemWidget(aiItem);
    if (!bubbleWidget) return;

    // 2. 找到Widget中的AiBubbleLabel
    QLabel* textLabel = bubbleWidget->findChild<QLabel*>("AiBubbleLabel");
    if (!textLabel) return;

    // 3. 追加字符到现有文本后（核心逻辑）
    QString currentText = textLabel->text();
    currentText += appendChar; // 追加新字符
    textLabel->setText(currentText);

    // 4. 关键：更新Item的尺寸，让气泡自适应新文本的高度（避免文本超出气泡）
    aiItem->setSizeHint(bubbleWidget->sizeHint());
    ui->listWidget_chat->scrollToBottom(); // 始终滚动到底部
}

// 创建用户侧气泡
QWidget* MainWindow::createUserBubble(const QString& text)
{
    QWidget* bubbleWidget = new QWidget;
    QHBoxLayout* layout = new QHBoxLayout(bubbleWidget);
    layout->setContentsMargins(15, 8, 15, 8);

    QLabel* textLabel = new QLabel(text);
    textLabel->setObjectName("UserBubbleLabel");
    textLabel->setWordWrap(true);
    textLabel->setMaximumWidth(ui->listWidget_chat->width() * 0.7);

    textLabel->setStyleSheet("QLabel#UserBubbleLabel { background-color: #409eff;border-radius: 12px;padding: 12px 16px;color:#ffffff;font-size: 16px;}");

    QLabel* iconLabel = new QLabel;
    QPixmap userIcon(USER_ICON_PATH);
    if (!userIcon.isNull()) {
        iconLabel->setPixmap(userIcon.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    iconLabel->setFixedSize(40, 40);
    iconLabel->setStyleSheet("border-radius: 20px;"); // 可选：圆形icon

    layout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum)); // 左对齐留白
    layout->addWidget(textLabel); // 文本气泡
    layout->addSpacing(10); // 文本和icon之间的间距
    layout->addWidget(iconLabel); // 右侧icon

    return bubbleWidget;
}

// 添加消息接口
void MainWindow::addChatMessage(const QString& text, bool isUser)
{
    QListWidgetItem* item = new QListWidgetItem(ui->listWidget_chat);
    QWidget* bubbleWidget = isUser ? createUserBubble(text) : createAiBubble(text);
    item->setSizeHint(bubbleWidget->sizeHint());
    ui->listWidget_chat->setItemWidget(item, bubbleWidget);
    ui->listWidget_chat->scrollToBottom();
}

void MainWindow::UI_init()
{
    // 设置导航栏
    // 默认设置在上方
    ui->tabWidget_main->setTabPosition(QTabWidget::North);
    ui->listWidget_chat->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listWidget_chat->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->lineEdit_send_message->setPlaceholderText("请输入您的问题");

    // 测试：添加示例消息
    addChatMessage("您好！我是AI助手，请上传配置文件", false); // AI消息
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ai_send_clicked()
{
    QString message = ui->lineEdit_send_message->text();
    addChatMessage(message,true);

    m_currentAiItem = createEmptyAiBubble();

    // 将数据发送到多线程AI聊天线程中
    emit SendUserMessage(message);


    ui->lineEdit_send_message->clear();
}

void MainWindow::GetAiAnsower(QString message)
{
    appendAiBubbleText(m_currentAiItem, message);
}
