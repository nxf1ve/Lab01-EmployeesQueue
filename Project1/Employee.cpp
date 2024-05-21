#include "Employee.h"
#include <string>
#include <iostream>
using namespace std;

double Employee::getSalary() const {
    return salary;
}
string Employee::getFirstName() const {
    return firstName;
}
string Employee::getLastName() const {
    return lastName;
}
ostream& operator << (std::ostream& os, const Employee& empl)
{
    return os << empl.getLastName() << " " << empl.getSalary();
}

