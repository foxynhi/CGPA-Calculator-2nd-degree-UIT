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

    //Initialize Course objects from CSV
    void initDataFromCSV(const string& file);
    bool deleteCourse(string targetId, int sem);
    void updateCourse(string targetId, string targetName, int tolCre, int lecCre, int labCre, int p, int sem);
};
typedef CourseList CL;

#endif