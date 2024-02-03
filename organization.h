#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include <QWidget>
#include <vector>
namespace Ui {
class Organization;
}

class Organization: public QWidget{

    Q_OBJECT

public:
    explicit Organization(QString name,QString task,QString information,QWidget *parent = nullptr);
    ~Organization();
    void addMember(const QString& member ,const QString& memberRol);

    void editOrganization(const QString& newName);

    void deleteOrganization();

    void removeMember(const QString& member);

    void changeMemberRole(const QString& member, const QString& newRole);

    QList<QString> getMemberList();

    QList<QString> getFilteredAndSortedMembers(const QString& filter);


signals:

    void organizationCreated(const QString& name);

    void organizationEdited(const QString& newName);

    void organizationDeleted();

    void memberAdded(const QString& member);

    void memberRemoved(const QString& member);

    void roleChanged(const QString& member, const QString& newRole);


private:

    QString m_name;
    QString Task_Organization;
    QString Info_Organization;

    QList<QString> m_memberList;


private:
    Ui::Organization *ui;
};

#endif // ORGANIZATION_H

