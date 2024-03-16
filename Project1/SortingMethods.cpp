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
			for (auto it = start; std::next(it) != end; ++it) {
				if (*it > *std::next(it)) {
					swap(*it, *std::next(it));
					swapped = true;
				}
			}
			if (!swapped) break;
			--end;
			swapped = false;
			for (auto it = std::prev(end); it != start; --it) {
				if (*it > *std::next(it)) {
					swap(*it, *std::next(it));
					swapped = true;
				}
			}
			++start;
		}
	}

	void merge(int array[], int start, int middle, int end) {		
		int left = start;
		int right = middle + 1;
		int length = end - start + 1;
		int* tempArray = new int[length];
		for (int i = 0; i < length; i++) {
			if (right > end || (left <= middle && array[left] < array[right])) {
				tempArray[i] = array[left];
				left++;
			}
			else {
				tempArray[i] = array[right];
				right++;
			}
		}
		for (int i = 0; i < length; i++)
			array[i + start] = tempArray[i];
	}
	void merge(list<int>& lst, std::list<int>& left, std::list<int>& right) {
		auto leftIt = left.begin();
		auto rightIt = right.begin();
		while (leftIt != left.end() && rightIt != right.end()) {
			if (*leftIt < *rightIt) {
				lst.push_back(*leftIt);
				++leftIt;
			}
			else {
				lst.push_back(*rightIt);
				++rightIt;
			}
		}
		lst.insert(lst.end(), leftIt, left.end());
		lst.insert(lst.end(), rightIt, right.end());
	}

	void mergeSort(list<int>& lst) {
		if (lst.size() <= 1) return;
		std::list<int> left, right;
		int middle = lst.size() / 2;
		auto it = lst.begin();
		std::advance(it, middle);
		left.splice(left.begin(), lst, lst.begin(), it);
		right.splice(right.begin(), lst, it, lst.end());
		mergeSort(left);
		mergeSort(right);
		merge(lst, left, right);
	}

	void mergeSort(int array[], int start, int end) {
		if (start == end) return;
		int middle = (start + end) / 2;
		mergeSort(array, start, middle);
		mergeSort(array, middle + 1, end);
		merge(array, start, middle, end);

	}
}
