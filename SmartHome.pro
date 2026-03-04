QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aichat.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    aichat.h \
    loginwindow.h \
    mainwindow.h

FORMS += \
    loginwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons/AI.qrc \
    icons/HuanJin.qrc \
    icons/YongHuDengLu.qrc \
    icons/ai_new.qrc \
    icons/send.qrc \
    icons/send.qrc \
    icons/upload.qrc \
    icons/video.qrc \
    icons/xiaoqu.qrc \
    icons/xiaoquBai.qrc \
    icons/yh.qrc
