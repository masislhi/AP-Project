#include "desk.h"
#include "ui_desk.h"

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
