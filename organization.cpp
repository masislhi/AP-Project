#include "organization.h"

Organization::Organization(QString name, QString task, QString information, QObject *parent)
    : QObject(parent)
{
    this->m_name=name;
    this->m_task = task;
    m_info = information;
}
Organization::Organization(QString name, QString task, QObject *parent)
    : QObject(parent)
{
    this->m_name = name;
    this->m_task = task;
    m_info = "";
}
Organization::~Organization()
{
}

//void Organization::createOrganization(const QString& name)
//{
//    m_name = name;
//    emit organizationCreated(name);
//}

void Organization::addMember(Person *person)
{
    if (person->organiation() != nullptr) {
        person->organiation()->removeMember(QString::fromStdString(person->name()));
    }

    person->setOrganiation(this);
    m_memberList.insert(QString::fromStdString(person->name()), person);
    emit memberAdded(QString::fromStdString(person->name()));
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
    m_memberList.remove(member);
    emit memberRemoved(member);

}

void Organization::changeMemberRole(const QString& member, const QString& newRole)
{

    // Perform role change logic here

    emit roleChanged(member, newRole);
}

QHash<QString, Person *> Organization::getMemberList()

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

QString Organization::name() const
{
    return m_name;
}

void Organization::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged(m_name);
}

QString Organization::task() const
{
    return m_task;
}

void Organization::setTask(const QString &newTask)
{
    if (m_task == newTask)
        return;
    m_task = newTask;
    emit taskChanged(m_task);
}

QString Organization::info() const
{
    return m_info;
}

int Organization::totalMember() const
{
    return m_memberList.count();
}

void Organization::setInfo(const QString &newInfo)
{
    if (m_info == newInfo)
        return;
    m_info = newInfo;
    emit infoChanged(m_info);
}
