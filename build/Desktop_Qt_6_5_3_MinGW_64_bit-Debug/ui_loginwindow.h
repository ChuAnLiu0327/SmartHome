/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_account;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_login;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(345, 366);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/YongHuDengLu.png"), QSize(), QIcon::Normal, QIcon::Off);
        LoginWindow->setWindowIcon(icon);
        LoginWindow->setStyleSheet(QString::fromUtf8("/* \350\256\276\347\275\256widget\350\203\214\346\231\257 - \351\235\236\345\270\270\346\265\205\347\232\204\350\223\235\350\211\262\346\270\220\345\217\230 */\n"
"QWidget {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"                                stop:0 #F0F8FF, stop:0.5 #E6F3FF, stop:1 #D6E9FF);\n"
"    border: none;\n"
"}"));
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    border: none;\n"
"	background: transparent;\n"
"}"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("/* \350\256\276\347\275\256label\346\240\267\345\274\217 - \351\273\221\344\275\223\345\255\227\344\275\223\357\274\214\351\200\217\346\230\216\350\203\214\346\231\257 */\n"
"QLabel {\n"
"    color: blue;\n"
"    font-size: 14px;\n"
"    border: none;\n"
"    background: transparent;\n"
"}"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	border: none;\n"
"	background: transparent;\n"
"}"));

        verticalLayout->addWidget(label_2);


        verticalLayout_5->addWidget(widget);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    border: none;\n"
"	background: transparent;\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(widget_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName("widget_3");
        widget_3->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    border: none;\n"
"	background: transparent;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_3 = new QLabel(widget_3);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("QLable{\n"
"    border: none;\n"
"	background: transparent;\n"
"}"));

        verticalLayout_2->addWidget(label_3);

        lineEdit_account = new QLineEdit(widget_3);
        lineEdit_account->setObjectName("lineEdit_account");
        lineEdit_account->setStyleSheet(QString::fromUtf8("/* \350\256\276\347\275\256LineEdit\346\240\267\345\274\217 - \346\267\273\345\212\240\350\276\271\346\241\206\345\222\214\350\203\214\346\231\257\350\211\262 */\n"
"QLineEdit {\n"
"    border: 1px solid #CCCCCC;      /* \346\265\205\347\201\260\350\211\262\350\276\271\346\241\206 */\n"
"    border-radius: 4px;             /* \345\234\206\350\247\222\350\276\271\346\241\206 */\n"
"    padding: 5px 10px;              /* \345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 16px;                /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    background-color: #FFFFFF;      /* \347\231\275\350\211\262\350\203\214\346\231\257 */\n"
"    color: #333333;                 /* \346\267\261\347\201\260\350\211\262\345\255\227\344\275\223 */\n"
"    font-family: \"\351\273\221\344\275\223\", \"SimHei\";  /* \351\273\221\344\275\223\345\255\227\344\275\223 */\n"
"    selection-background-color: #1E90FF;  /* \351\200\211\344\270\255\346\226\207\346\234\254\350\203\214\346\231\257\350\211\262 */\n"
"}\n"
""
                        "\n"
"/* LineEdit\350\216\267\345\217\226\347\204\246\347\202\271\346\227\266\347\232\204\346\240\267\345\274\217 */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #1E90FF;      /* \350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"    outline: none;                  /* \345\217\226\346\266\210\351\273\230\350\256\244\347\204\246\347\202\271\350\275\256\345\273\223 */\n"
"}\n"
"\n"
"/* LineEdit\346\217\220\347\244\272\350\257\215\346\240\267\345\274\217 */\n"
"QLineEdit::placeholder {\n"
"    color: #999999;                 /* \346\265\205\347\201\260\350\211\262\346\217\220\347\244\272\350\257\215 */\n"
"    font-size: 13px;                /* \346\217\220\347\244\272\350\257\215\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-style: italic;             /* \346\226\234\344\275\223 */\n"
"}"));

        verticalLayout_2->addWidget(lineEdit_account);


        verticalLayout_4->addWidget(widget_3);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName("widget_4");
        widget_4->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    border: none;\n"
