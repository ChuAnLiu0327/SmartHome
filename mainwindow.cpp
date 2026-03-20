#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aichat.h"
#include "envcard.h"
#include <QSqlDatabase>

MainWindow::MainWindow(const QString& loginAccount,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,m_loginAccount(loginAccount)
{
    ui->setupUi(this);

    UI_init();

    qDebug() << "MainWindow接收到的登录账号：" << m_loginAccount;
    this->setWindowTitle("智慧小区物业中控系统----欢迎用户: " + m_loginAccount);

    AiChat *aichat = new AiChat; // ai聊天对象
    QThread *aichat_thread = new QThread;
    aichat->moveToThread(aichat_thread); // 移动到线程池中

    m_networkmanage = new NetWorkManage;
    m_networkmanagethread = new QThread;
    m_networkmanage->moveToThread(m_networkmanagethread);

    connect(this,&MainWindow::SendUserMessage,aichat,&AiChat::ChatToAi);
    connect(aichat,&AiChat::SendToUserAnsower,this,&MainWindow::GetAiAnsower);

    connect(this,&MainWindow::sendAccount,m_networkmanage,&NetWorkManage::recvAccount);
    emit sendAccount(m_loginAccount);

    connect(ui->pushButton_send_one,&QPushButton::clicked,this,&MainWindow::sendMessageToNetWorkManage);
    connect(this,&MainWindow::sendOneMessage,m_networkmanage,&NetWorkManage::getMessageFromMainWindow);
    connect(m_networkmanage,&NetWorkManage::sendGetOneMessageToMainWindow,this,&MainWindow::showOneMessage);

    aichat_thread->start();
    m_networkmanagethread->start();

    m_chartmanager = new ChartManager(this);

    // 准备假数据
    QVector<qreal> xData = {1, 2, 3, 4, 5};
    QVector<qreal> yData1 = {10, 20, 15, 30, 25};

    // 调用接口，生成折线图
    m_chartmanager->renderChart(
        ui->widget_charts,    // 放到哪个 Widget 里
        xData,              // X轴数据
        yData1,              // Y轴数据
        "时间(秒)",         // X轴标签
        "温度(°C)",         // Y轴标签
        ChartManager::Line  // 图表类型：Line, Bar, Pie
    );
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

    // 1. 温度卡片 → 塞进 temp_widget
    EnvCard *tempCard = new EnvCard(":/new/prefix1/icons/wendu.png", "温度", "°C");
    tempCard->setValue("23.9");
    tempCard->setStatus("正常", 0);
    addCardToWidget(ui->widget_wendu, tempCard); // 核心封装函数，一行搞定

    // 2. 湿度卡片 → 塞进 hum_widget
    EnvCard *humCard = new EnvCard(":/new/prefix1/icons/shidu.png", "湿度", "%RH");
    humCard->setValue("55");
    humCard->setStatus("正常", 0);
    addCardToWidget(ui->widget_shidu, humCard);

    // 3. PM2.5卡片 → 塞进 pm_widget
    EnvCard *pmCard = new EnvCard(":/new/prefix1/icons/pm25.png", "PM2.5", "μg/m³");
    pmCard->setValue("49");
    pmCard->setStatus("轻度污染", 1);
    addCardToWidget(ui->widget_PM25, pmCard);

    // 4. 光照卡片 → 塞进 light_widget
    EnvCard *lightCard = new EnvCard(":/new/prefix1/icons/guangzhao.png", "光照", "lux");
    lightCard->setValue("852");
    lightCard->setStatus("适宜", 0);
    addCardToWidget(ui->widget_guangzhao, lightCard);

    // 5. 燃气卡片 → 塞进 gas_widget
    EnvCard *gasCard = new EnvCard(":/new/prefix1/icons/ranqi.png", "燃气", "%LEL");
    gasCard->setValue("0");
    gasCard->setStatus("安全", 0);
    addCardToWidget(ui->widget_ranqi, gasCard);

    // 6. 设备状态卡片 → 塞进 device_widget
    EnvCard *deviceCard = new EnvCard(":/new/prefix1/icons/shebei.png", "设备状态", "");
    deviceCard->setValue("0");
    deviceCard->setStatus("正常", 0);
    addCardToWidget(ui->widget_shebeizhuangtai, deviceCard);
}

// ========== 封装一个通用函数，不用重复写代码 ==========
// 功能：把EnvCard卡片，塞进指定的widget容器里，自动填满
void MainWindow::addCardToWidget(QWidget *containerWidget, EnvCard *card)
{
    // 1. 先给容器widget设置布局（兜底：就算你没在Designer里设，代码里自动补）
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(containerWidget->layout());
    if(!layout) {
        layout = new QVBoxLayout(containerWidget);
        layout->setContentsMargins(0, 0, 0, 0); // 边距设为0，让卡片完全填满容器
        layout->setSpacing(0);
    }
    // 2. 把卡片塞进布局里
    layout->addWidget(card);
}

void MainWindow::sendMessageToNetWorkManage()
{
    QString target_account = ui->lineEdit_recv_account->text();
    QString message = ui->lineEdit_send_one->text();
    addOneChatMessage(message, true);
    emit sendOneMessage(target_account,message);
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

void MainWindow::showOneMessage(QString message)
{
    qDebug() << message;
    // 接收的消息 → 左侧气泡（isUser=false）
    addOneChatMessage(message, false);

}

// 单聊-接收方气泡（左侧，他人发的消息）
QWidget* MainWindow::createOneChatRecvBubble(const QString& text)
{
    QWidget* bubbleWidget = new QWidget;
    QHBoxLayout* layout = new QHBoxLayout(bubbleWidget);
    layout->setContentsMargins(15, 8, 15, 8); // 气泡边距

    // 对方头像（可替换为实际头像路径）
    QLabel* iconLabel = new QLabel;
    QPixmap recvIcon(AI_ICON_PATH); // 临时复用AI头像，可改造成对方账号对应的头像
    if (!recvIcon.isNull()) {
        iconLabel->setPixmap(recvIcon.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    iconLabel->setFixedSize(40, 40);
    iconLabel->setStyleSheet("border-radius: 20px;"); // 圆形头像

    // 消息文本气泡
    QLabel* textLabel = new QLabel(text);
    textLabel->setObjectName("OneChatRecvLabel");
    textLabel->setWordWrap(true);
    textLabel->setMaximumWidth(ui->listWidget_one_chat->width() * 0.7); // 适配单聊控件宽度
    textLabel->setStyleSheet("QLabel#OneChatRecvLabel { background-color: #e5e5e5;border-radius: 12px;padding: 12px 16px;color: #333;font-size: 16px;}");

    // 布局组装（头像+文本+右留白）
    layout->addWidget(iconLabel);
    layout->addSpacing(10);
    layout->addWidget(textLabel);
    layout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));

    return bubbleWidget;
}

// 单聊-发送方气泡（右侧，自己发的消息）
QWidget* MainWindow::createOneChatSendBubble(const QString& text)
{
    QWidget* bubbleWidget = new QWidget;
    QHBoxLayout* layout = new QHBoxLayout(bubbleWidget);
    layout->setContentsMargins(15, 8, 15, 8);

    // 消息文本气泡
    QLabel* textLabel = new QLabel(text);
    textLabel->setObjectName("OneChatSendLabel");
    textLabel->setWordWrap(true);
    textLabel->setMaximumWidth(ui->listWidget_one_chat->width() * 0.7);
    textLabel->setStyleSheet("QLabel#OneChatSendLabel { background-color: #409eff;border-radius: 12px;padding: 12px 16px;color: #fff;font-size: 16px;}");

    // 自己的头像
    QLabel* iconLabel = new QLabel;
    QPixmap sendIcon(USER_ICON_PATH);
    if (!sendIcon.isNull()) {
        iconLabel->setPixmap(sendIcon.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    iconLabel->setFixedSize(40, 40);
    iconLabel->setStyleSheet("border-radius: 20px;");

    // 布局组装（左留白+文本+头像）
    layout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
    layout->addWidget(textLabel);
    layout->addSpacing(10);
    layout->addWidget(iconLabel);

    return bubbleWidget;
}

// 单聊添加消息统一接口（isUser=true：自己发的/右侧；false：他人发的/左侧）
void MainWindow::addOneChatMessage(const QString& text, bool isUser)
{
    if (text.trimmed().isEmpty()) return; // 空消息过滤

    QListWidgetItem* item = new QListWidgetItem(ui->listWidget_one_chat);
    QWidget* bubbleWidget = isUser ? createOneChatSendBubble(text) : createOneChatRecvBubble(text);
    item->setSizeHint(bubbleWidget->sizeHint()); // 自适应气泡尺寸
    ui->listWidget_one_chat->setItemWidget(item, bubbleWidget);
    ui->listWidget_one_chat->scrollToBottom(); // 自动滚动到底部
}
