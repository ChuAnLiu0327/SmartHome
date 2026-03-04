/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget_main;
    QWidget *tab;
    QWidget *widget;
    QWidget *tab_3;
    QWidget *widget1;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *uploadConfigBtn;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QListWidget *listWidget_chat;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_send_message;
    QPushButton *pushButton_ai_send;
    QWidget *tab_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1089, 775);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/xiaoqu.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget_main = new QTabWidget(centralwidget);
        tabWidget_main->setObjectName("tabWidget_main");
        tabWidget_main->setStyleSheet(QString::fromUtf8("/* \346\240\207\347\255\276\346\240\217\345\256\271\345\231\250\346\240\267\345\274\217 */\n"
"    QTabWidget::pane {\n"
"        border: 1px solid #e0e0e0;\n"
"        background-color: #FFFFFFFF;\n"
"        border-radius: 4px;\n"
"        margin-top: 5px;\n"
"    }\n"
"    \n"
"    /* \346\240\207\347\255\276\351\241\265\346\234\254\350\272\253\357\274\210\351\235\236\351\200\211\344\270\255\347\212\266\346\200\201\357\274\211 */\n"
"    QTabBar::tab {\n"
"        background-color: #f5f5f5;\n"
"        border: 1px solid #e0e0e0;\n"
"        border-bottom: none;\n"
"        border-top-left-radius: 4px;\n"
"        border-top-right-radius: 4px;\n"
"        padding: 10px 20px;\n"
"        margin-right: 2px;\n"
"        font-size: 16px;\n"
"        color: #666;\n"
"    }\n"
"    \n"
"    /* \351\274\240\346\240\207\346\202\254\345\201\234\346\225\210\346\236\234 */\n"
"    QTabBar::tab:hover {\n"
"        background-color: #e8f4ff;\n"
"        color: #0078d4;\n"
"    }\n"
"    \n"
"    /* \351\200\211\344\270\255"
                        "\347\212\266\346\200\201\347\232\204\346\240\207\347\255\276\351\241\265 */\n"
"    QTabBar::tab:selected {\n"
"        background-color: white;\n"
"        color: #0078d4;\n"
"        font-weight: bold;\n"
"        border-bottom: 2px solid #0078d4;\n"
"    }\n"
"    \n"
"    /* \351\235\236\351\200\211\344\270\255\347\212\266\346\200\201\347\232\204\346\240\207\347\255\276\351\241\265 - \345\272\225\351\203\250\350\276\271\346\241\206 */\n"
"    QTabBar::tab:!selected {\n"
"        margin-top: 2px;\n"
"    }\n"
"    \n"
"    /* \347\246\201\347\224\250\347\212\266\346\200\201\347\232\204\346\240\207\347\255\276\351\241\265 */\n"
"    QTabBar::tab:disabled {\n"
"        color: #999;\n"
"        background-color: #f0f0f0;\n"
"    }"));
        tabWidget_main->setIconSize(QSize(32, 32));
        tab = new QWidget();
        tab->setObjectName("tab");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/HuanJin.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_main->addTab(tab, icon1, QString());
        widget = new QWidget();
        widget->setObjectName("widget");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix2/SheBeiKongZhi.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_main->addTab(widget, icon2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix3/FeiYong.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_main->addTab(tab_3, icon3, QString());
        widget1 = new QWidget();
        widget1->setObjectName("widget1");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix4/LiaoTian.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_main->addTab(widget1, icon4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        verticalLayout_3 = new QVBoxLayout(tab_5);
        verticalLayout_3->setObjectName("verticalLayout_3");
        widget_2 = new QWidget(tab_5);
        widget_2->setObjectName("widget_2");
        widget_2->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: #E5E7EB;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(288, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName("widget_3");
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        uploadConfigBtn = new QPushButton(widget_3);
        uploadConfigBtn->setObjectName("uploadConfigBtn");
        uploadConfigBtn->setStyleSheet(QString::fromUtf8("/* \345\237\272\347\241\200\346\240\267\345\274\217 */\n"
"QPushButton#uploadConfigBtn {\n"
"    /* \350\203\214\346\231\257\350\211\262\357\274\232\345\214\271\351\205\215\345\233\276\344\270\255\347\232\204\350\223\235\347\264\253\350\211\262 */\n"
"    background-color: #4E5AF1;\n"
"    /* \346\226\207\345\255\227\351\242\234\350\211\262\357\274\232\347\231\275\350\211\262 */\n"
"    color: white;\n"
"    /* \345\216\273\346\216\211\351\273\230\350\256\244\350\276\271\346\241\206 */\n"
"    border: none;\n"
"    /* \345\234\206\350\247\222\345\244\247\345\260\217\357\274\2328px \345\214\271\351\205\215\350\247\206\350\247\211\346\225\210\346\236\234 */\n"
"    border-radius: 8px;\n"
"    /* \345\206\205\350\276\271\350\267\235\357\274\232\344\270\212\344\270\21310px\357\274\214\345\267\246\345\217\26316px\357\274\214\345\267\246\344\276\247\351\242\235\345\244\226\347\225\231\345\207\272\345\233\276\346\240\207\344\275\215\347\275\256 */\n"
"    padding: 10px 16px;\n"
"    padding-left: 32px;\n"
"    /* \345"
                        "\255\227\344\275\223\346\240\267\345\274\217 */\n"
"    font-family: \"Microsoft YaHei\", Arial, sans-serif;\n"
"    font-size: 18px;\n"
"    /* \345\233\276\346\240\207\344\275\215\347\275\256\357\274\232\345\267\246\344\276\24710px\345\261\205\344\270\255\357\274\210\345\246\202\346\236\234\344\275\240\347\224\250\350\203\214\346\231\257\345\233\276\345\201\232\345\233\276\346\240\207\357\274\211 */\n"
"    background-repeat: no-repeat;\n"
"    background-position: left 10px center;\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\346\265\256\347\212\266\346\200\201 */\n"
"QPushButton#uploadConfigBtn:hover {\n"
"    background-color: #434EDC;\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\214\211\344\270\213\347\212\266\346\200\201 */\n"
"QPushButton#uploadConfigBtn:pressed {\n"
"    background-color: #3A44C8;\n"
"}\n"
"\n"
"/* \347\246\201\347\224\250\347\212\266\346\200\201 */\n"
"QPushButton#uploadConfigBtn:disabled {\n"
"    background-color: #B4B8F5;\n"
"    color: #E0E0E0;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/upload.png"), QSize(), QIcon::Normal, QIcon::Off);
        uploadConfigBtn->setIcon(icon5);
        uploadConfigBtn->setIconSize(QSize(32, 32));

        verticalLayout_2->addWidget(uploadConfigBtn);

        label = new QLabel(widget_3);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);


        horizontalLayout_2->addWidget(widget_3);

        horizontalSpacer_2 = new QSpacerItem(288, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_3->addWidget(widget_2);

        listWidget_chat = new QListWidget(tab_5);
        listWidget_chat->setObjectName("listWidget_chat");
        listWidget_chat->setStyleSheet(QString::fromUtf8("QListWidget { border: none; background: white; }"));

        verticalLayout_3->addWidget(listWidget_chat);

        widget2 = new QWidget(tab_5);
        widget2->setObjectName("widget2");
        horizontalLayout = new QHBoxLayout(widget2);
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit_send_message = new QLineEdit(widget2);
        lineEdit_send_message->setObjectName("lineEdit_send_message");
        lineEdit_send_message->setStyleSheet(QString::fromUtf8("/* QTextEdit \345\237\272\347\241\200\346\240\267\345\274\217 */\n"
"QLineEdit {\n"
"    /* \350\203\214\346\231\257\350\211\262\357\274\232\346\265\205\347\201\260\350\211\262\357\274\214\346\237\224\345\222\214\344\270\215\345\210\272\347\234\274 */\n"
"    background-color: #f8f9fa;\n"
"    /* \350\276\271\346\241\206\357\274\232\346\265\205\347\201\260\350\211\262\357\274\214\345\234\206\350\247\2228px\357\274\210\345\217\257\350\260\203\346\225\264\357\274\211 */\n"
"    border: 1px solid #dee2e6;\n"
"    border-radius: 8px;\n"
"    /* \345\206\205\350\276\271\350\267\235\357\274\232\351\201\277\345\205\215\346\226\207\345\255\227\350\264\264\350\276\271\346\241\206\357\274\214\344\270\212\344\270\213\345\267\246\345\217\263\345\220\20410px */\n"
"    padding: 10px;\n"
"    /* \346\226\207\345\255\227\346\240\267\345\274\217\357\274\232\351\273\230\350\256\244\345\255\227\344\275\223\357\274\21414px\345\244\247\345\260\217\357\274\214\346\267\261\347\201\260\350\211\262\346\226\207\345\255\227 */\n"
"    "
                        "font-family: \"Microsoft YaHei\", Arial, sans-serif;\n"
"    font-size: 20px;\n"
"    /* \347\246\201\347\224\250\351\273\230\350\256\244\347\232\204\347\204\246\347\202\271\350\231\232\347\272\277\346\241\206 */\n"
"    outline: none;\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\346\265\256\347\212\266\346\200\201 */\n"
"QLineEdit:hover {\n"
"    border-color: #adb5bd;\n"
"    background-color: #f1f3f5;\n"
"}\n"
"\n"
"/* \350\216\267\345\276\227\347\204\246\347\202\271\347\212\266\346\200\201\357\274\210\346\277\200\346\264\273\357\274\211 */\n"
"QLineEdit:focus {\n"
"    border-color: #4dabf7;\n"
"    /* \350\275\273\345\276\256\345\244\226\345\217\221\345\205\211\346\225\210\346\236\234\357\274\214\345\242\236\345\274\272\347\204\246\347\202\271\346\217\220\347\244\272 */\n"
"}\n"
"\n"
"/* \351\200\211\344\270\255\346\226\207\346\234\254\347\232\204\350\203\214\346\231\257\350\211\262 */\n"
"QLineEdit::selection {\n"
"    background-color: #4dabf7;\n"
"    color: white;\n"
"}\n"
"\n"
"/* \347\246\201"
                        "\347\224\250\347\212\266\346\200\201 */\n"
"QLineEdit:disabled {\n"
"    background-color: #e9ecef;\n"
"    color: #adb5bd;\n"
"    border-color: #e9ecef;\n"
"}\n"
"\n"
"/* ---------- \351\205\215\345\245\227\346\273\232\345\212\250\346\235\241\347\276\216\345\214\226 ---------- */\n"
"/* \346\273\232\345\212\250\346\235\241\346\225\264\344\275\223 */\n"
"QLineEdit QScrollBar:vertical {\n"
"    width: 8px;\n"
"    background-color: transparent;\n"
"    margin: 0px;\n"
"}\n"
"\n"
"/* \346\273\232\345\212\250\346\235\241\346\273\221\345\235\227 */\n"
"QLineEdit QScrollBar::handle:vertical {\n"
"    background-color: #ced4da;\n"
"    border-radius: 4px;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"/* \346\273\221\345\235\227\346\202\254\346\265\256 */\n"
"QLineEdit QScrollBar::handle:vertical:hover {\n"
"    background-color: #adb5bd;\n"
"}\n"
"\n"
"/* \346\273\232\345\212\250\346\235\241\344\270\212\344\270\213\347\256\255\345\244\264\357\274\210\351\232\220\350\227\217\357\274\211 */\n"
"QLineEdit QScrollBar::sub-l"
                        "ine:vertical,\n"
"QLineEdit QScrollBar::add-line:vertical {\n"
"    height: 0px;\n"
"}\n"
"\n"
"/* \346\260\264\345\271\263\346\273\232\345\212\250\346\235\241\357\274\210\346\214\211\351\234\200\345\220\257\347\224\250\357\274\211 */\n"
"QLineEdit QScrollBar:horizontal {\n"
"    height: 8px;\n"
"    background-color: transparent;\n"
"    margin: 0px;\n"
"}\n"
"\n"
"QLineEdit QScrollBar::handle:horizontal {\n"
"    background-color: #ced4da;\n"
"    border-radius: 4px;\n"
"    min-width: 20px;\n"
"}\n"
"\n"
"QLineEdit QScrollBar::handle:horizontal:hover {\n"
"    background-color: #adb5bd;\n"
"}\n"
"\n"
"QLineEdit QScrollBar::sub-line:horizontal,\n"
"QLineEdit QScrollBar::add-line:horizontal {\n"
"    width: 0px;\n"
"}"));

        horizontalLayout->addWidget(lineEdit_send_message);

        pushButton_ai_send = new QPushButton(widget2);
        pushButton_ai_send->setObjectName("pushButton_ai_send");
        pushButton_ai_send->setStyleSheet(QString::fromUtf8("/* \345\217\221\351\200\201\346\214\211\351\222\256\345\237\272\347\241\200\346\240\267\345\274\217 */\n"
"QPushButton { /* \344\275\277\347\224\250ID\351\200\211\346\213\251\345\231\250\357\274\214\351\201\277\345\205\215\345\275\261\345\223\215\345\205\266\344\273\226\346\214\211\351\222\256 */\n"
"    /* \350\203\214\346\231\257\351\242\234\350\211\262\357\274\210\347\244\272\344\276\213\344\270\255\347\232\204\350\223\235\350\211\262\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\357\274\211 */\n"
"    background-color: #2196F3; /* Material Design \346\240\207\345\207\206\350\223\235\350\211\262 */\n"
"    /* \346\226\207\345\255\227\346\240\267\345\274\217 */\n"
"    color: white; /* \347\231\275\350\211\262\346\226\207\345\255\227 */\n"
"    font-size: 20px; /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-weight: 500; /* \345\255\227\344\275\223\347\262\227\347\273\206\357\274\210\345\217\257\351\200\211\357\274\214\345\242\236\345\274\272"
                        "\345\261\202\346\254\241\346\204\237\357\274\211 */\n"
"    /* \350\276\271\346\241\206\344\270\216\345\234\206\350\247\222 */\n"
"    border: none; /* \346\227\240\350\276\271\346\241\206 */\n"
"    border-radius: 6px; /* \345\234\206\350\247\222\357\274\210\347\244\272\344\276\213\344\270\255\347\232\204\345\234\206\350\247\222\347\272\2466px\357\274\211 */\n"
"    /* \345\206\205\350\276\271\350\267\235\357\274\210\346\214\211\351\222\256\345\206\205\345\256\271\344\270\216\350\276\271\346\241\206\347\232\204\351\227\264\350\267\235\357\274\214\351\201\277\345\205\215\346\213\245\346\214\244\357\274\211 */\n"
"    padding: 10px 20px; /* \344\270\212\344\270\21310px\357\274\214\345\267\246\345\217\26320px */\n"
"    /* \345\233\276\346\240\207\350\256\276\347\275\256 */\n"
"    icon-size: 16px; /* \345\233\276\346\240\207\345\244\247\345\260\217\357\274\210\344\270\216\346\226\207\345\255\227\345\214\271\351\205\215\357\274\211 */\n"
"    /* \346\234\200\345\260\217\345\256\275\351\253\230\357\274\210\347\241"
                        "\256\344\277\235\346\214\211\351\222\256\344\270\215\344\274\232\345\244\252\345\260\217\357\274\211 */\n"
"    min-width: 120px; /* \346\234\200\345\260\217\345\256\275\345\272\246 */\n"
"    min-height: 36px; /* \346\234\200\345\260\217\351\253\230\345\272\246 */\n"
"}\n"
"\n"
"/*  hover \346\225\210\346\236\234\357\274\210\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\357\274\211 */\n"
"QPushButton:hover {\n"
"    background-color: #1976D2; /* \346\233\264\346\267\261\347\232\204\350\223\235\350\211\262\357\274\210\345\242\236\345\274\272\344\272\244\344\272\222\345\217\215\351\246\210\357\274\211 */\n"
"}\n"
"\n"
"/*  pressed \346\225\210\346\236\234\357\274\210\351\274\240\346\240\207\346\214\211\344\270\213\346\227\266\357\274\211 */\n"
"QPushButton:pressed {\n"
"    background-color: #1565C0; /* \346\233\264\346\232\227\347\232\204\350\223\235\350\211\262\357\274\210\346\250\241\346\213\237\346\214\211\345\216\213\346\204\237\357\274\211 */\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/send_baise.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_ai_send->setIcon(icon6);
        pushButton_ai_send->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_ai_send);


        verticalLayout_3->addWidget(widget2);

        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/AI.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_main->addTab(tab_5, icon7, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/video.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_main->addTab(tab_2, icon8, QString());

        verticalLayout->addWidget(tabWidget_main);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1089, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget_main->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\231\272\346\205\247\345\260\217\345\214\272\347\211\251\344\270\232\344\270\255\346\216\247\347\263\273\347\273\237", nullptr));
        tabWidget_main->setTabText(tabWidget_main->indexOf(tab), QCoreApplication::translate("MainWindow", "\347\216\257\345\242\203\347\233\221\346\265\213", nullptr));
        tabWidget_main->setTabText(tabWidget_main->indexOf(widget), QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\346\216\247\345\210\266", nullptr));
        tabWidget_main->setTabText(tabWidget_main->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\347\211\251\344\270\232\350\264\271\347\224\250\347\274\264\347\272\263", nullptr));
        tabWidget_main->setTabText(tabWidget_main->indexOf(widget1), QCoreApplication::translate("MainWindow", "\345\260\217\345\214\272\350\201\212\345\244\251\345\256\244", nullptr));
        uploadConfigBtn->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\274\240\351\205\215\347\275\256\346\226\207\344\273\266", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">\346\224\257\346\214\201JSON\346\210\226YMAL\346\240\274\345\274\217\347\232\204\351\205\215\347\275\256\346\226\207\344\273\266</span></p></body></html>", nullptr));
        pushButton_ai_send->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        tabWidget_main->setTabText(tabWidget_main->indexOf(tab_5), QCoreApplication::translate("MainWindow", "AI\345\210\206\346\236\220\345\270\210", nullptr));
        tabWidget_main->setTabText(tabWidget_main->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221\351\200\232\350\257\235", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
