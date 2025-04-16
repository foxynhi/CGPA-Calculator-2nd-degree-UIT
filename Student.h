#include "string"
#include "CourseList.h"
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

#pragma once


struct Student
{
    int id;
    string name;
    int n;      //Number of courses taken
    CourseList cList;
    
    Student()
        :id(0), name(""), n(0), cList() {};
    Student(int i, string n, int nn, CL cl)
        : id(i), name(n), n(nn), cList(cl) {}
    ~Student(){};
};

#endif