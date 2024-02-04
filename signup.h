#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <QMap>

namespace Ui {
class signup;
}

class signup : public QWidget
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_pushButton_clicked();

private:
    Ui::signup *ui;
    QMap<QString,QString> page;
    QMap<QString,QString> mlist;

};

#endif // SIGNUP_H
