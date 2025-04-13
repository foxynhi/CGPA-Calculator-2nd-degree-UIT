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
    Course(int i, string n, int t, int lec, int lab, float p)
        : id(i), name(n), tolCredit(t), lecCredit(lec), labCredit(lab), point(p) {}
    ~Course(){};
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
    Course* c = nullptr;
    Course* pNext = nullptr;
};

//Linked list of courses in a semester
struct Semester
{
    Course* pHead = nullptr;
};

//List of courses a student takes overall
struct CourseList
{
    Semester semester[N];
};
typedef CourseList CL;

void addCourse()
{

}


int main()
{
    cout << "---------- CUMULATIVE GRADE POINT AVERAGE CALCULATOR ---------\nThis CGPA calculator is for 2nd Bachelor Degree in Information Technology at UIT.\n" << endl;

    return 0;
}