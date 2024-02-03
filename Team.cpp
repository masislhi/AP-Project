#include "Team.h"
#include "person.h"
#include "ui_team.h"
#include <algorithm>
#include <iostream>
Team::Team(std::string name, std::string task)
    : Organization(QString::fromStdString(name), QString::fromStdString(task))
{}

Team::~Team()
{
    //deleteTeam();
}


void Team::addTeamMember(Person* member)
{
    m_teamMembers.push_back(member);
}

void Team::removeTeamMember(Person* member)
{
    auto it = std::find(m_teamMembers.begin(), m_teamMembers.end(), member);
    if (it != m_teamMembers.end())
    {
        m_teamMembers.erase(it);
        removeMember(QString::fromStdString(member->name()));
        delete member;
    }
}

void Team::changeTeamRole(Person* member, std::string newRole)
{
    member->setRole(newRole);
}

void Team::listTeamMembers()
{
    for (Person* member : m_teamMembers)
    {
        std::cout << member->name() << " - " << member->role() << std::endl;
    }
}

void Team::filterTeamMembers(std::string roleFilter)
{
    for (Person* member : m_teamMembers)
    {
        if (member->role() == roleFilter) {
            std::cout << member->name() << " - " << member->role() << std::endl;
        }
    }
}

void Team::sortTeamMembers()
{
    std::sort(m_teamMembers.begin(), m_teamMembers.end(), [](Person *a, Person *b) {
        return a->name() < b->name();
    });
}
//Team::~Team()
//{
//    delete ui;
//}
