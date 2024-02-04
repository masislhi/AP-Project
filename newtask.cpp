#include "newtask.h"
#include "ui_newtask.h"
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include <string>
#include "task.h"

#define CURRENT_SOURCE_DIR std::string(__FILE__).substr(0,std::string(__FILE__).find_last_of("/\\"))
newtask::newtask(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::newtask)
{
    ui->setupUi(this);
}

newtask::~newtask()
{
    delete ui;

}

void newtask::on_pushButton_clicked()
{
    QString path=QString::fromStdString(CURRENT_SOURCE_DIR);
    QFile file(path+"/"+use+"_"+ui->name->text()+".txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        QTextStream out(&file);
        out<<ui->name->text();
        out<<"\n";
        out<<ui->dateTimeEdit->text();
        out<<"\n";
        out<<ui->priority->currentText();
        out<<"\n";
    }
    file.close();
    close();
    Task *t=new Task();
    t->user(use);
    t->show();

}

