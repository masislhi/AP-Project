#include "person.h"

Person &Person::operator=(const Person &rhs)
{
    //    if (this != &rhs)
    //        data.operator=(rhs.data);
    //    return *this;
}

std::string Person::name() const
{
    return m_name;
}

void Person::setName(const std::string &newName)
{
    m_name = newName;
}

std::string Person::role() const
{
    return m_role;
}

void Person::setRole(const std::string &newRole)
{
    m_role = newRole;
}


Organization *Person::organiation() const
{
    return m_organiation;
}

void Person::setOrganiation(Organization *newOrganiation)
{
    m_organiation = newOrganiation;
}

Person::Person(std::string name, std::string role, QObject *parent)
    : QObject(parent)
    , m_name(name)
    , m_role(role)
{}

Person::~Person() {}
