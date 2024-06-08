#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QStandardItemModel>
#include <QApplication>
#include <QMessageBox>
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
    void on_pushButton_clicked();

    void cleanButton();
    void on_clearButton_clicked();

    void on_actionAbout_App_triggered();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *m_model;


};
#endif // MAINWINDOW_H
