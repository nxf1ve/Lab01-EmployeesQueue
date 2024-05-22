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
#define MAX_EMPLOYEES 100000

using namespace std;
using namespace std::chrono;


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
};
template <class T>
class AdtQueueWrapper : public IntetfaceToAdt<T>
{
public:
    class Queue
    {
    public:
        T* data;
        Queue* next;

        Queue(T* data) {
            this->data = data;
            next = nullptr;
        }
    };

    Queue* head;

    AdtQueueWrapper() {
        head = nullptr;
    }

    int deleteForIndex(int index) {
        int cnt = 0;
        Queue* realptr = head;
        if (index == 0) { this->pop(); return 1; }
        while (cnt < index - 1 || realptr == nullptr)
        {
            if (realptr == nullptr) {
                return 0;
            }
            ++cnt;
            realptr = realptr->next;
        }
        if (realptr->next == nullptr || index < 0) { return 0; }

        Queue* getnextpetr = realptr->next, * twoxnextpr = realptr->next->next;
        delete getnextpetr->data;
        delete getnextpetr;
        realptr->next = twoxnextpr;
        return 1;
    }



    void clear() override
    {
        if (isEmpty()) { return; }
        Queue* realPtr = head->next;
        while (realPtr != nullptr) {
            delete head->data;
            delete head;
            head = realPtr;
            realPtr = realPtr->next;
        }
        head = nullptr;
    }

    bool isEmpty() override {
        return (head == nullptr);
    }

    void pop() override {
        if (isEmpty()) { return; }
        Queue* realptr = head->next;
        delete head->data;
        delete head;
        head = realptr;
    }

    T* front() override {
        return (*head).data;
    }

    void push(T* t) override {

        if (isEmpty())
        {
            this->head = new Queue(t);
            return;
        }
        Queue* realPtr = head;
        while (realPtr->next != nullptr) {
            realPtr = realPtr->next;
        }
        realPtr->next = new Queue(t);
    }

    void printAdt() override {
        if (isEmpty())
        {
            cout << "NULL" << endl;
            return;
        }
        cout << *(head->data);
        cout << " -> ";
        Queue* realPtr = head->next;
        while (realPtr != nullptr) {
            cout << *(realPtr->data);
            cout << " -> ";
            realPtr = realPtr->next;
        }
        cout << "NULL" << endl;
    }

    T* getForIndex(int index) {
        int cnt = 0;
        Queue* realptr = head;
        while (cnt != index || realptr == nullptr)
        {
            if (realptr == nullptr) {
                return nullptr;
            }
            ++cnt;
            realptr = realptr->next;
        }
        return realptr->data;
    }
};

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
    setlocale(LC_ALL, "RU");
    AdtQueueWrapper<Employee> myQueue;
    myQueue.push(new Employee("John", "Doe", "Manager", 5000));
    myQueue.push(new Employee("Jane", "Smith", "Developer", 4000));
    myQueue.printAdt();
    myQueue.pop();
    myQueue.printAdt();
    myQueue.push(new Employee("Alice", "Johnson", "Designer", 4500));
    myQueue.printAdt();

    /*Queue<Medicament> teammateQueue;
    teammateQueue.push(new Medicament(100, "Арбидол"));
    teammateQueue.push(new Medicament(100, "Тамыаы"));
    teammateQueue.printAdt();
    teammateQueue.pop();
    teammateQueue.printAdt();*/


   /* vector<int> vec;
    measureVectorPush(vec, 10000);
    measureVectorPop(vec, 10000);   */
    
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