#include "Semester.h"
#include "Course.h"
#include "config.h"
#ifndef COURSELIST_H
#define COURSELIST_H


#pragma once

//List of courses a student takes overall

struct CourseList
{
    Semester semester[N];
    
    CourseList();
    void addCourse(Course c);
    friend ostream& operator<<(ostream& os, CourseList& cList);
};
typedef CourseList CL;

#endif