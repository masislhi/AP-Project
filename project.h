#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>
#include <QObject>
#include <QWidget>
class Project
{
public:

    Project(std::string name, std::string status);
    virtual ~Project();

    void addMember(std::string member);
    void removeMember(QString member);
    void editProject(std::string name, std::string status);
    void deleteProject();
    void changeStatus(std::string newStatus);
    void listMemberProjects(std::string member);

private:
    std::string m_projectName;
    std::string m_status;
    std::vector<std::string> m_projectMembers;
};

#endif // PROJECT_H
