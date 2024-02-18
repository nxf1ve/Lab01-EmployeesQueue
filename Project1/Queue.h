#ifndef EMPLOYEE_QUEUE_H
#define EMPLOYEE_QUEUE_H
#define MAX_EMPLOYEES 100
#include "employee.h"
class Queue
{
private:
	Employee employees[MAX_EMPLOYEES];
	int size;
	int front;
	int tail;	
public:
	Queue();
	void insert(const Employee& emp);
	void remove();
	void paySalaries();
	void printAllEmployees() const;
};
#endif

