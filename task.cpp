#include "task.h"
#include "ui_task.h"
#include "newtask.h"
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QDir>
#include <string>
#include <QString>
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#define CURRENT_SOURCE_DIR std::string(__FILE__).substr(0,std::string(__FILE__).find_last_of("/\\"))
int countfiles(QString search,QStringList& list)
{
    QDir directiry(QString::fromStdString(CURRENT_SOURCE_DIR));
    QStringList files=directiry.entryList(QDir::Files);
    int count =0;
    for(QString filename : files)
    {
        if(filename.contains(search))
        {
            count++;
            QString origin=filename;
            origin.replace((search+"_"),"");
            origin.replace(".txt","");
            list<<origin;
        }
    }
    return count;
}
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
    close();
}


void Task::on_pushButton_clicked()
{
    alltasks.setWindowTitle("All Tasks");
    alltasks.setGeometry(100,100,400,200);
    QGridLayout* gridlayout=new QGridLayout(&alltasks);
    for(int i=0;i<countfiles(use,tasks);++i)
    {

        QPushButton* button = new QPushButton(tasks.at(i),&alltasks);
        gridlayout->addWidget(button,i/3,i%3);
        connect(button,&QPushButton::clicked,this,&Task::on_b_clicked);
    }

    alltasks.show();
}

void Task::on_b_clicked()
{
    QPushButton* clicked=qobject_cast<QPushButton*>(sender());
    if(clicked)
    {
        int index = tasks.indexOf(clicked->text());
        if(index>=0 && index<tasks.size())
        {
            QFile file(QString::fromStdString(CURRENT_SOURCE_DIR)+"/"+use+"_"+tasks.at(index)+".txt");
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream in(&file);
            QString content=in.readAll();
            file.close();
            QDialog* contentWindow=new QDialog(this);
            QVBoxLayout* lay=new QVBoxLayout(contentWindow);
            QLabel* contentlable=new QLabel(content);
            lay->addWidget(contentlable);
            QPushButton* button = new QPushButton("CHANGE",&alltasks);
            lay->addWidget(button);
            connect(button,&QPushButton::clicked,[=](){
                contentWindow->close();
                change_maker(clicked->text());

            });

            contentWindow->exec();
        }
    }
}
void Task::change_maker(QString name)
{
    QFile file(QString::fromStdString(CURRENT_SOURCE_DIR)+"/"+use+"_"+name+".txt");
    file.remove();
    newtask *n =new newtask();
    n->user(use);
    n->show();
}
