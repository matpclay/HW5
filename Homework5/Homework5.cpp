// Homework5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <chrono>
#include "Array.h"
#include "Student.h"
typedef std::chrono::high_resolution_clock Clock;


int main()
{
	Array *ar = new Array(10);
	// need to make copies, I think this works
	Array ar2 = *ar;
	Array ar3 = *ar;
	Array ar4 = *ar;
	Array ar5 = *ar;
	auto t1 = Clock::now();
	// stuff happens here
	(*ar).bubbleSort();
	auto t2 = Clock::now();
	std::cout << "Bubble Sort: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
	auto t1 = Clock::now();
	// stuff happens here
	ar2.insertionSort();
	auto t2 = Clock::now();
	std::cout << "Insertion Sort: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
	auto t1 = Clock::now();
	// stuff happens here
	ar3.mergeSort(0, ar3.getSize()-1);
	auto t2 = Clock::now();
	std::cout << "Merge Sort: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
	auto t1 = Clock::now();
	// stuff happens here
	ar4.quickSort(0, ar4.getSize()-1);
	auto t2 = Clock::now();
	std::cout << "Quick Sort: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
	auto t1 = Clock::now();
	// stuff happens here
	ar5.heapSort(0);
	auto t2 = Clock::now();
	std::cout << "Heap Sort: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
    return 0;
}

