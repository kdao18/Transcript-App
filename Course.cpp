/*
    Pham, Kidd (Team Leader)
    Nguyen, Cindy
    Dao, Kenneth
    Rodriguez, Cele

    Project: Grade Report
    CS A250
    Fall 2023
*/

#include "Course.h"

using namespace std;

void Course::setCourseInfo(const string& paramPrefix, 
    int paramNumber, int paramUnits)
{
    coursePrefix = paramPrefix;
    courseNumber = paramNumber;
    courseUnits = paramUnits;
}

string Course::getCoursePrefix() const
{
    return coursePrefix;
}

int Course::getCourseNumber() const
{
    return courseNumber;
}

int Course::getCourseUnits() const
{
    return courseUnits;
}

bool Course::operator<(const Course& paramCourse) const
{
    if (coursePrefix != paramCourse.coursePrefix)
    {
        return coursePrefix < paramCourse.coursePrefix;
    }
    else if (courseNumber != paramCourse.courseNumber)
    {
        return courseNumber < paramCourse.courseNumber;
    }
    else
    {
        return courseUnits < paramCourse.courseUnits;
    }
}