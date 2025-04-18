#include "Course.h"
#ifndef NODE_H
#define NODE_H

#pragma once

//Node for a Course

struct Node
{
    Course c;
    Node* pNext;

    Node()
        : c(), pNext(nullptr) {};
    Node(const Course&);
    ~Node(){
        pNext = nullptr;
    };
    Node* deepCopyList(Node* pHead);
};

#endif