#pragma once
#ifndef SORTINGMETHODS_H
#define SORTINGMETHODS_H
#include <list>
using namespace std;
namespace SortingMethods {	
	void swap(int& firstElement, int& secondElement);
	void shakerSort(int array[], int n);
	void merge(int array[], int start, int middle, int end);
	void mergeSort(int array[], int start, int end);	

	void shakerSort(list<int>& lst);
	void merge(list<int>& lst, std::list<int>& left, std::list<int>& right);
	void mergeSort(list<int>& lst);
}

#endif