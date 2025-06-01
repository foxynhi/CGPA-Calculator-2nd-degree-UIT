#include "Semester.h"
#include "cmath"

Semester::Semester()
{
    pHead = nullptr;
}

//Semester linked list destructor
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