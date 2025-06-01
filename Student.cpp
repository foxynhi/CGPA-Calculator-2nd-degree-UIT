#include "Student.h"
#include "cmath"
#include "fstream"
#include "sstream"
#include "limits"
using namespace std;

ostream& operator<<(ostream& os, Student& s)
{
    os << "ID: " << s.id 
        << "\nName: " << s.name 
        << "\n" << s.n << " courses\n\n" << s.cList; 
    return os;
}

istream& operator>>(istream& is, Student& s)
{
    cout << "Enter student information:\n";
    while (true) {
        cout << "ID (123): ";
        is >> s.id;
        if (is.fail()){
            cout << "Invalid input. ID must be a number." << endl;
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n');
        } else break;
    }
    cout << "Name (Nguyen Van An): ";
    is.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(is, s.name);
    return is;
}

bool Student::addCourse(CL cl, string targetId, int sem)
{
    Node* node = cl.findNode(targetId);
    if (!node) 
        return false;
        
    Course course(node->c);
    course.semester = sem;
    cList.addCourse(course);
    n = cList.getCount();
    return true;
}

bool Student::setPoint(string targetId, int sem, float p)
{
    Node* node = cList.findNode(targetId, sem);
    if (!node) 
        return false;
    cList.updateCourse(node, node->c.name, node->c.tolCredit, node->c.lecCredit, node->c.labCredit, p, sem);
    return true;
}

float Student::calcSemesterGPA(int sem)
{
    Node* p = cList.semester[sem].pHead;
    if (p == nullptr) 
        return 0;
    int count = 0;
    float sum = 0;
    
    for (; p != nullptr; p = p->pNext){
        sum += p->c.point * p->c.tolCredit;
        count += p->c.tolCredit;
    }
    return round(sum / count * 100) /100.;
}

float Student::calcCGPAbySemester()
{
    if (cList.getCount() == 0) 
        return 0;
    float sum = 0;
    int sem = 0;
    for (int i = 0; i < N; i++){
        if (cList.semester[i].pHead == nullptr) 
            continue;
        sum += calcSemesterGPA(i);
        sem++;
    }
    return round(sum / sem * 100) / 100.;
}

float Student::calcCGPAbyCourse()
{
    if (cList.getCount() == 0) 
        return 0;
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++){
        if (cList.semester[i].pHead == nullptr) 
            continue;

        for (Node* p = cList.semester[i].pHead; p != nullptr; p = p->pNext){
            sum += p->c.point * p->c.tolCredit;
            count += p->c.tolCredit;
        }
    }
    return round(sum / count * 100) / 100.;

}