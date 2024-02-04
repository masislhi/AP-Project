#include "taskmanager.h"
#include <QApplication>
#include <QLineEdit>
#include <QList>
#include <QObject>
#include <QPushButton>
#include <QVBoxLayout>
#include "OrganizationManager.h"
#include "PersonManager.h"
#include "organization.h"
#include "qmessagebox.h"
#include "ui_taskmanager.h"

TaskManager::TaskManager(QMainWindow *parent)
    : QMainWindow(parent)
    , ui(new Ui::TaskManager)
{
    ui->setupUi(this);
    qRegisterMetaType<QList<Organization *>>();
    m_organizationManager = new OrganizationManager();
    m_personManager = new PersonManager(this);
}

TaskManager::~TaskManager()
{
    delete ui;
}
void TaskManager::createOrganizaition(const QString &name,
                                      const QString &task,
                                      const QString &information)
{
    auto newOrganizaition = m_organizationManager->onAddOrganization(name, task, information);
    if (newOrganizaition != nullptr) {
        m_curentOrganizaition = newOrganizaition;
        emit organizationCreatedSignal(name, task, information);
        QMessageBox::information(this,
                                 "Success adding organization",
                                 "Organization is successfully added.");
    } else {
        QMessageBox::critical(this,
                              "Fail adding organization",
                              "Adding Organization is failed. Name of organization is duplicate.");
    }
}

void TaskManager::createPerson(const QString &name, const QString &role)
{
    auto newPerson = m_personManager->onAddPerson(name, role);
    if (newPerson != nullptr) {
        QMessageBox::information(this, "Success adding person", "Person is successfully added.");
        if (m_curentOrganizaition != nullptr) {
            m_curentOrganizaition->addMember(newPerson);
        }
    } else {
        QMessageBox::critical(this,
                              "Fail adding person",
                              "Adding Person is failed. Name of person is duplicate.");
    }
}

void TaskManager::on_Send_Info_Organ_clicked()
{
//    QList<QLineEdit*> Creat_Oganization;
    QString Name_Organ=ui->N_Organ->text();
    QString Organization_Task=ui->Organ_Task->text();
    QString Organization_Information=ui->Organ_Info->text();
    createOrganizaition(Name_Organ, Organization_Task, Organization_Information);
}
void TaskManager::on_Add_person_clicked()
{
    QString Name_person=ui->N_person->text();
    QString Rol_Person =ui->Rol_person->text();
    createPerson(Name_person, Rol_Person);
}

void TaskManager::on_Delete_organization_clicked()
{
    QString organizaitionName = ui->Delete_organ->text();
    if (m_organizationManager->onDeleteOrganizaition(organizaitionName)) {
        if (m_curentOrganizaition->name() == organizaitionName)
            m_curentOrganizaition = nullptr;
        QMessageBox::information(this,
                                 "Success organization removal",
                                 "Organization is successfully deleted.");
    } else {
        QMessageBox::critical(
            this,
            "Fail organization removal",
            "Removing Organization is failed. Don't find organization with this name.");
    }
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

    m_personManager->onRemovePerson(Delete_member);
}

void TaskManager::on_viewOrganizations_clicked()
{
    m_organizationManager->show();
}
