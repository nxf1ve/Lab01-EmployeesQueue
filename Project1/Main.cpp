#include "Employee.h"
#include "Queue.h"
#include "SortingMethods.h"
#include <random>
#include <iostream>
#include <ctime>
#include <list>
using namespace std;
using namespace SortingMethods;
void generateRandomArray(int* arr, int size, int min, int max) {
	for (int i = 0; i < size; i++) {
		arr[i] = min + rand() % max;
	}
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
	Queue myQueue;
	myQueue.insert(Employee("John", "Doe", "Manager", 5000));
	myQueue.insert(Employee("Jane", "Smith", "Developer", 4000));
	

	//myQueue.printAllEmployees();
	//myQueue.remove();
	myQueue.printAllEmployees();
	myQueue.insert(Employee("Alice", "Johnson", "Designer", 4500));
	myQueue.findEmployee("Smith");
	myQueue.printAllEmployees();
	myQueue.paySalaries();
	//int size;
	//cout << "Set array/list size: " << endl;
	//cin >> size;

	//int* arr = new int[size];
	//list<int> lst;

	////generateRandomArray(arr, size, 1, 50);
	//generateRandomList(lst, size, 1, 50);

	//cout << "Initial array/list: " << endl;
	////printArray(arr, size);
	//printList(lst);

	//clock_t start = clock();
	////shakerSort(lst);
	////mergeSort(arr, 0, size - 1);
	//mergeSort(lst);
	//clock_t finish = clock();

	//double elapsedTime = double(finish - start) / CLOCKS_PER_SEC;

	//cout << "\nSorted array/list: " << endl;
	////printArray(arr, size);
	//printList(lst);
	//cout << "\nTime taken for sort: " << elapsedTime << endl;
}