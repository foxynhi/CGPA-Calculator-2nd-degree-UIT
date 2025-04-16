#include "CourseList.h"


CourseList::CourseList()
{
    for (int i = 0; i < N; i++){
        Semester s;
        semester[i+1] = s;
    }
}
//add a course into CL
void CourseList::addCourse(Course c)
{   
    int s = c.semester-1;
    Node* p = semester[s].pHead;
    Node* cNode = new Node(c);;
    if (p == nullptr){
        semester[s].pHead = cNode;
        return;
    }
    cNode->pNext = p;
    semester[s].pHead = cNode;
}

ostream& operator<<(ostream& os, CourseList& cList)
{
    for (int i = 0; i < N; i++)
    {
        os << "Semester " << i+1 << ":\n";
        for (Node* p = cList.semester[i].pHead; p != nullptr; p = p->pNext)
        {
            os << p->c << "    ";
        }
        os << endl;
    }
    return os;
}
