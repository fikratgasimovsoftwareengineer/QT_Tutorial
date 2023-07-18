#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("Fikr@t2023");
    db.setDatabaseName("qt6");

    if(!db.open()){

        ui->label->setText(db.lastError().text());

    }  else{
        QSqlQuery queryDB;
        queryDB.exec("CREATE TABLE IF NOT EXISTS users ("
                     "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                     "firstname TEXT,"
                     "lastname TEXT)"
                     );
        firstname = ui->lineEdit->text();
        lastname = ui->lineEdit_2->text();

        queryDB.exec("INSERT INTO users (firstname, lastname) VALUES ('" + firstname + "','" + lastname + ")");
        QMessageBox::information(this, "Database added", "Data has been inserted succesfully");

        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");


    }
}

