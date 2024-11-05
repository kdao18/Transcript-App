/*
    Pham, Kidd (Team Leader)
    Nguyen, Cindy
    Dao, Kenneth
    Rodriguez, Cele

    Project: Grade Report
    CS A250
    Fall 2023
*/

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

#include <iostream>
#include <ostream>
#include <fstream>

class Node
{
public:
    Node() : student(), next(nullptr) {}
    Node(Student nStudent, Node* newNext) : student(nStudent), next(newNext) {}

    Node* getNext() const { return next; }
    Student getStudent() const { return student; }

    void setStudent(Student newStudent) { student = newStudent; }
    void setNext(Node* newNext) { next = newNext; }

    ~Node() {}

private:
    Student student;
    Node* next;
};

class StudentList
{
public:
    StudentList() : first(nullptr), last(nullptr), count(0) {}
    StudentList(const StudentList&);
    
    StudentList& operator=(const StudentList&);

    void addStudent(const Student&);

    int getNoOfStudents() const;

    void changeGrade();

    void printStudentByID(int, double) const;
    void printStudentByName(const std::string&) const;
    void printStudentsByCourse(const std::string&, int) const;
    void printAllStudents(double) const;
    void printStudentsToFile(std::ofstream&, double) const;
    void printStudentsOnHold(double) const;

    void clearStudentList();
    ~StudentList();

private:
    Node* first;
    Node* last;
    int count;

    void copyCallingObjIsEmpty(const StudentList&);
    void copyObjectsSameLength(const StudentList&);
    void copyCallingObjLonger(const StudentList&);
    void copyCallingObjShorter(const StudentList&);
};

#endif


