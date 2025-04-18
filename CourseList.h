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
    CourseList(const CourseList& cl);
    Node* deepCopySemester(Node* pHead);
    
    void addCourse(Course c);
    friend ostream& operator<<(ostream& os, CourseList& cList);

    //Initialize Course objects from CSV
    void initDataFromCSV(const string& file);

    //Find Cousre Node with id and semester
    Node* findNode(string targetId, int sem);

    //Delete Cousre with id and semester
    bool deleteCourse(string targetId, int sem);

    //Update Cousre data
    bool updateCourse(string targetId, string targetName, int tolCre, int lecCre, int labCre, int p, int sem);

    //Calculate CGPA of the whole CourseList
    float calculateCGPA();

    int getCount();
};
typedef CourseList CL;

#endif