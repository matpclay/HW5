#pragma once

#include <string>
using namespace std;
static const int CUR_YEAR = 2017;
class Student {
private:
	string firstName, lastName, mNumber;
	double GPA;
	long birthday; //formatted as mmddyyyy
public:
	Student();
	Student(string, string, string, long);
	Student(string, string, string, long, double);
	// getters
	string getName(); // gets full name
	string getMNumber(); // gets mNumber
	int getAge(); // returns age in years
				  // comparators of mNumbers
	bool operator >(const Student &);
	bool operator <(const Student &);
	bool operator ==(const Student &);
	void display(); // Task 4
};