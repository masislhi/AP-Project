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
public slots:


private slots:

    void on_Send_Info_Organ_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_3_clicked();

    void on_Delete_organization_clicked();

private:

    Organization* organization;
    Team* team;
private:
    Ui::TaskManager *ui;
};
#endif // TASKMANAGER_H
