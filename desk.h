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
    ~desk();

private:
    Ui::desk *ui;
};

#endif // DESK_H
