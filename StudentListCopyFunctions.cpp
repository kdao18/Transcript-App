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

StudentList::StudentList(const StudentList& paramStudentList)
{
	if (paramStudentList.count != 0)
	{
		first = new Node(paramStudentList.first->getStudent(), nullptr);

		Node* current = paramStudentList.first->getNext();
		Node* temp = first;
		while (current != nullptr)
		{
			temp->setNext(new Node(current->getStudent(), nullptr));
			current = current->getNext();
			temp = temp->getNext();
		}

		last = temp;
		count = paramStudentList.count;
	}
	else
	{
		first = nullptr;
		last = nullptr;
		count = 0;
	}
}

StudentList& StudentList::operator=(const StudentList& rightSide)
{
	if (&rightSide == this)
	{
		cerr << "Attempted assignment to itself.";
		return *this;
	}
	else
	{
		if (rightSide.count == 0)
		{
			clearStudentList();
		}
		else if (count == 0)
		{
			copyCallingObjIsEmpty(rightSide);
		}
		else if (count == rightSide.count)
		{
			copyObjectsSameLength(rightSide);
		}
		else if (count > rightSide.count)
		{
			copyCallingObjLonger(rightSide);
		}
		else
		{
			copyCallingObjShorter(rightSide);
		}
		return *this;
	}
}

void StudentList::copyCallingObjIsEmpty(const StudentList& rightSide)
{
	first = new Node(rightSide.first->getStudent(), nullptr);

	Node* current = rightSide.first->getNext();
	Node* temp = first;
	while (current != nullptr)
	{
		temp->setNext(new Node(current->getStudent(), nullptr));
		current = current->getNext();
		temp = temp->getNext();
	}

	last = temp;
	count = rightSide.count;
}

void StudentList::copyObjectsSameLength(const StudentList& rightSide)
{
	Node* current = rightSide.first;
	Node* temp = first;
	while (temp != nullptr)
	{
		temp->setStudent(current->getStudent());
		current = current->getNext();
		temp = temp->getNext();
	}
}

void StudentList::copyCallingObjLonger(const StudentList& rightSide)
{
	first->setStudent(rightSide.first->getStudent());

	Node* current = rightSide.first->getNext();
	Node* temp = first;
	while (current != nullptr)
	{
		temp->getNext()->setStudent(current->getStudent());
		current = current->getNext();
		temp = temp->getNext();
	}

	Node* trailingCurrent = temp;
	temp = temp->getNext();
	while (temp != nullptr)
	{
		trailingCurrent->setNext(temp->getNext());
		delete temp;
		temp = trailingCurrent->getNext();
	}

	last = trailingCurrent;
	count = rightSide.count;
}

void StudentList::copyCallingObjShorter(const StudentList& rightSide)
{
	Node* temp = first;
	Node* current = rightSide.first;
	while (temp != nullptr)
	{
		temp->setStudent(current->getStudent());
		temp = temp->getNext();
		current = current->getNext();
	}

	temp = last;
	while (current != nullptr)
	{
		temp->setNext(new Node(current->getStudent(), nullptr));
		current = current->getNext();
		temp = temp->getNext();
	}

	last = temp;
	count = rightSide.count;
}
