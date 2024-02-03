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

    std::string getName();
    void setName(std::string name);
    std::string getRole();
    void setRole(std::string role);
    Person &operator=(const Person &rhs);

private:
    std::string m_name;
    std::string m_role;
};

#endif // PERSON_H
