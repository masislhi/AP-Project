#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signup.h"
#include "desk.h"
#include "passc.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString user=ui->lineEdit->text();
    QString pass=ui->lineEdit_2->text();
    if(map.contains(user))
    {
        if(map.value(user)==pass)
        {
            close();
            QMessageBox::information(this,"sign in","you have enterd");
            desk *d=new desk();
            d->user(list.key(pass));
            d->show();

        }
        else
            QMessageBox::warning(this,"sign in","password is incorrect");
    }
    else
        QMessageBox::warning(this,"sign in","sign up first");
}


void MainWindow::on_pushButton_2_clicked()
{
    close();
    signup *s=new signup();
    s->show();
}




void MainWindow::on_pushButton_3_clicked()
{
    Passc *p=new Passc();
    p->rec(list);
    p->show();
}

