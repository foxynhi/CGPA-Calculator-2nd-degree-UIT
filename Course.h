#include "iostream"
#include "string"
using namespace std;

#ifndef COURSE_H
#define COURSE_H

#pragma once

struct Course
{
    string id;
    string name;
    int tolCredit;  //Total Credit hours
    int lecCredit;  //Lecture Credit hours
    int labCredit;  //Lab Credit hours
    float point;
    int semester;
    
    Course()
        : id(""), name(""), tolCredit(0), lecCredit(0), labCredit(0), point(0), semester(0) {}
    Course(string i, string n, int t, int lec, int lab, float p, int s)
        : id(i), name(n), tolCredit(t), lecCredit(lec), labCredit(lab), point(p), semester(s) {}
    Course(const Course& x)
        : id(x.id), name(x.name), tolCredit(x.tolCredit), lecCredit(x.lecCredit), labCredit(x.labCredit), point(x.point), semester(x.semester) {}
    ~Course(){};
    friend istream& operator>>(istream& is, Course& c);
    friend ostream& operator<<(ostream& os, Course& c);
    Course operator=(const Course& c);
    string toCSV() const;
    
};

#endif