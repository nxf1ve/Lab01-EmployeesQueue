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
	

}
