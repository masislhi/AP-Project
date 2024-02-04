#pragma once

#include <QObject>
#include "person.h"

class PersonManager : public QObject
{
    Q_OBJECT
public:
    PersonManager(QObject *parent);

public slots:
    Person *onAddPerson(QString name, QString role);
    bool onRemovePerson(QString name);

protected:
    QHash<QString, Person *> m_persons;
};
