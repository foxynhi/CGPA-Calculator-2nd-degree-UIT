#include "Semester.h"
#include "cmath"

Semester::Semester()
{
    pHead = nullptr;
}

Semester::~Semester()
{
    Node* curr = pHead;
    while (curr){
        Node* next = curr->pNext;
        delete curr;
        curr = next;
    }
    pHead = nullptr;
}

float Semester::calcSemesterGPA()
{
    int count = 0;
    float sum = 0;
    
    for (Node* p = pHead; p != nullptr; p = p->pNext){
        sum += p->c.point;
        count++;
    }
    return round(sum / count * 100) /100.;
}