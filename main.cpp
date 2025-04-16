#include "iostream"
#include "stdio.h"
#include "cstdio"
#include "string"
#include "Course.h"
#include "CourseList.h"
#include "CSVhandler.h"
using namespace std;

int main()
{
    cout << "---------- CUMULATIVE GRADE POINT AVERAGE CALCULATOR ---------\nThis CGPA calculator is for 2nd Bachelor Degree in Information Technology at UIT.\n" << endl;
    // CL cl;
    // Course c1("it", "a", 2, 1, 1, 10, 1);
    // cout << c1 << endl;
    // cl.addCourse(c1);
    // cout << cl;

    // Course c2;
    // cin >> c2;
    // cout << c2;
    initDataFromCSV2CSV("./course-data/rawData.csv");
    // deleteCourseFromCSV("course-data/courses.csv", "1"); 
    // deleteCourseFromCSV("course-data/courses.csv", "2"); 
    // deleteCourseFromCSV("course-data/courses.csv", 3);

    return 0;
}