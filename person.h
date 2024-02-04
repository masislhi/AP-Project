#ifndef PERSON_H
#define PERSON_H

#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>
#include <string>

#include <QObject>
#include <string>

class Organization;

class Person : public QObject
{
    Q_OBJECT
public:
    Person(std::string name, std::string role, QObject *parent = nullptr);
    virtual ~Person();
    Person &operator=(const Person &rhs);

    std::string name() const;
    void setName(const std::string &newName);

    std::string role() const;
    void setRole(const std::string &newRole);

    Organization *organiation() const;
    void setOrganiation(Organization *newOrganiation);


private:
    std::string m_name;
    std::string m_role;

    Organization *m_organiation = nullptr;
};

#endif // PERSON_H
