#include "Employee.h"
#include "Medicament.h"
#include "SortingMethods.h"
#include <random>
#include <iostream>
#include <ctime>
#include <list>
#include <vector>
#define MAX_EMPLOYEES 100

using namespace std;
using namespace SortingMethods;

template <class T>
class IntetfaceToAdt {
public:
    virtual void clear() = 0;
    virtual bool isEmpty() = 0;
    virtual void push(T* const t) = 0;
    virtual void pop() = 0;
    virtual T* front() = 0;
    virtual void printAdt() = 0;
    virtual T* getForIndex(int index) = 0;
};

// Шаблонный класс очереди, реализующий интерфейс
template <class T>
class Queue : public IntetfaceToAdt<T> {
private:
    T* elements[MAX_EMPLOYEES];
    int size;
    int frontIndex;
    int tail;
public:
    Queue() : size(0), frontIndex(0), tail(0) {}

    void clear() override {
        size = 0;
        frontIndex = 0;
        tail = 0;
    }

    bool isEmpty() override {
        return size == 0;
    }

    void push(T* const t) override {
        if ((tail + 1) % MAX_EMPLOYEES == frontIndex) {
            cout << "Queue is full" << endl;
        }
        else {
            elements[tail] = t;
            tail = (tail + 1) % MAX_EMPLOYEES;
            size++;
        }
    }

    void pop() override {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        }
        else {
            frontIndex = (frontIndex + 1) % MAX_EMPLOYEES;
            size--;
        }
    }

    T* front() override {
        if (isEmpty()) {
            return nullptr;
        }
        return elements[frontIndex];
    }

    void printAdt() override {
        cout << "Elements in queue: " << endl;
        int current = frontIndex;
        for (int i = 0; i < size; i++) {
            elements[current]->printInformation();
            cout << endl;
            current = (current + 1) % MAX_EMPLOYEES;
        }
    }

    T* getForIndex(int index) override {
        if (index < 0 || index >= size) {
            return nullptr;
        }
        return elements[(frontIndex + index) % MAX_EMPLOYEES];
    }

    void paySalaries() {
        cout << "Paying salaries..." << endl;
        int current = frontIndex;
        for (int i = 0; i < size; i++) {
            cout << "Paying salary to: " << elements[current]->getFirstName()
                << " " << elements[current]->getLastName() << endl;
            current = (current + 1) % MAX_EMPLOYEES;
        }
    }

    void findEmployee(const string& employeeLastName) {
        bool isEmployeeInQueue = false;
        int current = frontIndex;
        for (int i = 0; i < size; i++) {
            if (elements[current]->getLastName() == employeeLastName) {
                cout << "This employee is in the queue, his position: " << (current - frontIndex + MAX_EMPLOYEES) % MAX_EMPLOYEES + 1 << endl;
                isEmployeeInQueue = true;
                break;
            }
            current = (current + 1) % MAX_EMPLOYEES;
        }
        if (!isEmployeeInQueue) {
            cout << "This employee is not in the queue" << endl;
        }
    }
};

    //void paySalaries() {
    //    cout << "Paying salaries..." << endl;
    //    int current = front;
    //    for (int i = 0; i < size; i++) {
    //        cout << "Paying salary to: " << employees[current]->getFirstName()
    //            << " " << employees[current]->getLastName() << endl;
    //        current = (current + 1) % MAX_EMPLOYEES;
    //    }
    //}

    //void findEmployee(const string& employeeLastName) {
    //    bool isEmployeeInQueue = false;
    //    int current = front;
    //    for (int i = 0; i < size; i++) {
    //        if (employees[current]->getLastName() == employeeLastName) {
    //            cout << "This employee is in the queue, his position: " << (current - front + MAX_EMPLOYEES) % MAX_EMPLOYEES + 1 << endl;
    //            isEmployeeInQueue = true;
    //            break;
    //        }
    //        current = (current + 1) % MAX_EMPLOYEES;
    //    }
    //    if (!isEmployeeInQueue) {
    //        cout << "This employee is not in the queue" << endl;
    //    }
    //}

vector<int> generateRandomVector(int min, int max, int count) {
    vector<int> vec;
	for (int i = 0; i < count; i++) {
		vec.push_back(min + rand() % max);
	}
    return vec;
}
void printVector(vector<int> vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;   
}

void generateRandomList(list<int>& lst, int size, int min, int max) {
	for (int i = 0; i < size; i++) {
		lst.push_back(min + rand() % max);
	}
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void printList(const list<int>& lst) {
	for (int num : lst) {
		cout << num << " ";
	}
	cout << endl;
}
void main() {
   /* Queue<Employee> myQueue;
    myQueue.push(new Employee("John", "Doe", "Manager", 5000));
    myQueue.push(new Employee("Jane", "Smith", "Developer", 4000));
    myQueue.printAdt();
    myQueue.pop();
    myQueue.printAdt();
    myQueue.push(new Employee("Alice", "Johnson", "Designer", 4500));
    myQueue.printAdt();*/

  /*  Queue<Medicament> teammateQueue;
    teammateQueue.push(new Medicament(100, "ABD"));
    teammateQueue.printAdt();*/
   	
    vector<int> vec = generateRandomVector(5, 25, 25);
    printVector(vec);
    
    
    

}