#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;
class Employee
{
private:
	string firstName;
	string lastName;
	string position;
	double salary;
public :
	Employee() : firstName(""), lastName(""), position(""), salary(0.0) {}
	Employee(const string& fName, const string& lName, const string& pos, double sal)
		: firstName(fName), lastName(lName), position(pos), salary(sal) {}
	double getSalary() const;
	string getFirstName() const;
	string getLastName() const;
};

ostream& operator << (std::ostream& os, const Employee& med);

#endif
