#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include <cstdio>
using namespace std;

const int N = 6;

struct Course
{
private:
    string id;
    string name;
    int tolCredit;  //Total Credit hours
    int lecCredit;  //Lecture Credit hours
    int labCredit;  //Lab Credit hours
    float point;
    int semester;
public:
    Course()
        : id(""), name(""), tolCredit(0), lecCredit(0), labCredit(0), point(0), semester(0) {}
    Course(string i, string n, int t, int lec, int lab, float p, int s)
        : id(i), name(n), tolCredit(t), lecCredit(lec), labCredit(lab), point(p), semester(s) {}
    Course(const Course& x)
        : id(x.id), name(x.name), tolCredit(x.tolCredit), lecCredit(x.lecCredit), labCredit(x.labCredit), point(x.point), semester(x.semester) {}
    ~Course(){};
    friend istream& operator>>(istream& is, Course& c);
    friend ostream& operator<<(ostream& os, Course& c);
    Course operator=(Course& c);
    string getId() {return id;}
    string getName() {return name;}
    int getTolCredit() {return tolCredit;}
    int getLecCredit() {return lecCredit;}
    int getLabCredit() {return labCredit;}
    int getPoint() {return point;}
    int getSemester() {return semester;}
    void setId(string x) {id = x;}
    void setName(string x) {name = x;}
    void setTolCredit(int x) {tolCredit = x;}
    void setLecCredit(int x) {lecCredit = x;}
    void setLabCredit(int x) {labCredit = x;}
    void setPoint(int x) {point = x;}
    void setSemester(int x) {semester = x;}
    string toCSV() const {
        stringstream s;
        s << id << ","
        << name << "," 
        << tolCredit << "," 
        << lecCredit << "," 
        << labCredit << "," 
        << point << "," 
        << semester;
        return s.str();
    };
};
istream& operator>>(istream& is, Course& c)
{
    cout << "\nEnter course data:\n";
    cout << "id: ";
    is.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(is, c.id);
    cout << "name: ";
    // is.ignore(numeric_limits<streamsize>::max(), '\n');
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

Course Course::operator=(Course& c)
{
    id = c.id;
    name = c.name;
    tolCredit = c.tolCredit;
    lecCredit = c.lecCredit;
    labCredit = c.labCredit;
    point = c.point;
    semester = c.semester;
    return *this;
}

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
    Course c;
    Node* pNext;
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
    Node* pHead;
};
void initSemester(Semester& s){
    s.pHead = nullptr;
}

//List of courses a student takes overall
typedef struct CourseList
{
    private:
        Semester semester[N];
    public:
        void initCourseList(CourseList& cList);
        void addCourse(Course c);
        friend ostream& operator<<(ostream& os, CourseList& cList);
} CL;

void CourseList::initCourseList(CourseList& cList)
{
    for (int i = 0; i < N; i++){
        Semester s;
        initSemester(s);
        semester[i+1] = s;
    }
};
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

// void addCourse2CSV(const string& file, Course c)
// {
//     ofstream fout(file, ios::app);
//     if(!fout.is_open()){
//         cerr << "Cannot write file." << endl;
//         return;
//     }
//     fout.close();
//     cout << "write data into file successfully!" << endl;
// }

void initCourseData()
{
    if (remove("courses.csv") == 0){
        cout << "Replacing data..." << endl;
    } else perror("Error replacing data...");

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
        fout << c.getId() << "," 
            << c.getName() << "," 
            << c.getTolCredit() << "," 
            << c.getLecCredit() << "," 
            << c.getLabCredit() << "," 
            << c.getPoint() << "," 
            << c.getSemester() << '\n';
    }
    fout.close();
}

void initCourseDataFromCSV(const string& csv)
{
    if (remove("courses.csv") == 0){
        cout << "Replacing data..." << endl;
    } else cout << "Creating csv file..." << endl;
    ofstream fout("courses.csv");
    if(!fout.is_open()){
        cerr << "Cannot open file." << endl;
        return;
    }
    fout << "id,name,totalCredit,lectureCredit,labCredit,point,semester\n";

    ifstream fin(csv);
    if (!fin.is_open()) {
        cerr << "Cannot open input file." << endl;
        return;
    }

    string line;
    getline(fin, line);
    while (getline(fin, line)){
        stringstream ss(line);
        string token;
        string id, name;
        int tolCre, lecCre, labCre, sem;

        getline(ss, token, ',');
        sem = stoi(token);

        getline(ss, id, ',');

        getline(ss, name, ',');

        getline(ss, token, ',');
        tolCre = stoi(token);

        getline(ss, token, ',');
        lecCre = stoi(token);

        getline(ss, token, ',');
        labCre = stoi(token);

        Course c(id,name,tolCre,lecCre,labCre,0,sem);
        fout << c.toCSV() << '\n';
    }
    fout.close();
    fin.close();
    cout << "Done!" << endl;
}

void deleteCourse(const string& file, string targetId)
{
    ifstream in(file);
    ofstream out("temp.csv");
    string line;
    getline(in, line);
    out << line <<'\n';

    while (getline(in, line)){
        stringstream s(line);
        string id;
        getline(s, id, ',');

        if (id != targetId){
            out << line << '\n';
        }
    }
    in.close();
    out.close();

    remove(file.c_str());
    rename("temp.csv", file.c_str());
}

// void updateCourseData()
// {

// }

// Course findCourse()
// {

// }

int main()
{
    cout << "---------- CUMULATIVE GRADE POINT AVERAGE CALCULATOR ---------\nThis CGPA calculator is for 2nd Bachelor Degree in Information Technology at UIT.\n" << endl;
    // CL cList;
    // cList.initCourseList(cList);
    // Course c1(1, "a", 2, 1, 1, 10, 1);
    // cout << c1 << endl;
    // cList.addCourse(c1);
    // cout << cList;

    // Course c2;
    // cin >> c2;
    // cout << c2;
    initCourseDataFromCSV("./rawData.csv");
    // deleteCourse("courses.csv", 1); 
    // deleteCourse("courses.csv", 2); 
    // deleteCourse("courses.csv", 3); 
    return 0;
}