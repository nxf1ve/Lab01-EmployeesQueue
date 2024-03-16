#include "Employee.h"
#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue() : size(0), front(0), tail(0) {}

void Queue::insert(const Employee& emp) {
    if ((tail + 1) % MAX_EMPLOYEES == front) {
        cout << "Queue is full" << endl;
    }
    else {
        employees[tail] = emp;
        tail = (tail + 1) % MAX_EMPLOYEES;
        size++;
    }
}

void Queue::remove() {
    if (front == tail) {
        cout << "Queue is empty" << endl;
    }
    else {
        front = (front + 1) % MAX_EMPLOYEES;
        size--;
    }
}

void Queue::paySalaries() {
    cout << "Paying salaries..." << endl;
    int current = front;
    for (int i = 0; i < size; i++) {
        cout << "Paying salary to: " << employees[current].getFirstName()
            << " " << employees[current].getLastName() << endl;
        current = (current + 1) % MAX_EMPLOYEES;
    }
}

void Queue::printAllEmployees() const {
    cout << "Employees in queue: " << endl;
    int current = front;
    for (int i = 0; i < size; i++) {
        employees[current].printEmployeeInformation();
        cout << endl;
        current = (current + 1) % MAX_EMPLOYEES;
    }
}

void Queue::findEmployee(const string& employeeLastName) {
    bool isEmployeeInQueue = false;
    for (int i = 0; i < size; i++) {
        if (employees[i].getLastName() == employeeLastName) {
            cout << "This employee is in the queue, his position: " << i + 1 << endl;
            isEmployeeInQueue = true;
            break;
        }
        
    }
    if (isEmployeeInQueue == false) {
        cout << "This employee is not in the queue" << endl;   
    }
}

