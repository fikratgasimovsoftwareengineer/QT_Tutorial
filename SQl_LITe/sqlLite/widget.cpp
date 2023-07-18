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

        personalDB = QSqlDatabase::addDatabase("QSQLITE");
        personalDB.setDatabaseName("/home/fikrat/myPersonalDB.sqlite");

        if (!personalDB.open()){
            QMessageBox::information(this, "Database error ", "Database is not connected");
        }
        else{
            QSqlQuery queryDB;
            queryDB.exec("CREATE TABLE IF NOT EXISTS users ("
                         "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                         "firstname TEXT,"
                         "lastname TEXT,"
                         "age INTEGER)"
                         );
            firstname = ui->lineEdit->text();
            lastname = ui->lineEdit_2->text();
            age = ui->lineEdit_3->text();

            queryDB.exec("INSERT INTO users (firstname, lastname, age) VALUES ('" + firstname + "','" + lastname + "'," + age + ")");
            QMessageBox::information(this, "Database added", "Data has been inserted succesfully");

            ui->lineEdit->setText("");
            ui->lineEdit_2->setText("");
            ui->lineEdit_3->setText("");

        }


}

