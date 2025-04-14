#include <iostream>
#include <string>
using namespace std;

const int N = 5;

struct Course
{
private:
    int id;
    string name;
    int tolCredit;  //Total Credit hours
    int lecCredit;  //Lecture Credit hours
    int labCredit;  //Lab Credit hours
    float point;
    int semester;
public:
    Course()
        : id(0), name(""), tolCredit(0), lecCredit(0), labCredit(0), point(0), semester(0) {}
    Course(int i, string n, int t, int lec, int lab, float p, int s)
        : id(i), name(n), tolCredit(t), lecCredit(lec), labCredit(lab), point(p), semester(s) {}
    Course(const Course& x)
        : id(x.id), name(x.name), tolCredit(x.tolCredit), lecCredit(x.lecCredit), labCredit(x.labCredit), point(x.point), semester(x.semester) {}
    ~Course(){};
    // friend istream& operator>>(istream& is, Course& c);
    friend ostream& operator<<(ostream& os, Course& c);
    int getSemester() {
        return semester;
    }
};
// istream& operator>>(istream& is, Course& c)
// {
    
// };
ostream& operator<<(ostream& os, Course& c)
{
    os << "{" << c.id << "; " << c.name << "; " << c.tolCredit << "; " << c.lecCredit << "; " << c.labCredit << "; " << c.point << "; " << c.semester << "}" << endl;
    return os;
};

struct Student
{
private:
    int id;
    string name;
    int n;      //Number of courses taken
public:
    Student()
        : id(0), name(""), n(0) {}
    Student(int i, string n, int nn)
        : id(i), name(n), n(nn) {}
    ~Student(){};
};

//Node for a Course
struct Node
{
    Course c = Course();
    Node* pNext = nullptr;
};

Node* initNode(Course c)
{
    Node* p = new Node;
    p->c = c;
    p->pNext = nullptr;

    return p;
};

//Linked list of courses in a semester
struct Semester
{
    Node* pHead = nullptr;
};

//List of courses a student takes overall
struct CourseList
{
    private:
        Semester semester[N];
    public:
        void addCourse(Course c);
        friend ostream& operator<<(ostream& os, CourseList& cList);
};
typedef CourseList CL;

//add a course into CL
void CourseList::addCourse(Course c)
{   
    int s = c.getSemester();
    Node* p = semester[s].pHead;
    Node* cNode = initNode(c);
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
        cout << "Semester " << i << ": " << endl;
        for (Node* p = cList.semester[i].pHead; p != nullptr; p = p->pNext)
        {
            cout << p->c << "    ";
        }
        cout << endl;
    }
    cout << endl;
};

int main()
{
    cout << "---------- CUMULATIVE GRADE POINT AVERAGE CALCULATOR ---------\nThis CGPA calculator is for 2nd Bachelor Degree in Information Technology at UIT.\n" << endl;
    CL cList;
    Course c1(1, "a", 2, 1, 1, 10, 1);
    cout << c1 << endl;
    cList.addCourse(c1);
    cout << cList;
    return 0;
}