#ifndef DESK_H
#define DESK_H

#include <QWidget>

namespace Ui {
class desk;
}

class desk : public QWidget
{
    Q_OBJECT

public:
    explicit desk(QWidget *parent = nullptr);
    void user(QString  rec)
    {
        use=rec;
    }
    ~desk();

private slots:
    void on_pushButton_clicked();

private:
    Ui::desk *ui;
    QString use;
};

#endif // DESK_H
