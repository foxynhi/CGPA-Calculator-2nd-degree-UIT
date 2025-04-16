#include "Semester.h"

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