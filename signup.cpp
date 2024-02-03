#include "signup.h"
#include "ui_signup.h"
#include <QMap>
#include <QMessageBox>
#include "mainwindow.h"

bool ValidPass(QString& pass)
{
    if(pass.length()<8)
    {
        QMessageBox::warning(nullptr,"PASSWORD","password too short");
        return false;
    }
    bool hasUppercase=false;
    bool hasLowercase=false;
    bool hasNumber=false;
    for(QChar& c:pass)
    {
        if(c.isUpper())
            hasUppercase=true;
        else if(c.isLower())
            hasLowercase=true;
        else if(c.isDigit())
            hasNumber=true;
    }
    if(!hasUppercase || !hasLowercase || !hasNumber)
    {
        QMessageBox::warning(nullptr,"PASSWORD","password must include at least one uppercase letter, one lowecase letter and a number");
        return false;
    }
    return true;

}
signup::signup(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_clicked()
{
    QString username=ui->txt_user->text();
    QString pass=ui->txt_pass->text();
    QString mail=ui->txt_mail->text();
    if(mlist.contains(mail))
    {
        QMessageBox::warning(this,"sign up","you have signed up before!");
        close();
    }

    if(ValidPass(pass))
    {
        page.insert(username,pass);
        mlist.insert(mail,pass);
        if(ui->txt_mail->text().isEmpty()|| ui->txt_pass->text().isEmpty()  || ui->txt_user->text().isEmpty())
            QMessageBox::warning(this,"sign up","fill all the blanks!!");

        close();
    }
    MainWindow *w=new MainWindow();
    w->reclist(mlist);
    w->recmap(page);
    w->show();

}

