#include "CourseList.h"
#include "fstream"
#include "sstream"
#include "iomanip"

CourseList::CourseList()
{
    for (int i = 0; i < N; i++){
        Semester s;
        semester[i] = s;
    }
}

Node* CourseList::deepCopySemester(Node* pHead)
{
    if (!pHead) return nullptr;

    Node* newHead = new Node;
    newHead->c = pHead->c;
    newHead->pNext = deepCopySemester(pHead->pNext);
    return newHead;
}

CourseList::CourseList(const CourseList& cl)
{
    for (int i = 0; i < N; i++){
        semester[i].pHead = deepCopySemester(cl.semester[i].pHead);
    }
}

void CourseList::addCourse(Course c)
{   
    int s = c.semester;
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
    if (cList.semester[0].pHead == nullptr){
        os << "No course data available." << endl;
        return os;
    }
    os << "| " << setw(5) << left << "ID" << " | "
        << setw(38) << left << "Course Name" << " | "
        << setw(10) << left << "Total cre." << " | "
        << setw(12) << left << "Lecture cre." << " | "
        << setw(8) << left << "Lab cre." << " | "
        << setw(5) << left << "Point" << " | "
        << setw(8) << left << "Semester" << " | " << endl;
    for (int i = 0; i < N; i++)
    {
        Node* p = cList.semester[i].pHead;
        if (!p) continue;
        os << "------------------------------------------------------------------------------------------------------------\n";
        for (; p != nullptr; p = p->pNext)
        {
            os << p->c;
        }
    }
    os << "------------------------------------------------------------------------------------------------------------\n";
    return os;
}
void CourseList::initDataFromCSV(const string& file)
{
    ifstream in(file);
    string line;
    getline(in, line);

    string token;
    Course c;

    while (getline(in, line)){
        stringstream s(line);
        getline(s, c.id, ',');

        getline(s, c.name, ',');

        getline(s, token, ',');
        c.tolCredit = stoi(token);

        getline(s, token, ',');
        c.lecCredit = stoi(token);

        getline(s, token, ',');
        c.labCredit = stoi(token);

        getline(s, token, ',');
        c.point = stoi(token);

        getline(s, token, ',');
        c.semester = stoi(token)-1;

        addCourse(c);
    }
    in.close();
}

Node* CourseList::findNode(string targetId)
{
    for (int i = 0; i < N; i++){
        for (Node* p = semester[i].pHead; p != nullptr; p = p->pNext){
            if (p->c.id == targetId){
                return p;
            }
        }
    }
    return nullptr;
}

Node* CourseList::findNode(string targetId, int sem)
{
    for (Node* p = semester[sem].pHead; p != nullptr; p = p->pNext){
        if (p->c.id == targetId){
            return p;
        }
    }
    return nullptr;
}

bool CourseList::deleteCourse(string targetId, int sem)
{
    Node* node = findNode(targetId, sem);
    if (!node) 
        return false;

    Node* pPrev = nullptr;
    Node* p = semester[sem].pHead;
    while (p != nullptr){
        if (p == node){
            if (pPrev == nullptr){
                semester[sem].pHead = p->pNext;
            } else {
                pPrev->pNext = p->pNext;
            }
            p->pNext = nullptr;
            delete p;
            return true;
        }
        pPrev = p;
        p = p->pNext;
    }
    return false;
}
bool CourseList::deleteCourse(string targetId)
{
    Node* node = findNode(targetId);
    if (!node) 
        return false;

    Node* pPrev = nullptr;
    Node* p = semester[node->c.semester].pHead;
    while (p != nullptr){
        if (p == node){
            if (pPrev == nullptr){
                semester[node->c.semester].pHead = p->pNext;
            } else {
                pPrev->pNext = p->pNext;
            }
            p->pNext = nullptr;
            delete p;
            return true;
        }
        pPrev = p;
        p = p->pNext;
    }
    return false;
}

bool CourseList::updateCourse(Node*& node, string targetName, int tolCre, int lecCre, int labCre, int p, int sem)
{
    node->c.name = targetName;
    node->c.tolCredit = tolCre;
    node->c.lecCredit = lecCre;
    node->c.labCredit = labCre;
    node->c.point = p;
    node->c.semester = sem;
    return true;
}

int CourseList::getCount()
{
    int count = 0;
    for (int i = 0; i < N; i++){
        for (Node* p = semester[i].pHead; p != nullptr; p = p->pNext){
            count++;
        }
    }
    return count;
}

void CourseList::changeSemester(Node* node, int sem)
{
    Course course(node->c);
    course.semester = sem;
    addCourse(course);
    deleteCourse(node->c.id, node->c.semester);
}