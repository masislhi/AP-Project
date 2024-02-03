#include "person.h"

class PersonData : public QSharedData
{
public:

};

//Person::Person() : data(new PersonData)
//{

//}

//Person::Person(const Person &rhs)
//    : data{rhs.data}
//{

//}

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

Person::~Person() {}
