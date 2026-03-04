#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTextEdit>
#include <QThread>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void UI_init();

    void ImageTabWidget(const QString &imagePath,const QString &tabText,const QString &contentText,const QSize &imageSize);
    void appendAiBubbleText(QListWidgetItem* aiItem, const QString& appendChar);

private slots:
    void on_pushButton_ai_send_clicked();

    void GetAiAnsower(QString message);

private:
    Ui::MainWindow *ui;
    QListWidgetItem* m_currentAiItem;


    QWidget* createUserBubble(const QString& text);
    QWidget* createAiBubble(const QString& text);

    QListWidgetItem* createEmptyAiBubble();


    void addChatMessage(const QString& text, bool isUser);

signals:
    void SendUserMessage(QString message);
};
#endif // MAINWINDOW_H
