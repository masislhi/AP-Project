#include "person.h"

class PersonData : public QSharedData
{
public:

};

//Person::Person() : data(new PersonData)
//{

//}

//Person::Person(const Person &rhs)
//    : data{rhs.data}
//{

//}

Person &Person::operator=(const Person &rhs)
{
//    if (this != &rhs)
//        data.operator=(rhs.data);
//    return *this;
}

Person::~Person()
{

}
