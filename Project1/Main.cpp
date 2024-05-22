#include "Employee.h"
#include "Medicament.h"
#include <random>
#include <iostream>
#include <ctime>
#include <list>
#include <vector>
#include <iomanip>
#include <chrono>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include "Task1.h"
#include <fstream>
#define MAX_EMPLOYEES 100000

using namespace std;
using namespace std::chrono;

Employee* readNewObj() {
    string firstName;
    string lastName;
    string position;
    double Salary;
    in >> 
}

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
            cout << *elements[current] << endl;
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

void printVector(vector<int> vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;   
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void measureQueuePush(Queue<int>& q, int count) {
    auto start = high_resolution_clock::now();
    for (int i = 0; i < count; ++i) {
        q.push(new int(rand()));
    }
    auto finish = high_resolution_clock::now();

    duration<double> elapsedTime = finish - start;
    cout << "Time taken for push(" << count << " elements): " << fixed << setprecision(9) << elapsedTime.count() << " seconds" << endl;
}

void measureQueuePop(Queue<int>& q, int count) {
    for (int i = 0; i < count; ++i) {
        q.push(new int(rand()));
    }

    auto start = high_resolution_clock::now();
    for (int i = 0; i < count; ++i) {
        if (!q.isEmpty()) {
            q.pop();
        }
    }
    auto finish = high_resolution_clock::now();

    duration<double> elapsedTime = finish - start;
    cout << "Time taken for pop(" << count << " elements): " << fixed << setprecision(9) << elapsedTime.count() << " seconds" << endl;
}
void main() {
   /* Queue<Employee> myQueue;
    myQueue.push(new Employee("John", "Doe", "Manager", 5000));
    myQueue.push(new Employee("Jane", "Smith", "Developer", 4000));
    myQueue.printAdt();
    myQueue.pop();
    myQueue.printAdt();
    myQueue.push(new Employee("Alice", "Johnson", "Designer", 4500));
    myQueue.printAdt();

    Queue<Medicament> teammateQueue;
    teammateQueue.push(new Medicament(100, "ABD"));
    teammateQueue.printAdt();*/

    vector<int> vec;
    measureVectorPush(vec, 10000);
    measureVectorPop(vec, 10000);   
    
   /* stack<int> stk;
    measureStackPush(stk, 10000);
    measureStackPop(stk, 10000);*/

    /*queue<int> q;
    measureQueuePush(q, 320000);
    measureQueuePop(q, 320000); */
     
    /*Queue<int> q;
    measureQueuePush(q, 80000);
    measureQueuePop(q, 80000);*/

    /*map<int, int> m;
    measureMapInsert(m, 320000);
    measureMapErase(m, 320000);*/

    /*unordered_map<int, int> um;
    measureUnorderedMapInsert(um, 10000);
    measureUnorderedMapErase(um, 10000);*/
 

}