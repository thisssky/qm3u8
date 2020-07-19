QT       += core gui
QT       += network
QT       += webenginewidgets
QT       += sql
QT       += multimedia
QT       += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
#CONFIG += console

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    EqualizerDialog.cpp \
    SimplePlayer.cpp \
    browser.cpp \
    localplayer.cpp \
    main.cpp \
    mainwindow.cpp \
    mqwebengineurlrequestinterceptor.cpp \
    webcookie.cpp

HEADERS += \
    EqualizerDialog.h \
    SimplePlayer.h \
    browser.h \
    localplayer.h \
    mainwindow.h \
    mqwebengineurlrequestinterceptor.h \
    webcookie.h

FORMS += \
    EqualizerDialog.ui \
    SimplePlayer.ui \
    mainwindow.ui

TRANSLATIONS += \
    qm3u8_zh_CN.ts

# Edit below for custom library location
LIBS       += -L/usr/local/lib -lVLCQtCore -lVLCQtWidgets
INCLUDEPATH += /usr/local/include

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
