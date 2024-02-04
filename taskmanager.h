#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QMainWindow>
#include <QMessageBox>
#include <QObject>
#include "PersonManager.h"
#include "Team.h"
#include "organization.h"
#include "qhash.h"
#include <OrganizationManager.h>

QT_BEGIN_NAMESPACE
namespace Ui { class TaskManager; }
QT_END_NAMESPACE

Q_DECLARE_METATYPE(QList<Organization *>)

class TaskManager : public QMainWindow
{
    Q_OBJECT

public:
    TaskManager(QMainWindow *parent = nullptr);
    ~TaskManager();

protected:
    void createOrganizaition(const QString &name, const QString &task, const QString &information);
    void createPerson(const QString &name, const QString &role);

signals:
    void organizationCreatedSignal(QString, QString, QString);
private slots:

    void on_Send_Info_Organ_clicked();

    void on_Add_person_clicked();

    void on_Delete_organization_clicked();

    void on_Chenge_member_Rol_clicked();

    void on_Delete_member_clicked();

    void on_viewOrganizations_clicked();

private:
    // Organization* organization;

    Team *m_team = nullptr;
    OrganizationManager *m_organizationManager = nullptr;
    PersonManager *m_personManager = nullptr;
    Organization *m_curentOrganizaition = nullptr;

private:
    Ui::TaskManager *ui = nullptr;
};
#endif // TASKMANAGER_H
