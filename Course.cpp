#include "Course.h"
#include "iostream"
#include "string"
#include "sstream"
#include "limits"
#include "config.h"
using namespace std;

istream& operator>>(istream& is, Course& c)
{
    cout << "\nEnter course data:\n";
    cout << "ID: ";
    string id;
    is.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(is, id);
    for (char& x : id){
        x = (char)toupper(x);
    }
    c.id = id;

    cout << "Name: ";
    getline(is, c.name);
    while (true){
        cout << "Total credits (0-8): ";
        is >> c.tolCredit;
        if (is.fail()){
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input." << endl;
            continue;
        }
        if (c.tolCredit >= 0 && c.tolCredit <= 8)
            break;
    }

    while (true){
        cout << "Lecture credits (0-8): ";
        is >> c.lecCredit;
        if (is.fail()){
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input." << endl;
            continue;
        }
        if (c.lecCredit >= 0 && c.lecCredit <= c.tolCredit)
            break;
    }

    c.labCredit = c.tolCredit - c.lecCredit;
    
    while (true){
        cout << "Point (0.0-10.0): ";
        is >> c.point;
        if (is.fail()){
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input." << endl;
            continue;
        }
        if (c.point >= 0 && c.point <= 10)
            break;
    }

    int s;
    while (true){
        cout << "Semester (1-" << N << "): ";
        is >> s;
        if (is.fail()){
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input." << endl;
            continue;
        }
        if (s >= 1 && s <= N){
            c.semester = s-1;
            break;
        }
    }
    return is;
}
ostream& operator<<(ostream& os, Course& c)
{
    os << "{" << c.id << "; " 
        << c.name << "; " 
        << c.tolCredit << "; " 
        << c.lecCredit << "; " 
        << c.labCredit << "; " 
        << c.point << "; " 
        << c.semester + 1 << "}" << endl;
    return os;
}
Course Course::operator=(const Course& c)
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
string Course::toCSV() const {
    stringstream s;
    s << id << ","
    << name << "," 
    << tolCredit << "," 
    << lecCredit << "," 
    << labCredit << "," 
    << point << "," 
    << semester;
    return s.str();
}
