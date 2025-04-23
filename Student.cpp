#include "Student.h"
#include "cmath"
#include "fstream"
#include "sstream"
#include "limits"
using namespace std;

ostream& operator<<(ostream& os, Student& s)
{
    os << s.id << "; " << s.name << "; " << s.n << " courses:\n" << s.cList; 
    return os;
}
istream& operator>>(istream& is, Student& s)
{
    cout << "Enter student information:\n";
    cout << "ID (123): ";
    is >> s.id;
    cout << "Name (Nguyen Van An): ";
    is.ignore(numeric_limits<streamsize>::max(), '\n');
    is >> s.name;
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
    int count = 0;
    float sum = 0;
    
    for (Node* p = cList.semester[sem].pHead; p != nullptr; p = p->pNext){
        sum += p->c.point * p->c.tolCredit;
        count += p->c.tolCredit;
    }
    return round(sum / count * 100) /100.;
}

float Student::calcCGPAbySemester()
{
    float sum = 0;
    int sem = 0;
    for (int i = 0; i < N; i++){
        if (cList.semester[i].pHead == nullptr) 
            continue;
        sum += calcSemesterGPA(i);
        sem++;
    }
    cout << "Calculate GPA by Semester:\nSemester counted: " << sem << endl;
    return round(sum / sem * 100) / 100.;
}

float Student::calcCGPAbyCourse()
{
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
    cout << "Calculate GPA by Course:\nCredits counted: " << count << endl;
    return round(sum / count * 100) / 100.;

}