#include "organization.h"
#include "ui_organization.h"

Organization::Organization(QString name ,QString task,QString information,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Organization)
{
    ui->setupUi(this);
    this->m_name=name;
    this->Task_Organization=task;
    Info_Organization=information;
}
Organization::Organization(QString name, QString task, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Organization)
{
    ui->setupUi(this);
    this->m_name = name;
    this->Task_Organization = task;
    Info_Organization = "";
}
Organization::~Organization()
{
    delete ui;
}

//void Organization::createOrganization(const QString& name)
//{
//    m_name = name;
//    emit organizationCreated(name);
//}

void Organization::addMember(const QString& member ,const QString& memberRol)
{
    m_memberList.append(member);
    emit memberAdded(member);
}

void Organization::deleteOrganization()
{
    m_name.clear();
    m_memberList.clear();
    emit organizationDeleted();
}

void Organization::editOrganization(const QString& newName)
{

    m_name = newName;
    emit organizationEdited(newName);
}

void Organization::removeMember(const QString& member)
{
    m_memberList.removeOne(member);
    emit memberRemoved(member);

}

void Organization::changeMemberRole(const QString& member, const QString& newRole)
{

    // Perform role change logic here

    emit roleChanged(member, newRole);
}

QList<QString> Organization::getMemberList()

{
    return m_memberList;
}


QList<QString> Organization::getFilteredAndSortedMembers(const QString& filter)
{
    QList<QString> filteredList;
    // Perform filtering and sorting logic here

    // Add the filtered and sorted members to "filteredList"

    return filteredList;
}
