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
    
    //CourseList constructor
    CourseList();

    //Create a deep copy of a CourseList
    CourseList(const CourseList& cl);

    //Get deep copy of a Semester pHead Node
    Node* deepCopySemester(Node* pHead);
    
    //add a course into CL
    void addCourse(Course c);

    friend ostream& operator<<(ostream& os, CourseList& cList);

    //Initialize Course objects from CSV
    void initDataFromCSV(const string& file);

    //Find Cousre Node with id
    Node* findNode(string targetId);

    //Find Cousre Node with id and semester
    Node* findNode(string targetId, int sem);

    //Delete Cousre with id
    bool deleteCourse(string targetId);

    //Delete Cousre with id and semester
    bool deleteCourse(string targetId, int sem);

    //Update Cousre data
    bool updateCourse(Node*& node, string targetName, int tolCre, int lecCre, int labCre, int p, int sem);

    //Get number of courses in a CourseList
    int getCount();

    //Change semester a course is taken and update its position in CourseList
    void changeSemester(Node* node, int sem);
};
typedef CourseList CL;

#endif