#include "Array.h"
#include "stdlib.h"

Array::Array()
{
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (2*size);
	}
}

Array::Array(int width) {
	size = width;
	arr = new int[size];
	for (int j = 0; j < size; j++) {
		arr[j] = rand() % (2 * size);
	}
}

Array::~Array()
{
	delete(arr);
}

void Array::bubbleSort() {
	// for each element, i elements in the back of the data are sorted
	for (int i = 0; i < size; i++) {
		// look at each ensuing element
		for (int j = 0; j < size - i - 1; j++) {
			// if items need to be swapped, swap them
			if (arr[j] < arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void Array::insertionSort() {
	// for each item
	for (int i = 1; i < size; i++) {
		// place each element based on the preceding elements into the appropriate place
		int j = i - 1;
		int temp = arr[i];
		// swap items if needed
		while (j >= 0 && temp < arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

/* leftIn is for left index and rightIn is right index of the
sub-array of arr to be sorted */
void Array::mergeSort(int leftIn, int rightIn)
{ 
	if (leftIn < rightIn)
	{
		int mid = leftIn + rightIn / 2;

		//sorts front half, back half of array
		mergeSort(leftIn, mid);
		mergeSort(mid + 1, rightIn);
		merge(leftIn, mid, rightIn);
	}
}
void Array::merge(int leftIn, int mid, int rightIn)
{
	int i, j, k;
	int n1 = mid - leftIn + 1;
	int n2 = rightIn - mid;

	// Temporary arrays
	int *Left = new int[n1];
	int *Right = new int[n2];

	// Copies data to temporary arrays
	for (i = 0; i < n1; i++)
		Left[i] = arr[leftIn + i];
	for (j = 0; j < n2; j++)
		Right[j] = arr[mid + 1 + j];

	// Begins merging process
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = leftIn; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (Left[i] <= Right[j])
		{
			arr[k] = Left[i];
			i++;
		}
		else
		{
			arr[k] = Right[j];
			j++;
		}
		k++;
	}
	// Copies remaining elements in Left[]
	while (i < n1)
	{
		arr[k] = Left[i];
		i++;
		k++;
	}

	// Copies remaining elements in Right[]
	while (j < n2)
	{
		arr[k] = Right[j];
		j++;
		k++;
	}
}

void Array::quickSort(int leftIn, int rightIn)
{
	int i, j, temp;
	i = leftIn;
	j = rightIn;
	int pivot = arr[(leftIn + rightIn) / 2]; //sets pivot as middle
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	if (leftIn < j)
		quickSort(leftIn, j);
	if (i < rightIn)
		quickSort(i, rightIn);
}
void Array::heapify(int i, int n)
{
	int leftIn, rightIn, largest, loc;
	leftIn = 2 * i;
	rightIn = (2 * i + 1);
	if ((leftIn <= n) && arr[leftIn]>arr[i])
		largest = leftIn;
	else
		largest = i;
	if ((rightIn <= n) && (arr[rightIn]>arr[largest]))
		largest = rightIn;
	if (largest != i)
	{
		loc = arr[i];
		arr[i] = arr[largest];
		arr[largest] = loc;
		heapify(largest, n);
	}
}
int Array::getSize()
{
	return size;
}
void Array::buildHeap(int n)
{
	for (int k = n / 2; k >= 1; k--)
	{
		heapify(k, n);
	}
}
void Array::heapSort(int n)
{

	buildHeap(n);
	int i, temp;
	for (i = n; i >= 2; i--)
	{
		temp = arr[i];
		arr[i] = arr[1];
		arr[1] = temp;
		heapify(1, i - 1);
	}
}