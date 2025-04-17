#include "CourseList.h"
#include "fstream"
#include "sstream"


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
    cout << "\t{ID; NAME; TOTAL CREDIT; LECTURE CREDIT; LAB CREDIT; POINT; SEMESTER}" << endl;
    for (int i = 0; i < N; i++)
    {
        os << "Semester " << i+1 << ":\n\t";
        for (Node* p = cList.semester[i].pHead; p != nullptr; p = p->pNext)
        {
            os << p->c << "\t";
        }
        os << endl;
    }
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
        c.semester = stoi(token);

        addCourse(c);
    }
    in.close();
}

void CourseList::deleteCourse(string targetId, int sem)
{
    Node* p = semester[sem].pHead;
    for ( ; p != nullptr; p = p->pNext){
        
    }
}

void CourseList::updateCourse(string targetId, string targetName, int tolCre, int lecCre, int labCre, int p, int sem)
{

}
