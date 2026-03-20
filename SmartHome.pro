QT       += core gui network charts sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aichat.cpp \
    chartmanager.cpp \
    envcard.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    networkmanage.cpp \
    userdbmanager.cpp

HEADERS += \
    aichat.h \
    chartmanager.h \
    envcard.h \
    loginwindow.h \
    mainwindow.h \
    networkmanage.h \
    userdbmanager.h

FORMS += \
    loginwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc \
    icons/AI.qrc \
    icons/HuanJin.qrc \
    icons/YongHuDengLu.qrc \
    icons/ai_new.qrc \
    icons/chat_all.qrc \
    icons/send.qrc \
    icons/send.qrc \
    icons/tab_chat.qrc \
    icons/upload.qrc \
    icons/video.qrc \
    icons/xiaoqu.qrc \
    icons/xiaoquBai.qrc \
    icons/yh.qrc
