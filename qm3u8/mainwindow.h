#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include<QWebEngineView>
#include<QWebEnginePage>
#include<QWebEngineProfile>
#include<QWebEngineCookieStore>
#include<QUrl>

#include <QObjectList>
#include <QStringList>
#include <QTextStream>

#include <QSqlDriver>
#include <QSqlDatabase>
#include <QSqlQuery>

#include<QMediaPlayer>
#include<QVideoWidget>
#include<QSlider>

//local header
#include<webcookie.h>
#include<browser.h>
#include<localplayer.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showWeb();
    void test();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
