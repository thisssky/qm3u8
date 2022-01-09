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

#include<QHBoxLayout>
#include<QLabel>
#include<QTextEdit>
#include<QPushButton>
#include<QTableWidget>
#include<QLineEdit>

//local header
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
    QWebEngineView *browser;
    QLabel *backLabel;
    QLabel *refreshLabel;
    QLabel *forwardLabel;
    QLabel *mainPageLabel;

private:
    Ui::MainWindow *ui;
    QPushButton *downloadButton;
    QTableWidget *tableWidget;
    QLineEdit *txtUrl;
};
#endif // MAINWINDOW_H
