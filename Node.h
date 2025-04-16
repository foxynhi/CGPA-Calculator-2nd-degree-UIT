#include "Course.h"
#ifndef NODE_H
#define NODE_H

#pragma once

//Node for a Course

struct Node
{
    Course c;
    Node* pNext;

    Node(const Course&);
    ~Node(){
        pNext = nullptr;
    };
};

#endif