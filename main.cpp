#include "iostream"
#include "stdio.h"
#include "cstdio"
#include "string"
#include "Course.h"
#include "CourseList.h"
#include "dataHandler.h"
#include "Student.h"
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

    // cl.initDataFromCSV("/home/nhi/Practice/CGPA-calculator/course-data/courses.csv");
    // cout << cl << endl;

    // cout << "Test: Delete Course (IT001) successfully: "<< cl.deleteCourse("IT001", 1) << endl << endl;
    // cout << cl << endl;

    // cout << "Test: Update course (IE101) successfully:" << cl.updateCourse("IE101", "updated", 1,1,1,10,1) << endl << endl;
    // cout << cl << endl;

    // cout << "Test: GPA for semester 1 = ";
    // float gpa1 = cl.semester[0].calculateGPA();
    // cout << gpa1 << endl;

    // int n1 = cl.getCount();
    // cout << "Test: Get number of Courses in CourseList: " << n1 << endl;
    Student s1(123, "Nguyen Van A", 0, cl);
    // cout << s1 << endl;

    // cout << "Find Node" << s1.cList.findNode("IE101", 0) << endl;
    // s1.setPoint("IE101", 0, 10.);
    // s1.setPoint("IT005", 0, 10.);
    // s1.setPoint("IT004", 0, 10.);
    // s1.setPoint("IE005", 0, 10.);
    // s1.setPoint("IT001", 0, 10.);

    // s1.setPoint("MA004", 1, 9.);
    // s1.setPoint("IT012", 1, 9.);
    // s1.setPoint("IT003", 1, 9.);
    // s1.setPoint("IT002", 1, 9.);

    // s1.setPoint("IE106", 2, 8.);
    // s1.setPoint("IE104", 2, 8.);
    // s1.setPoint("IE103", 2, 8.);
    // cout << s1 << endl;

    // cout << "Calculate CGPA by Semester's GPA: " << s1.calcCGPAbySemester() << endl;
    // cout << "Calculate CGPA by Course: " << s1.calcCGPAbyCourse() << endl;

    s1.addTakenCourse("IE101", 1, 10);
    s1.addTakenCourse("IT005", 2, 10);
    s1.addTakenCourse("IT004", 3, 10);
    s1.addTakenCourse("MA004", 4, 10);
    s1.addTakenCourse("IT001", 5, 10);
    cout << s1 << endl;

    cout << endl;
    return 0;
}