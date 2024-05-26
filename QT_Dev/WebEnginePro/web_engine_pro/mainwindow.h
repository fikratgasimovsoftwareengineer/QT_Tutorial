#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QWebEngineView>
#include <QUrl>
#include <QTimer>

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



private slots:

    void on_backButton_clicked();

    void on_forwardButton_clicked();

    void on_refreshButton_clicked();

    void on_searchButton_clicked();

private:
    Ui::MainWindow *ui;

    QWebEngineView *webEngine;

    void load_page();

};
#endif // MAINWINDOW_H
