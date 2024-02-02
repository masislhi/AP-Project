#include "desk.h"
#include "ui_desk.h"
#include "task.h"

desk::desk(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::desk)
{
    ui->setupUi(this);
}

desk::~desk()
{
    delete ui;
}

void desk::on_pushButton_clicked()
{
    Task *t = new Task();
    t->user(use);
    t->show();
}

