#ifndef NEWTASK_H
#define NEWTASK_H

#include <QWidget>

namespace Ui {
class newtask;
}

class newtask : public QWidget
{
    Q_OBJECT

public:
    explicit newtask(QWidget *parent = nullptr);
    void user(QString & rec)
    {
        use=rec;
    }
    ~newtask();

private slots:
    void on_pushButton_clicked();

private:
    Ui::newtask *ui;
    QString use;
};

#endif // NEWTASK_H
