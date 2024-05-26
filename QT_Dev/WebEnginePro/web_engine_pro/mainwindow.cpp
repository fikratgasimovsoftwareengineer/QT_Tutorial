#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    webEngine = new QWebEngineView();

    ui->webContainer->addWidget(webEngine);
    load_page();



}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_backButton_clicked()
{
    webEngine->back();
    qDebug() << "Backward CLick";

}


void MainWindow::on_forwardButton_clicked()
{
    webEngine->forward();
    qDebug() << "Forward CLick";
}


void MainWindow::on_refreshButton_clicked()
{
    webEngine->reload();
    qDebug() << "Reload CLick";

}

void MainWindow::on_searchButton_clicked()
{
    load_page();
}


void MainWindow::load_page()
{
    QString url = ui->lineEdit->text();

    if (!url.startsWith("http://") && !url.startsWith("https://")){
        url = "https://" + url;
    }
    ui->lineEdit->setText(url);
    webEngine->load(QUrl(url));
}



