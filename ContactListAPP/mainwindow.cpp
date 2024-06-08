#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_model = new QStandardItemModel(this);

    QStringList userCredentails;
    userCredentails << "User Name "
        << "Phone Number";
    // Set header labels to the model

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_model->setHorizontalHeaderLabels(userCredentails);
    /*m_model->setVerticalHeaderItem(0, new QStandardItem("Name"));
    m_model->setVerticalHeaderItem(1, new QStandardItem("Phone"));*/
    ui->tableView->setModel(m_model);



    connect(ui->actionQuite, &QAction::triggered, this, QCoreApplication::quit);



    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::on_clearButton_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    bool isNumeric = false;
    QString nameText = ui->nameEdit->text();
    int phoneNum = ui->phoneEdit->text().toInt(&isNumeric);

    if (isNumeric) {
        QStandardItem *nameItem = new QStandardItem(nameText);
        QStandardItem *phoneItem = new QStandardItem();
        phoneItem->setData(phoneNum, Qt::DisplayRole); // Set the phone number as integer


        m_model->appendRow({nameItem, phoneItem});

        // Optionally clear inputs after successful insertion
        ui->nameEdit->clear();
        ui->phoneEdit->clear();
    }
    else{
        QMessageBox::critical(this, "Error", "Phone item is not integer");
        ui->nameEdit->clear();
        ui->phoneEdit->clear();
    }



}






void MainWindow::on_clearButton_clicked()
{
    ui->nameEdit->clear();
    ui->phoneEdit->clear();
}


void MainWindow::on_actionAbout_App_triggered()
{
    QMessageBox::about(this, "About Aplication", "this is Qt6 TableWidget APP");
}

