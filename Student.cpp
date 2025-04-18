#include "Student.h"

ostream& operator<<(ostream& os, Student& s)
{
    os << "{" << s.id << "; " << s.name << "; " << s.n << " courses:\n" << s.cList << "}" << endl; 
    return os;
}