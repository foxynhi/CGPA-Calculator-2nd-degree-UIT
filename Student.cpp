#include "Student.h"
#include "cmath"
#include "fstream"
#include "sstream"
#include "limits"
using namespace std;

ostream& operator<<(ostream& os, Student& s)
{
    os << "{" << s.id << "; " << s.name << "; " << s.n << " courses:\n" << s.cList << "}" << endl; 
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
    cout << "Number of courses taken: ";
    is >> s.n;
    return is;
}

bool Student::addTakenCourse(string targetId, int sem, float p)
{
    //Find Course data in CSV
    ifstream in("./course-data/courses.csv");
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

            c.id = id;

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
    Node* node = cList.findNode(targetId, sem);
    if (!node) 
        return false;
    cList.updateCourse(node, node->c.name, node->c.tolCredit, node->c.lecCredit, node->c.labCredit, p, sem);
    return true;
}

float Student::calcCGPAbySemester()
{
    float sum = 0;
    int sem = 0;
    for (int i = 0; i < N; i++){
        if (cList.semester[i].pHead == nullptr) 
            continue;
        sum += cList.semester[i].calcSemesterGPA();
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