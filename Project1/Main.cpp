#include "Employee.h"
#include "Queue.h"
void main() {
	Queue myQueue;
	myQueue.insert(Employee("John", "Doe", "Manager", 5000));
	myQueue.insert(Employee("Jane", "Smith", "Developer", 4000));
	

	myQueue.printAllEmployees();
	myQueue.remove();
	myQueue.printAllEmployees();
	myQueue.insert(Employee("Alice", "Johnson", "Designer", 4500));
	myQueue.printAllEmployees();
	myQueue.paySalaries();

}