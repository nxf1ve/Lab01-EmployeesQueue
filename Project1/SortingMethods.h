#pragma once
#ifndef SORTINGMETHODS_H
#define SORTINGMETHODS_H
#include <list>
using namespace std;
namespace SortingMethods {	
	void swap(int& firstElement, int& secondElement);
	void shakerSort(int array[], int n);
	void bubbleSort(int array[], int n);
	void merge(int array1[], int array2[], int targetArray[], int array1Length, int array2Length);
	void mergeSort(int array[], int size);

	void shakerSort(list<int>& lst);
	void bubbleSort(list<int>& lst);
	void merge(list<int>& lst, std::list<int>& left, std::list<int>& right);
	void mergeSort(list<int>& lst);
}

#endif