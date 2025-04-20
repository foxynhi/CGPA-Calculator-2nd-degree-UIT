#include "Course.h"
#include "iostream"
#include "string"
#include "sstream"
#include "limits"
using namespace std;

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
    int s;
    is >> s;
    c.semester = s-1;
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
};