#include "taskmanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TaskManager taskManager;

    taskManager.show();
    return a.exec();
}
