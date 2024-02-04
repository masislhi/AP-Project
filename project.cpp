#include "project.h"
#include <algorithm>

Project::Project(std::string name, std::string status)
    : m_projectName(name), m_status(status)
{}

Project::~Project() {}

void Project::addMember(std::string member)
{
    m_projectMembers.push_back(member);
}

void Project::removeMember(QString member)
{
    auto it = std::find(m_projectMembers.begin(), m_projectMembers.end(), member.toStdString());
    if (it != m_projectMembers.end()) {
        m_projectMembers.erase(it);
    }
}

void Project::editProject(std::string name, std::string status)
{
    m_projectName = name;
    m_status = status;
}

void Project::deleteProject()
{
    m_projectMembers.clear();
}

void Project::changeStatus(std::string newStatus)
{
    m_status = newStatus;
}

void Project::listMemberProjects(std::string member)
{
    for (const auto& project : m_projectMembers) {
//        std::cout << project << std::endl;
    }
}
