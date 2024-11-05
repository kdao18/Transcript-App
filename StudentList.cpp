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

#include <iomanip>

using namespace std;

void StudentList::addStudent(const Student& newStudent)
{
    Node* temp = new Node(newStudent, nullptr);
    if (first == nullptr)
    {
        first = temp;
        last = temp;
    }
    else
    {
        last->setNext(temp);
        last = last->getNext();
    }
    count++;
}

int StudentList::getNoOfStudents() const
{
    return count;
}

void StudentList::printStudentByID(int studentID, 
    double tuitionRate) const
{
    bool found = false;
    
    Node* current = first;
    while (current != nullptr)
    {
        if (current->getStudent().getID() == studentID)
        {
            found = true;
            current->getStudent().printStudentInfo(tuitionRate);
        }
        current = current->getNext();
    }

    if (!found)
    {
        cout << "No students with ID " 
            << studentID << " found in the list.\n\n";
    }
}

void StudentList::printStudentByName(const string& lastName) const
{
    bool found = false;

    Node* current = first;
    while (current != nullptr)
    {
        if (current->getStudent().getLastName() == lastName)
        {
            found = true;
            current->getStudent().printStudent();
        }
        current = current->getNext();
    }

    if (!found)
    {
        cout << "No student with last name " 
            << lastName << " is on the list." << endl;
    }
}

void StudentList::printStudentsByCourse(const string& coursePrefix, 
    int courseNumber) const
{
    bool found = false;
    
    Node* current = first;
    while (current != nullptr)
    {
        if (current->getStudent().isCourseCompleted(coursePrefix, courseNumber))
        {
            found = true;
            current->getStudent().printStudent();
        }
        current = current->getNext();
    }

    if (!found)
    {
        cout << "No students enrolled in " 
            << coursePrefix << " " << courseNumber << "." << endl;
    }
}

void StudentList::printAllStudents(double tuitionRate) const
{
    Node* current = first;
    while (current != nullptr)
    {
        current->getStudent().printStudentInfo(tuitionRate);
        current = current->getNext();
    }
}

void StudentList::printStudentsToFile(ofstream& out, double tuition) const
{
    Node* current = first;
    while (current != nullptr)
    {
        Student currentStudent = current->getStudent();
        out << "Student Name: " 
            << currentStudent.getLastName() << ", " 
            << currentStudent.getFirstName() << endl
            << "Student ID: " << currentStudent.getID() << endl
            << "Number of courses completed: " 
            << currentStudent.getNumberOfCourses() << "\n\n"
            << "CourseNo  Units  Grade\n";
        if (currentStudent.isTuitionPaid())
        {
            multimap<Course, char> courses = 
                currentStudent.getCoursesCompleted();
            auto courseItr = courses.begin();
            auto courseEnd = courses.end();
            for (courseItr; courseItr != courseEnd; ++courseItr)
            {
                out << courseItr->first.getCoursePrefix()
                    << " " << courseItr->first.getCourseNumber() << "    "
                    << courseItr->first.getCourseUnits() << "      "
                    << courseItr->second << endl;
            }
            out << "Total number of credit hours: "
                << currentStudent.getUnitsCompleted() << endl
                << "Current Term GPA: " << fixed << setprecision(2) 
                << currentStudent.calculateGPA() << "\n\n";
        }
        else
        {
            multimap<Course, char> courses =
                currentStudent.getCoursesCompleted();
            auto courseItr = courses.begin();
            auto courseEnd = courses.end();
            for (courseItr; courseItr != courseEnd; ++courseItr)
            {
                out << courseItr->first.getCoursePrefix()
                    << " " << courseItr->first.getCourseNumber() << "    "
                    << courseItr->first.getCourseUnits() << "     "
                    << "***" << endl;
            }
            out << "Total number of credit hours: "
                << currentStudent.getUnitsCompleted() << endl 
                << "*** Grades are being held for not the paying tuition. ***" 
                << endl << "Amount Due: $" << fixed << setprecision(2)
                << currentStudent.billingAmount(tuition) << "\n\n";
        }
        
        for (size_t i = 0; i < 24; ++i)
        {
            out << "-*";
        }
        out << "-\n\n";

        current = current->getNext();
    }
}

void StudentList::printStudentsOnHold(double tuition) const
{
    bool found = false;
    
    Node* current = first;
    while (current != nullptr)
    {
        Student student = current->getStudent();

        if (!student.isTuitionPaid())
        {
            found = true;
            student.printStudent();
            cout << "    Amount Due: $" 
                << fixed << setprecision(2) 
                << student.billingAmount(tuition) << endl;
        }
        current = current->getNext();
    }

    if (!found)
    {
        cout << "There are no students on hold." << endl;
    }
}

void StudentList::clearStudentList()
{
    Node* temp = first;
    while (first != nullptr)
    {
        first = first->getNext();
        delete temp;
        temp = first;
    }
    last = first;
    count = 0;
}

StudentList::~StudentList()
{
    if (first != nullptr)
    {
        clearStudentList();
    }
}