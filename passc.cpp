#include "passc.h"
#include "ui_passc.h"
#include <QMessageBox>

Passc::Passc(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Passc)
{
    ui->setupUi(this);
}

Passc::~Passc()
{
    delete ui;
}

void Passc::on_pushButton_clicked()
{
    QString mail=ui->mail->text();
    if(list.contains(mail))
    {
        ui->pass->setText(list.value(mail));
    }
}

