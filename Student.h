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
    Student(int i, string n, int nn, const CL& cl)
        : id(i), name(n), n(nn), cList(cl) {}
    friend ostream& operator<<(ostream& os, Student& s);

    bool addTakenCourse(string targetId, int sem, float p);

    bool setPoint(string targetId, int sem, float p);
    float calcCGPAbySemester();
    float calcCGPAbyCourse();
};

#endif