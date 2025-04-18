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

    //Find Cousre Node with id and semester
    Node* findNode(string targetId, int sem);

    //Delete Cousre with id and semester
    bool deleteCourse(string targetId, int sem);

    //Update Cousre data
    void updateCourse(string targetId, string targetName, int tolCre, int lecCre, int labCre, int p, int sem);
};
typedef CourseList CL;

#endif