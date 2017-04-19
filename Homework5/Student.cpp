#include "stdafx.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

Student::Student()
{
}

Student::Student(string n1, string n2, string mnum, long dob)
{
	firstName = n1;
	lastName = n2;
	mNumber = mnum;
	birthday = dob;
}

Student::Student(string n1, string n2, string mnum, long dob, double grade)
{
	firstName = n1;
	lastName = n2;
	mNumber = mnum;
	birthday = dob;
	GPA = grade;
}

string Student::getName()
{
	return (firstName + " " + lastName);
}

string Student::getMNumber()
{
	return mNumber;
}

// only valid to current year and birth year, not month and day
int Student::getAge()
{
	int birthYear = birthday % 10000; // returns last 4 digits of birthday which is year
	return CUR_YEAR - birthYear;
}

// for comparison operations, compare mNumber strings

bool Student::operator>(const Student &comp)
{
	if (this->mNumber.compare(comp.mNumber) > 0)
		return true;
	return false;
}

bool Student::operator<(const Student &comp)
{
	if (this->mNumber.compare(comp.mNumber) < 0)
		return true;
	return false;
}

bool Student::operator==(const Student &comp)
{
	if (this->mNumber.compare(comp.mNumber) == 0)
		return true;
	return false;
}


void Student::display()
{
	// only important ones are name and m-number
	cout << getName() << "\t" << getMNumber() << endl;
}
