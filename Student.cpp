/*
	Pham, Kidd (Team Leader)
	Nguyen, Cindy
	Dao, Kenneth
	Rodriguez, Cele

	Project: Grade Report
	CS A250
	Fall 2023
*/

#include "Student.h"

#include <iostream>
#include <iomanip>

using namespace std;

void Student::setStudent(const Student& paramStudent)
{
	studentID = paramStudent.studentID;
	firstName = paramStudent.firstName;
	lastName = paramStudent.lastName;
	numberOfCourses = paramStudent.numberOfCourses;
	tuitionWasPaid = paramStudent.tuitionWasPaid;
	coursesCompleted = paramStudent.coursesCompleted;
}

void Student::setStudentInfo(int newIDNum, const string& newFirstName,
	const string& newLastName, bool newTuitionBoolean, 
	const multimap<Course, char>& newCoursesCompleted)
{
	studentID = newIDNum;
	firstName = newFirstName;
	lastName = newLastName;
	numberOfCourses = static_cast<int> (newCoursesCompleted.size());
	tuitionWasPaid = newTuitionBoolean;
	coursesCompleted = newCoursesCompleted;
}

bool Student::updatedCourse(char newGrade, const string& prefix, int num)
{
	for (auto& courseMapElem : coursesCompleted)
	{
		if (courseMapElem.first.getCoursePrefix() == prefix
			&& courseMapElem.first.getCourseNumber() == num)
		{
			courseMapElem.second = newGrade;
			return true;
		}
	}
	return false;
}

void Student::getName(string& fName, string& lName) const
{
	fName = firstName;
	lName = lastName;
}

int Student::getID() const
{
	return studentID;
}

string Student::getFirstName() const
{
	return firstName;
}

string Student::getLastName() const
{
	return lastName;
}

int Student::getNumberOfCourses() const
{
	return numberOfCourses;
}

int Student::getUnitsCompleted() const
{
	int totalUnits = 0;
	auto courseItr = coursesCompleted.begin();
	auto coursesEnd = coursesCompleted.end();
	for (courseItr; courseItr != coursesEnd; ++courseItr)
	{
		totalUnits += courseItr->first.getCourseUnits();
	}
	return totalUnits;
}

multimap<Course, char> Student::getCoursesCompleted() const
{
	return coursesCompleted;
}

bool Student::isTuitionPaid() const
{
	return tuitionWasPaid;
}

bool Student::isCourseCompleted(const string& coursePrefix, 
	int courseNumber) const
{
	if (numberOfCourses == 0)
	{
		return false;
	}
	else
	{
		auto itr = coursesCompleted.begin();
		auto end = coursesCompleted.end();
		for (itr; itr != end; ++itr)
		{
			if (itr->first.getCoursePrefix() == coursePrefix &&
				itr->first.getCourseNumber() == courseNumber)
			{
				return true;
			}
		}
		return false;
	}
}

double Student::calculateGPA() const
{
	double totalUnits = 0;
	double qualityPoints = 0;

	auto courseItr = coursesCompleted.begin();
	auto coursesEnd = coursesCompleted.end();
	for (courseItr; courseItr != coursesEnd; ++courseItr)
	{
		totalUnits += courseItr->first.getCourseUnits();
		if (courseItr->second == 'A')
		{
			qualityPoints += 4 * courseItr->first.getCourseUnits();
		}
		else if (courseItr->second == 'B')
		{
			qualityPoints += 3 * courseItr->first.getCourseUnits();
		}
		else if (courseItr->second == 'C')
		{
			qualityPoints += 2 * courseItr->first.getCourseUnits();
		}
		else if (courseItr->second == 'D')
		{
			qualityPoints += 1 * courseItr->first.getCourseUnits();
		}
		else
		{
			qualityPoints += 0;
		}
	}

	return qualityPoints / totalUnits;
}

double Student::billingAmount(double tuitionRate) const
{
	return tuitionRate * numberOfCourses;
}

void Student::printStudent() const
{
	cout << studentID << " - " << lastName << ", " << firstName << endl;
}

void Student::printStudentInfo(double tuitionRate) const
{
	cout << "Student Name: "
		<< lastName << ", " << firstName << endl
		<< "Student ID: " << studentID << endl
		<< "Number of courses completed: " 
		<< numberOfCourses << "\n\n"
		<< "CourseNo  Units  Grade\n";
	auto course = coursesCompleted.begin();
	auto coursesEnd = coursesCompleted.end();
	for (course; course != coursesEnd; ++course)
	{
		cout << course->first.getCoursePrefix() << " "
			<< course->first.getCourseNumber() << "    "
			<< course->first.getCourseUnits() << "      "
			<< course->second << endl;
	}
	cout << endl << "Total number of credit hours: "
		<< getUnitsCompleted() << endl;
	
	if (!isTuitionPaid())
	{
		cout << "*** Grades are being held for not paying the tuition. ***" << endl
			<< "Amount Due: $" << billingAmount(tuitionRate) << endl << endl;
		
	}
	else
	{
		cout << "Current Term GPA: "
			<< fixed << setprecision(2) << calculateGPA() << endl << "\n";
	}
		
	for (size_t i = 0; i < 24; ++i)
	{
		cout << "-*";
	}
	cout << "-\n" << endl;
}