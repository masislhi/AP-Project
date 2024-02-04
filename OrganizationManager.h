#pragma once

#include <QDialog>
#include "organization.h"

namespace Ui {
class Organization;
}

class OrganizationManager : public QDialog
{
    Q_OBJECT
public:
    OrganizationManager(QDialog *parent = nullptr);

public slots:
    Organization *onAddOrganization(const QString &name,
                                    const QString &task,
                                    const QString &information);
    bool onDeleteOrganizaition(const QString &name);

public slots:
    void updateList();
signals:
    void organizationsChanged(QList<Organization *> newList);


protected:
    QHash<QString, Organization *> m_organizations;
    Ui::Organization *ui;
};
