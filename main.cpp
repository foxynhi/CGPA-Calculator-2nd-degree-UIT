#include "iostream"
#include "stdio.h"
#include "cstdio"
#include "string"
#include "Course.h"
#include "CourseList.h"
#include "dataHandler.h"
using namespace std;

int main()
{
    cout << "---------- CUMULATIVE GRADE POINT AVERAGE CALCULATOR ---------\nThis CGPA calculator is for 2nd Bachelor Degree in Information Technology at UIT.\n" << endl;
    CL cl;
    // Course c1("it", "a", 2, 1, 1, 10, 1);
    // cout << c1 << endl;
    // cl.addCourse(c1);
    // cout << cl;

    // Course c2;
    // cin >> c2;
    // cout << c2;
    // initDataFromCSV2CSV("/home/nhi/Practice/CGPA-calculator/course-data/rawData.csv");
    // deleteCourseFromCSV("/home/nhi/Practice/CGPA-calculator/course-data/courses.csv", "1"); 
    // deleteCourseFromCSV("/home/nhi/Practice/CGPA-calculator/course-data/courses.csv", "2"); 
    // deleteCourseFromCSV("course-data/courses.csv", 3);

    cl.initDataFromCSV("./course-data/courses.csv");
    cout << cl << endl;
    // cout << "Delete successfully: "<< cl.deleteCourse("IE101", 1) << endl << endl;
    // cout << cl << endl;

    cl.updateCourse("IE101", "updated", 1,1,1,1,1);
    cout << cl << endl;
    return 0;
}