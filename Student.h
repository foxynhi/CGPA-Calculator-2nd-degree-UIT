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
    friend istream& operator>>(istream& is, Student& s);
    friend ostream& operator<<(ostream& os, Student& s);

    //add a course taken by a student from model CourseList
    bool addCourse(CL cl, string targetId, int sem);

    bool setPoint(string targetId, int sem, float p);
    
    //Calcualate GPA of a semester
    float calcSemesterGPA(int sem);

    //Calcualate CGPA of a Student devided by semester
    float calcCGPAbySemester();

    //Calcualate CGPA of a Student devided by course
    float calcCGPAbyCourse();
};

#endif