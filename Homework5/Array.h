#pragma once

class Array {
public:
	Array();
	Array(int);
	~Array();
	void bubbleSort();
	void insertionSort();
	void mergeSort(int, int);
	void merge(int, int, int);
	void quickSort(int, int);
	void heapSort(int);
	void buildHeap(int);
	void heapify(int, int);
	void countingSort();
	void radixSort();
	int getSize();
private:
	int size = 10;
	int *arr;
};