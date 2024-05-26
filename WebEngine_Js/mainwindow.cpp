#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    engineView = new QWebEngineView();
    engineView->load(QUrl("qrc:/js/index.html"));
    ui->verticalLayout->addWidget(engineView);
}

MainWindow::~MainWindow()
{
    delete ui;
}
