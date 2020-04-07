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


//local header
#include<webcookie.h>

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
