#include "taskmanager.h"
#include <QApplication>
#include <QLineEdit>
#include <QList>
#include <QObject>
#include <QPushButton>
#include <QVBoxLayout>
#include "organization.h"
#include "ui_taskmanager.h"

TaskManager::TaskManager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TaskManager)
{
    ui->setupUi(this);

}

TaskManager::~TaskManager()
{
    delete ui;
}
void TaskManager::Create_Organ(const QString& name ,const QString& task,const QString& information)
{
    Organization *New_Organ = new Organization(name, task, information);
    organizations.push_back(New_Organ);
    emit organizationCreatedSignal(name,task ,information);
}

void TaskManager::on_Send_Info_Organ_clicked()
{
//    QList<QLineEdit*> Creat_Oganization;
    QString Name_Organ=ui->N_Organ->text();
    QString Organization_Task=ui->Organ_Task->text();
    QString Organization_Information=ui->Organ_Info->text();
    Create_Organ(Name_Organ,Organization_Task,Organization_Information);
}
void TaskManager::on_Add_person_clicked()
{
    QString Name_person=ui->N_person->text();
    QString Rol_Person =ui->Rol_person->text();
}

void TaskManager::on_Delete_organization_clicked()
{
    QString Name_Organ_del=ui->Delete_organization->text();
    //Organization
}


void TaskManager::on_Chenge_member_Rol_clicked()
{
    QString Get_NameMember =ui->Name_member->text();
    QString ChengeNew_Rol = ui ->Chenge_member_Rol->text();

}


void TaskManager::on_Delete_member_clicked()
{
    QString Delete_member= ui->L_name_Member->text();

}




