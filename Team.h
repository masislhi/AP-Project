#ifndef TEAM_H
#define TEAM_H

#include <QWidget>
#include "organization.h"
#include "person.h"
namespace Ui {
class Team;
}

class Team : public Organization
{
public:
    Team(std::string name, std::string task);
    virtual ~Team();

//    void deleteTeam();
    void addTeamMember(Person* member);
    void removeTeamMember(Person* member);
    void changeTeamRole(Person* member, std::string newRole);
    void listTeamMembers();
    void filterTeamMembers(std::string roleFilter);
    void sortTeamMembers();

private:
    std::vector<Person*> m_teamMembers;

public:
explicit Team(QWidget *parent = nullptr);
//~Team();

private:
Ui::Team *ui;
};

#endif // TEAM_H
