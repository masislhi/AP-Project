#include "PersonManager.h"
#include "person.h"

PersonManager::PersonManager(QObject *parent)
    : QObject(parent)
{}

Person *PersonManager::onAddPerson(QString name, QString role)
{
    if (!m_persons.contains(name)) {
        auto newPerson = new Person(name.toStdString(), role.toStdString());
        m_persons.insert(name, newPerson);

        return newPerson;
    }
    return nullptr;
}

bool PersonManager::onRemovePerson(QString name)
{
    if (m_persons.contains(name)) {
        m_persons.remove(name);

        return true;
    }
    return false;
}
