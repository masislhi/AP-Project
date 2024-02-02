#include "task.h"
#include "ui_task.h"
#include "newtask.h"
Task::Task(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Task)
{
    ui->setupUi(this);
}

Task::~Task()
{
    delete ui;
}

void Task::on_pushButton_2_clicked()
{
    newtask *n=new newtask();
    n->user(use);
    n->show();
}

