#include "Student.h"
#include "cmath"
#include "fstream"
#include "sstream"
using namespace std;

ostream& operator<<(ostream& os, Student& s)
{
    os << "{" << s.id << "; " << s.name << "; " << s.n << " courses:\n" << s.cList << "}" << endl; 
    return os;
}

bool Student::addTakenCourse(string targetId, int sem, float p)
{
    //Find Course data in CSV
    ifstream in("../course-data/courses.csv");
    if (!in.is_open()){
        cerr << "Cannot open input file." << endl;
        in.close();
        return false;
    }

    string line;
    getline(in, line);

    while (getline(in, line)){
        stringstream s(line);
        string id;
        getline(s, id, ',');
        if (id == targetId){
            Course c;
            string token;
            getline(s,token, ',');
            c.name = token;

            getline(s,token, ',');
            c.tolCredit = stoi(token);
            
            getline(s,token, ',');
            c.lecCredit = stoi(token);

            getline(s,token, ',');
            c.labCredit = stoi(token);

            c.point = p;

            c.semester = sem;

            cList.addCourse(c);

            n = cList.getCount();
            return true;
        }
    }
    return false;
}

bool Student::setPoint(string targetId, int sem, float p)
{
    Node* pCourse = cList.findNode(targetId, sem);
    if (!pCourse) 
        return false;
    cList.updateCourse(targetId, pCourse->c.name, pCourse->c.tolCredit, pCourse->c.lecCredit, pCourse->c.labCredit, p, sem);
    return true;
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

float Student::calcCGPAbyCourse()
{
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++){
        if (cList.semester[i].pHead == nullptr) 
            break;

        for (Node* p = cList.semester[i].pHead; p != nullptr; p = p->pNext){
            sum += p->c.point;
            count++;
        }
    }
    return round(sum / count * 100) / 100.;

}