"	background: transparent;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_4 = new QLabel(widget_4);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("QLable{\n"
"    border: none;\n"
"	background: transparent;\n"
"}"));

        verticalLayout_3->addWidget(label_4);

        lineEdit_password = new QLineEdit(widget_4);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setStyleSheet(QString::fromUtf8("/* \350\256\276\347\275\256LineEdit\346\240\267\345\274\217 - \346\267\273\345\212\240\350\276\271\346\241\206\345\222\214\350\203\214\346\231\257\350\211\262 */\n"
"QLineEdit {\n"
"    border: 1px solid #CCCCCC;      /* \346\265\205\347\201\260\350\211\262\350\276\271\346\241\206 */\n"
"    border-radius: 4px;             /* \345\234\206\350\247\222\350\276\271\346\241\206 */\n"
"    padding: 5px 10px;              /* \345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 16px;                /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    background-color: #FFFFFF;      /* \347\231\275\350\211\262\350\203\214\346\231\257 */\n"
"    color: #333333;                 /* \346\267\261\347\201\260\350\211\262\345\255\227\344\275\223 */\n"
"    font-family: \"\351\273\221\344\275\223\", \"SimHei\";  /* \351\273\221\344\275\223\345\255\227\344\275\223 */\n"
"    selection-background-color: #1E90FF;  /* \351\200\211\344\270\255\346\226\207\346\234\254\350\203\214\346\231\257\350\211\262 */\n"
"}\n"
""
                        "\n"
"/* LineEdit\350\216\267\345\217\226\347\204\246\347\202\271\346\227\266\347\232\204\346\240\267\345\274\217 */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #1E90FF;      /* \350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"    outline: none;                  /* \345\217\226\346\266\210\351\273\230\350\256\244\347\204\246\347\202\271\350\275\256\345\273\223 */\n"
"}\n"
"\n"
"/* LineEdit\346\217\220\347\244\272\350\257\215\346\240\267\345\274\217 */\n"
"QLineEdit::placeholder {\n"
"    color: #999999;                 /* \346\265\205\347\201\260\350\211\262\346\217\220\347\244\272\350\257\215 */\n"
"    font-size: 13px;                /* \346\217\220\347\244\272\350\257\215\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-style: italic;             /* \346\226\234\344\275\223 */\n"
"}"));

        verticalLayout_3->addWidget(lineEdit_password);


        verticalLayout_4->addWidget(widget_4);

        pushButton_login = new QPushButton(widget_2);
        pushButton_login->setObjectName("pushButton_login");
        pushButton_login->setStyleSheet(QString::fromUtf8("/* \350\256\276\347\275\256\346\214\211\351\222\256\346\240\267\345\274\217 */\n"
"QPushButton {\n"
"    /* \350\276\271\346\241\206\350\256\276\347\275\256 */\n"
"    border: 2px solid #2E8B57;           /* \346\265\267\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    border-radius: 8px;                  /* \345\234\206\350\247\222\350\276\271\346\241\206 */\n"
"    \n"
"    /* \350\203\214\346\231\257\346\270\220\345\217\230 - \344\273\216\344\270\212\345\210\260\344\270\213\347\232\204\346\270\220\345\217\230 */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                                stop:0 #20B2AA, stop:1 #3CB371);\n"
"    \n"
"    /* \345\255\227\344\275\223\350\256\276\347\275\256 */\n"
"    color: white;                        /* \347\231\275\350\211\262\345\255\227\344\275\223 */\n"
"    font-size: 14px;                     /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-family: \"\351\273\221\344\275\223\", \"SimHei\";        /* \351\273\221\344\275"
                        "\223\345\255\227\344\275\223 */\n"
"    font-weight: bold;                   /* \345\255\227\344\275\223\345\212\240\347\262\227 */\n"
"    \n"
"    /* \345\206\205\350\276\271\350\267\235 */\n"
"    padding: 8px 16px;                   /* \344\270\212\344\270\2138px\357\274\214\345\267\246\345\217\26316px */\n"
"    \n"
"    /* \346\226\207\346\234\254\345\257\271\351\275\220 */\n"
"    text-align: center;\n"
"   \n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\346\214\211\351\222\256\346\240\267\345\274\217 */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                                stop:0 #40E0D0, stop:1 #66CDAA);\n"
"    border: 2px solid #228B22;           /* \346\202\254\345\201\234\346\227\266\350\276\271\346\241\206\345\217\230\346\267\261 */\n"
"    color: white;\n"
"}\n"
"\n"
"/* \346\214\211\351\222\256\346\214\211\344\270\213\346\227\266\347\232\204\346\240\267\345\274\217 */\n"
"QPushButton:pressed {\n"
"    b"
                        "ackground: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                                stop:0 #008B8B, stop:1 #2E8B57);\n"
"    border: 2px solid #006400;           /* \346\214\211\344\270\213\346\227\266\350\276\271\346\241\206\346\233\264\346\267\261 */\n"
"    padding: 9px 16px 7px 16px;          /* \346\250\241\346\213\237\346\214\211\344\270\213\346\225\210\346\236\234 */\n"
"}\n"
"\n"
"/* \346\214\211\351\222\256\347\204\246\347\202\271\347\212\266\346\200\201\357\274\210\351\224\256\347\233\230\345\257\274\350\210\252\357\274\211 */\n"
"QPushButton:focus {\n"
"    outline: none;                      /* \345\217\226\346\266\210\351\273\230\350\256\244\347\204\246\347\202\271\350\275\256\345\273\223 */\n"
"    border: 2px solid #1E90FF;          /* \347\204\246\347\202\271\346\227\266\350\223\235\350\211\262\350\276\271\346\241\206 */\n"
"}"));

        verticalLayout_4->addWidget(pushButton_login);


        verticalLayout_5->addWidget(widget_2);

        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 345, 21));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "\347\231\273\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700;\">\345\260\217\345\214\272\347\231\273\351\231\206\347\263\273\347\273\237</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:700;\">\346\254\242\350\277\216\344\275\277\347\224\250\346\231\272\346\205\247\345\260\217\345\214\272\347\256\241\347\220\206\345\271\263\345\217\260</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">\344\275\217\346\210\267\350\264\246\345\217\267</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">\347\231\273\345\275\225\345\257\206\347\240\201</span></p></body></html>", nullptr));
        pushButton_login->setText(QCoreApplication::translate("LoginWindow", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
