#include "OrganizationManager.h"
#include "qmainwindow.h"
#include "ui_organization.h"

OrganizationManager::OrganizationManager(QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::Organization)
{
    ui->setupUi(this);
}

Organization *OrganizationManager::onAddOrganization(const QString &name,
                                                     const QString &task,
                                                     const QString &information)
{
    if (!m_organizations.contains(name)) {
        Organization *New_Organ = new Organization(name, task, information);
        m_organizations.insert(name, New_Organ);
        emit organizationsChanged(m_organizations.values());
        updateList();
        connect(New_Organ, SIGNAL(memberAdded(QString)), this, SLOT(updateList()));
        connect(New_Organ, SIGNAL(memberRemoved(QString)), this, SLOT(updateList()));
        connect(New_Organ, SIGNAL(nameChanged(QString)), this, SLOT(updateList()));
        connect(New_Organ, SIGNAL(infoChanged(QString)), this, SLOT(updateList()));
        connect(New_Organ, SIGNAL(roleChanged(QString, QString)), this, SLOT(updateList()));
        connect(New_Organ, SIGNAL(taskChanged(QString)), this, SLOT(updateList()));
        connect(New_Organ, SIGNAL(organizationCreated(QString)), this, SLOT(updateList()));
        connect(New_Organ, SIGNAL(organizationDeleted()), this, SLOT(updateList()));
        connect(New_Organ, SIGNAL(organizationEdited(QString)), this, SLOT(updateList()));
        return New_Organ;
    }
    return nullptr;
}

bool OrganizationManager::onDeleteOrganizaition(const QString &name)
{
    if (m_organizations.contains(name)) {
        m_organizations.remove(name);
        emit organizationsChanged(m_organizations.values());
        updateList();
        return true;
    }

    return false;
}

void OrganizationManager::updateList()
{
    ui->tableWidget->setRowCount(m_organizations.count());

    int row = 0;
    for (auto organization : m_organizations) {
        QTableWidgetItem *nameItem = new QTableWidgetItem(organization->name());
        ui->tableWidget->setItem(row, 0, nameItem);

        QTableWidgetItem *taskItem = new QTableWidgetItem(organization->task());
        ui->tableWidget->setItem(row, 1, taskItem);

        QTableWidgetItem *infoItem = new QTableWidgetItem(organization->info());
        ui->tableWidget->setItem(row, 2, infoItem);

        QTableWidgetItem *totalMemberItem = new QTableWidgetItem(
            QString::number(organization->totalMember()));
        ui->tableWidget->setItem(row, 3, totalMemberItem);
        row++;
    }
}
