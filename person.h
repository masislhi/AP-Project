#ifndef PERSON_H
#define PERSON_H

#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>
#include <string>

class PersonData;

class Person
{
public:
    Person(std::string name, std::string role);
    virtual ~Person();
    Person &operator=(const Person &rhs);

    std::string name() const;
    void setName(const std::string &newName);

    std::string role() const;
    void setRole(const std::string &newRole);

private:
    std::string m_name;
    std::string m_role;
};

#endif // PERSON_H
