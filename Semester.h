#include "Node.h"

#ifndef SEMESTER_H
#define SEMESTER_H
#pragma once

//Linked list of courses in a semester

struct Semester
{
    Node* pHead;

    Semester();
    ~Semester();

    //Calculate GPA of a semester
    float calcSemesterGPA();
};

#endif