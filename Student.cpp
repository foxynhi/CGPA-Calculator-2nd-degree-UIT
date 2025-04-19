#include "Student.h"
#include "cmath"

ostream& operator<<(ostream& os, Student& s)
{
    os << "{" << s.id << "; " << s.name << "; " << s.n << " courses:\n" << s.cList << "}" << endl; 
    return os;
}

void Student::setPoint(string targetId, int sem, float p)
{
    Node* pCourse = cList.findNode(targetId, sem);
    cList.updateCourse(targetId, pCourse->c.name, pCourse->c.tolCredit, pCourse->c.lecCredit, pCourse->c.labCredit, p, sem);
}

float Student::calcCGPAbySemester()
{
    float sum = 0;
    int sem = 0;
    for (int i = 0; i < N; i++){
        if (cList.semester[i].pHead == nullptr) 
            break;
        sum += cList.semester[i].calcSemesterGPA();
        sem++;
    }
    return round(sum / sem * 100) / 100.;
}

float calcCGPAbyCourse();