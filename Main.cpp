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
#include "InputHandler.h"
#include "OutputHandler.h"

#include <iostream>
#include <iomanip>

using namespace std;

const string STUDENT_DATA = "student_data.txt";

void displayMenu();
void processChoice(StudentList&, double);

int main()
{
    StudentList newList;
    double num = 0.0;

    readStudentData(STUDENT_DATA, newList, num);

    displayMenu();
    processChoice(newList, num);

    cout << endl;
    system("Pause");
    return 0;
}

void displayMenu()
{
    cout << "\n*** MAIN MENU ***\n" << endl
        << "Select one of the following:\n" << endl
        << "    1: Print all students\n"
        << "    2: Print student information\n"
        << "    3: Search student by last name\n"
        << "    4: Print students by course\n"
        << "    5: Print students on hold\n"
        << "    6: Print students to file\n"
        << "    7: Change student's grade\n"
        << "    8: To exit\n" << endl
        << "Enter your choice: ";
}

void processChoice(StudentList& stuList, double tuition)
{
    int in = 8;
    bool proceed = true;

    while (proceed)
    {
        cin >> in;
        cout << endl;

        switch (in)
        {
            case 1:
            {
                stuList.printAllStudents(tuition);

                system("Pause");
                displayMenu();
                break;
            }
            case 2:
            {
                int id = 0;
                cout << "Please enter student's ID: ";
                cin >> id;
                cout << endl;

                stuList.printStudentByID(id, tuition);

                system("Pause");
                displayMenu();
                break;
            }
            case 3:
            {
                string lastName;
                cout << "Please enter student's last name: ";
                cin >> lastName;
                cout << endl;

                stuList.printStudentByName(lastName);
                
                cout << endl;
                system("Pause");
                cout << endl;
                displayMenu();
                break;
            }
            case 4:
            {
                string prefix;
                int num = 0;
                cout << "Please enter course prefix: ";
                cin >> prefix; 
                cout << "Please enter course number: ";
                cin >> num;
                cout << endl;

                stuList.printStudentsByCourse(prefix, num);

                cout << endl;
                system("Pause");
                displayMenu();
                break;
            }
            case 5:
            {
                stuList.printStudentsOnHold(tuition);

                cout << endl;
                system("Pause");
                displayMenu();
                break;
            }
            case 6:
            {
                printAllStudentsToFile(stuList, tuition);

                cout << endl;
                system("Pause");
                displayMenu();
                break;
            }
            case 7:
            {
                stuList.changeGrade();

                cout << endl;
                system("Pause");
                displayMenu();
                break;
            }
            case 8:
            {
                proceed = false;
                cout << "Thank you for using the OCC Gradebook. Good-Bye!\n";
                break;
            }
            default:
            {
                cout << "Sorry. That is not a selection.\n";

                cout << endl;
                system("Pause");
                displayMenu();
                break;
            }
        }
    }
}