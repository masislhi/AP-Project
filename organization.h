#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include <QObject>
#include "person.h"
#include "qhash.h"
#include <vector>

class Organization : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(QString task READ task WRITE setTask NOTIFY taskChanged FINAL)
    Q_PROPERTY(QString info READ info WRITE setInfo NOTIFY infoChanged FINAL)

public:
    explicit Organization(QString name,
                          QString task,
                          QString information,
                          QObject *parent = nullptr);
    Organization(QString name, QString task, QObject *parent = nullptr);
    ~Organization();
    void addMember(Person *person);

    void editOrganization(const QString& newName);

    void deleteOrganization();

    void removeMember(const QString& member);

    void changeMemberRole(const QString& member, const QString& newRole);

    QHash<QString, Person *> getMemberList();

    QList<QString> getFilteredAndSortedMembers(const QString& filter);

    QString name() const;

    QString task() const;

    QString info() const;

    int totalMember() const;

public slots:
    void setName(const QString &newName);

    void setTask(const QString &newTask);

    void setInfo(const QString &newInfo);

signals:

    void organizationCreated(const QString &name);

    void organizationEdited(const QString &newName);

    void organizationDeleted();

    void memberAdded(const QString& member);

    void memberRemoved(const QString& member);

    void roleChanged(const QString& member, const QString& newRole);

    void nameChanged(QString name);

    void taskChanged(QString task);

    void infoChanged(QString info);

private:
    QString m_name;
    QString m_task;
    QString m_info;

    QHash<QString, Person *> m_memberList;
};

#endif // ORGANIZATION_H

