#ifndef TASK_H
#define TASK_H

#include <QWidget>

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(QWidget *parent = nullptr);
    void user(QString  rec)
    {
        use=rec;
    }
    ~Task();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
    void on_b_clicked();
    void change_maker(QString name);

private:
    Ui::Task *ui;
    QString use;
    QStringList tasks;
    QWidget alltasks;
};

#endif // TASK_H
