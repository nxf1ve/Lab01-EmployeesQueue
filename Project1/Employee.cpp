#include "Employee.h"
#include <string>
#include <iostream>
using namespace std;

void Employee::printInformation() const {
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Position: " << position << endl;
    cout << "Salary: " << salary << endl;
}
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

