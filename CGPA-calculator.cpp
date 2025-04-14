#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;

const int N = 6;

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
    friend istream& operator>>(istream& is, Course& c);
    friend ostream& operator<<(ostream& os, Course& c);
    int getId() {return id;}
    string getName() {return name;}
    int getTolCredit() {return tolCredit;}
    int getLecCredit() {return lecCredit;}
    int getLabCredit() {return labCredit;}
    int getPoint() {return point;}
    int getSemester() {return semester;}
};
istream& operator>>(istream& is, Course& c)
{
    cout << "Enter course data:\n";
    cout << "id: ";
    is >> c.id;
    cout << "name: ";
    is.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(is, c.name);
    cout << "total credits: ";
    is >> c.tolCredit;
    cout << "lecture credits: ";
    is >> c.lecCredit;
    cout << "lab credits: ";
    is >> c.labCredit;
    cout << "point: ";
    is >> c.point;
    cout << "semester (1-6): ";
    is >> c.semester;
    return is;
};
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
    int s = c.getSemester()-1;
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
        os << "Semester " << i+1 << ":\n";
        for (Node* p = cList.semester[i].pHead; p != nullptr; p = p->pNext)
        {
            os << p->c << "    ";
        }
        os << endl;
    }
    return os;
}

void initCourseData()
{
    ofstream fout("courses.csv");
    if(!fout.is_open()){
        cerr << "Cannot open file." << endl;
        return;
    }
    fout << "id,name,totalCredit,lectureCredit,labCredit,point,semester\n";

    int n;
    cout << "number of courses to enter: ";
    cin >> n;
    Course c;
    for (int i = 0; i < n; i++){
        cin >> c;
        fout << c.getId() << "," << c.getName() << "," << c.getTolCredit() << "," << c.getLecCredit() << "," << c.getLabCredit() << "," << c.getPoint() << "," << c.getSemester() << '\n';
    }
    fout.close();
}

void deleteCourse(const string& file, int targetId)
{
    ifstream in(file);
    ofstream out("temp.csv");
    string line;
    getline(in, line);

    while (getline(in, line)){
        stringstream s(line);
        string idStr;
        getline(s, idStr, ',');
        int id = stoi(idStr);

        if (id != targetId){
            out << line << '\n';
        }
    }
    in.close();
    out.close();

    remove(file.c_str());
    rename("temp.csv", file.c_str());
}

int main()
{
    cout << "---------- CUMULATIVE GRADE POINT AVERAGE CALCULATOR ---------\nThis CGPA calculator is for 2nd Bachelor Degree in Information Technology at UIT.\n" << endl;
    // // CL cList;
    // Course c1(1, "a", 2, 1, 1, 10, 1);
    // cout << c1 << endl;
    // cList.addCourse(c1);
    // cout << cList;

    // Course c2;
    // cin >> c2;
    // cout << c2;
    // initCourseData();
    deleteCourse("courses.csv", 1); 
    return 0;
}