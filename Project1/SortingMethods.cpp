#include <iostream>
#include <list>
#include "SortingMethods.h"
using namespace std;
namespace SortingMethods {
	void swap(int& firstElement, int& secondElement) {
		int temp = firstElement;
		firstElement = secondElement;
		secondElement = temp;
	}
	void shakerSort(int array[], int n) {
		bool swapped = 1;
		int start = 0;
		int end = n - 1;
		while (swapped) {
			swapped = 0;
			for (int i = start; i < end; i++) {
				if (array[i] > array[i + 1]) {
					swap(array[i], array[i + 1]);
					swapped = 1;
				}
			}
			if (!swapped)
				break;
			--end;
			swapped = 0;
			for (int i = end - 1; i >= start; --i) {
				if (array[i] > array[i + 1]) {
					swap(array[i], array[i + 1]);
					swapped = 1;
				}
			}
			++start;
		}
	}
	void shakerSort(list<int>& lst) {
		bool swapped = true;
		auto start = lst.begin();
		auto end = lst.end();
		while (swapped) {
			swapped = false;
			for (auto it = start; next(it) != end; ++it) {
				if (*it > *next(it)) {
					swap(*it, *next(it));
					swapped = true;
				}
			}
			if (!swapped) break;
			--end;
			swapped = false;
			for (auto it = prev(end); it != start; --it) {
				if (*it > *next(it)) {
					swap(*it, *next(it));
					swapped = true;
				}
			}
			++start;
		}
	}
	void bubbleSort(int array[], int n) {
		for (int i = 0; i < n - 1; i++) {
			bool swapped = false;
			for (int j = 0; j < n - 1 - i; j++) {
				if (array[j] > array[j + 1]) {
					swapped = true;
					swap(array[j], array[j + 1]);
				}
			}
			if (!swapped)
				break;
		}
	}
	void bubbleSort(list<int>& lst) {
		for (auto iter1 = lst.begin(); iter1 != prev(lst.end()); ++iter1) {
			bool swapped = false;
			for (auto iter2 = lst.begin(); iter2 != prev(lst.end()); ++iter2) {
				auto nextIter = next(iter2);
				if (*iter2 > *nextIter) {
					swap(*iter2, *nextIter);
					swapped = true;
				}
			}
			if (!swapped)
				break;
		}
	}

	void merge(int array1[], int array2[], int targetArray[], int array1Length, int array2Length) {
		int array1MinIndex = 0;
		int array2MinIndex = 0;
		int targetArrayMinIndex = 0;

		while (array1MinIndex < array1Length && array2MinIndex < array2Length) {
			if (array1[array1MinIndex] <= array2[array2MinIndex]) {
				targetArray[targetArrayMinIndex] = array1[array1MinIndex];
				array1MinIndex++;
			}
			else {
				targetArray[targetArrayMinIndex] = array2[array2MinIndex];
				array2MinIndex++;
			}
			targetArrayMinIndex++;
		}

		while (array1MinIndex < array1Length) {
			targetArray[targetArrayMinIndex] = array1[array1MinIndex];
			array1MinIndex++;
			targetArrayMinIndex++;
		}

		while (array2MinIndex < array2Length) {
			targetArray[targetArrayMinIndex] = array2[array2MinIndex];
			array2MinIndex++;
			targetArrayMinIndex++;
		}
	}

	void mergeSort(int array[], int size) {
		if (size < 2) {
			return;
		}
		int mid = size / 2;
		int* left = new int[mid];
		int* right = new int[size - mid];

		for (int i = 0; i < mid; i++) {
			left[i] = array[i];
		}
		for (int i = mid; i < size; i++) {
			right[i-mid] = array[i];
		}
		mergeSort(left, mid);
		mergeSort(right, size - mid);
		merge(left, right, array, mid, size - mid);

	}
	void merge(list<int>& lst1, std::list<int>& lst2, std::list<int>& targetLst) {
		auto iter1 = lst1.begin();
		auto iter2 = lst2.begin();

		while (iter1 != lst1.end() && iter2 != lst2.end()) {
			if (*iter1 <= *iter2) {
				targetLst.push_back(*iter1);
				iter1++;
			}
			else {
				targetLst.push_back(*iter2);
				iter2++;
			}
		}
		while (iter1 != lst1.end()) {
			targetLst.push_back(*iter1);
			iter1++;
		}
		while (iter2 != lst2.end()) {
			targetLst.push_back(*iter2);
			iter2++;
		}
		
	}

	void mergeSort(list<int>& lst) {
		if (lst.size() < 2) {
			return;
		}

		int mid = lst.size() / 2;
		list<int> left, right;

		auto iter = lst.begin();
		for (int i = 0; i < mid; i++) {
			left.push_back(*iter);
			iter++;
		}
		while (iter != lst.end()) {
			right.push_back(*iter);
			iter++;
		}
		mergeSort(left);
		mergeSort(right);
		lst.clear();
		merge(left, right, lst);
		
	}

}
