#include "Course.h"
#include "iostream"
#include "string"
#include "sstream"
#include "limits"
#include "config.h"
#include "dataHandler.h"
#include "iomanip"
using namespace std;

istream& operator>>(istream& is, Course& c)
{
    c.id = validateIDInput();

    cout << "Course name: ";
    getline(is, c.name);

    c.tolCredit = validateTolCreditInput();
    c.labCredit = validateLecCreditInput(c.tolCredit);
    c.lecCredit = c.tolCredit - c.labCredit;
    c.point = validatePointInput();

    c.semester = validateSemesterInput();
    return is;
}
ostream& operator<<(ostream& os, Course& c)
{
    os << "| " << c.id << " | "
        << setw(38) << left << c.name << " | "
        << setw(10) << left << c.tolCredit << " | "
        << setw(12) << left << c.lecCredit << " | "
        << setw(8) << left << c.labCredit << " | "
        << setw(5) << left << c.point << " | "
        << setw(8) << left << c.semester << " | " << endl;
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
