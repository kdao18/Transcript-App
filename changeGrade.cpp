/*
	Pham, Kidd (Team Leader)
	Nguyen, Cindy
	Dao, Kenneth
	Rodriguez, Cele

	Project: Grade Report
	CS A250
	Fall 2023
*/

#include "StudentList.h"

#include <iostream>

using namespace std;

void StudentList::changeGrade()
{
	int id = 0;
	cout << "Please enter the student's ID: ";
	cin >> id;
	
	Student studentChangingGrade;
	bool found = false;

	Node* temp = first;
	while (!found && temp != nullptr)
	{
		Student tempStudent = temp->getStudent();

		if (tempStudent.getID() == id)
		{
			studentChangingGrade = tempStudent;
			found = true;
		}
		else
		{
			temp = temp->getNext();
		}
	}

	if (! found) 
	{
		cerr << "No student found with id: " << id << "\n";
	}
	else
	{
		string firstName, lastName;
		cout << "Please enter the student's first name: ";
		cin >> firstName;
		cout << "Please enter the student's last name: ";
		cin >> lastName;
	
		if (studentChangingGrade.getFirstName() != firstName
			|| studentChangingGrade.getLastName() != lastName)
		{
			cerr << "No student with that name found\n";			
		}
		else
		{
			string prefix;
			int num = 0;
			cout << "Please enter the course's prefix: ";
			cin >> prefix;
			cout << "Please enter the course's number: ";
			cin >> num;

			char newGrade = 'F';
			bool proceed = true;
			do
			{
				cout << "Please enter the student's new grade: ";
				proceed = false;
				cin >> newGrade;
				if (newGrade != 'A' && newGrade != 'B' && newGrade != 'C' 
					&& newGrade != 'D'&& newGrade != 'F')
				{
					proceed = true;
					cout << "Use a valid grade\n";
				}
			} while (proceed);

			if (studentChangingGrade.updatedCourse(newGrade, prefix, num))
			{
				temp->setStudent(studentChangingGrade);
				cout << "\nGrade found and replaced...\n";
			}
			else
			{
				cout << "Course not found\n";
			}
		}
	}
}