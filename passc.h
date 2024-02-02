#ifndef PASSC_H
#define PASSC_H

#include <QWidget>

namespace Ui {
class Passc;
}

class Passc : public QWidget
{
    Q_OBJECT

public:
    explicit Passc(QWidget *parent = nullptr);
    void rec(QMap<QString,QString> & rec)
    {
        list=rec;
    }
    ~Passc();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Passc *ui;
    QMap<QString,QString> list;
};

#endif // PASSC_H
