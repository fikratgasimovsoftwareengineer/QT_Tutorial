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
            if (!queryDB.exec(
                    "CREATE TABLE IF NOT EXISTS users ("
                    "id INTEGER PRIMARY KEY AUTO_INCREMENT, "   // Changed AUTOINCREMENT to AUTO_INCREMENT
                    "firstname TEXT, "                          // Added comma
                    "lastname TEXT, "
                    "age INT)"
                    ))
            {
                ui->lineEdit_3->setText(queryDB.lastError().text());
                return;
            }
            // Use prepared statement to avoid SQL injection
            queryDB.prepare("INSERT INTO users (firstname, lastname, age) VALUES (?, ?, ?)");
            queryDB.addBindValue(ui->lineEdit->text());
            queryDB.addBindValue(ui->lineEdit_2->text());
            queryDB.addBindValue(ui->lineEdit_4->text());

            if (!queryDB.exec())
            {
                ui->lineEdit_3->setText(queryDB.lastError().text());
                return;
            }

            QMessageBox::information(this, "Database added", "Data has been inserted successfully");

            ui->lineEdit->setText("");
            ui->lineEdit_2->setText("");
            ui->lineEdit_4->setText("");
        }


}

