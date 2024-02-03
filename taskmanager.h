#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QMainWindow>
#include <QObject>
#include <QMessageBox>
#include "organization.h"
#include "Team.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TaskManager; }
QT_END_NAMESPACE

class TaskManager : public QMainWindow
{
    Q_OBJECT

public:
    TaskManager(QWidget *parent = nullptr);
    ~TaskManager();

    void Create_Organ(const QString& name ,const QString& task,const QString& information);

signals:
    void organizationCreatedSignal(QString,QString,QString);
private slots:

    void on_Send_Info_Organ_clicked();

    void on_Add_person_clicked();

    void on_Delete_organization_clicked();

    void on_Chenge_member_Rol_clicked();

    void on_Delete_member_clicked();


private:

   // Organization* organization;
    std::vector<Organization *> organizations;
    Team* team;
private:
    Ui::TaskManager *ui;
};
#endif // TASKMANAGER_H
