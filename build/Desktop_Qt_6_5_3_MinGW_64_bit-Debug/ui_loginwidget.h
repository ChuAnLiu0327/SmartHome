/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *widget_smartHome_info;
    QLabel *label_lable_smartHome;
    QLabel *label_icon_smareHome;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(703, 538);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/YongHuDengLu.png"), QSize(), QIcon::Normal, QIcon::Off);
        Form->setWindowIcon(icon);
        widget_smartHome_info = new QWidget(Form);
        widget_smartHome_info->setObjectName("widget_smartHome_info");
        widget_smartHome_info->setGeometry(QRect(30, 90, 281, 361));
        widget_smartHome_info->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: qlineargradient(\n"
"        x1:0, y1:0, \n"
"        x2:1, y2:1,\n"
"        stop:0 #87CEEB, \n"
"        stop:0.5 #4682B4,\n"
"        stop:1 #4169E1\n"
"    );\n"
"}"));
        label_lable_smartHome = new QLabel(widget_smartHome_info);
        label_lable_smartHome->setObjectName("label_lable_smartHome");
        label_lable_smartHome->setGeometry(QRect(100, 50, 171, 71));
        label_lable_smartHome->setStyleSheet(QString::fromUtf8("/* \350\256\276\347\275\256\346\211\200\346\234\211QLabel\345\255\227\344\275\223\344\270\272\347\231\275\350\211\262 */\n"
"QLabel {\n"
"    color: white;\n"
"	font-size: 10pt;  /* \344\275\277\347\224\250pt\345\215\225\344\275\215 */\n"
"}"));
        label_icon_smareHome = new QLabel(widget_smartHome_info);
        label_icon_smareHome->setObjectName("label_icon_smareHome");
        label_icon_smareHome->setGeometry(QRect(30, 80, 53, 15));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "\347\231\273\345\275\225", nullptr));
        label_lable_smartHome->setText(QCoreApplication::translate("Form", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\231\272\346\205\247\345\260\217\345\214\272</span></p><p><span style=\" font-size:12pt;\">Intelligent Community System</span></p></body></html>", nullptr));
        label_icon_smareHome->setText(QCoreApplication::translate("Form", "icon", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
