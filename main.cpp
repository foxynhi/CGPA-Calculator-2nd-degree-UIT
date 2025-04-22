#include "iostream"
#include "stdio.h"
#include "cstdio"
#include "string"
#include "Course.h"
#include "CourseList.h"
#include "dataHandler.h"
#include "Student.h"
#include "cctype"
using namespace std;

void strUpper(string& s)
{
    for (char& x : s){
        x = (char)toupper(x);
    }
}

int main()
{
    cout << "---------- CUMULATIVE GRADE POINT AVERAGE CALCULATOR ---------\nThis CGPA calculator is for 2nd Bachelor Degree in Information Technology at UIT.\n" << endl;

    Student s;
    cin >> s;
    cout << endl;

    cout << "Option menu:\n1. Show model curriculum\n2. Show student information\n3. Add course manually\n4. Add course from curriculum\n5. Delete course\n6. Update course\n7. Add point for course\n8. Calculate GPA of a semester\n9. Calculate CGPA by course\n10. Calculate CGPA by semester\n11. See menu\n12. Exit" << endl;
    cout << "--------------------------------------------------------------" << endl;

    CL cl;
    cl.initDataFromCSV("./course-data/courses.csv");
    
    int option = 0;
    while (true) {
        while (true) {
            cout << "\nEnter option (1-12): ";
            cin >> option;
            if (option >= 1 && option <= 12) break;
            cout << "Invalid option. Please try again." << endl;
        }
        
        switch (option)
        {                       
            case 1:
                cout << cl << endl;
                break;
            case 2:
                cout << s << endl;
                break;
            case 3: {
                Course course;
                cin >> course;
                s.cList.addCourse(course);
                cout << "Course added successfully!" << endl << endl;
                break;
            }
            case 4:{
                //Add course from curriculum
                string id;
                int sem;
                cout << "Enter course id (IT001): ";
                cin >> id;
                strUpper(id);
                Node* node = cl.findNode(id);
                if (!node){
                    cout << "Error: Course ID \"" << id << "\" not found!" << endl;
                    break;
                }
                cout << "Enter semester taken that course (1-6): ";
                cin >> sem;
                sem--;
                Course course = node->c;
                course.semester = sem;
                s.cList.addCourse(course);
                cout << "Course added successfully!" << endl; 
                break;
            }
            case 5:{
                string id;
                cout << "Enter course ID to delete: ";
                cin >> id;
                strUpper(id);
                if (s.cList.deleteCourse(id))
                    cout << "Course deleted successfully!" << endl;
                else
                    cout << "Error deleting course..." << endl;
                break;
            }
            case 6:{
                //Update cousre
                string id;
                cout << "Enter course ID to update: ";
                cin >> id;
                strUpper(id);
                Node* node = s.cList.findNode(id);
                if (!node){
                    cout << "Error: Course ID \"" << id << "\" not found!" << endl;
                    break;
                }

                string name, token;
                cout << "Name (Enter if no change): ";
                cin.ignore();
                getline(cin, name);
                if (!name.empty())
                    node->c.name = name;

                cout << "Total credit (Enter if no change): ";
                getline(cin, token);
                if (!token.empty())
                    node->c.tolCredit = stoi(token);
                
                cout << "Lecture credit (Enter if no change): ";
                getline(cin, token);
                if (!token.empty())
                    node->c.lecCredit = stoi(token);

                cout << "Lab credit (Enter if no change): ";
                getline(cin, token);
                if (!token.empty())
                    node->c.labCredit = stoi(token);

                cout << "Point (Enter if no change): ";
                getline(cin, token);
                if (!token.empty())
                    node->c.point = stoi(token);
                
                cout << "Semester (Enter if no change): ";
                getline(cin, token);
                if (!token.empty())
                    s.cList.changeSemester(node, stoi(token)-1);

                cout << "Course updated successfully!" << endl;
                break;
            }
            case 7:
                cout << "Add point for course" << endl;
                break;
            case 8:
                cout << "Calculate GPA of a semester" << endl;
                break;
            case 9:
                cout << "Calculate CGPA by course" << endl;
                break;
            case 10:
                cout << "Calculate CGPA by semester" << endl;
                break;
            case 11:
                cout << "Exit" << endl;
                break;
            case 12:
                exit(0);
                break;
        }
    }

    // Course c1("it", "a", 2, 1, 1, 10, 1);
    // cout << c1 << endl;
    // cl.addCourse(c1);
    // cout << cl;

    // Course c2;
    // cin >> c2;
    // cout << c2;
    // deleteCourseFromCSV("/home/nhi/Practice/CGPA-calculator/course-data/courses.csv", "1"); 
    // deleteCourseFromCSV("/home/nhi/Practice/CGPA-calculator/course-data/courses.csv", "2"); 
    // deleteCourseFromCSV("course-data/courses.csv", 3);

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
    // Student s1(123, "Nguyen Van A", 0, cl);
    // // cout << s1 << endl;

    // // cout << "Find Node" << s1.cList.findNode("IE101", 0) << endl;
    // // s1.setPoint("IE101", 0, 10.);
    // // s1.setPoint("IT005", 0, 10.);
    // // s1.setPoint("IT004", 0, 10.);
    // // s1.setPoint("IE005", 0, 10.);
    // // s1.setPoint("IT001", 0, 10.);

    // // s1.setPoint("MA004", 1, 9.);
    // // s1.setPoint("IT012", 1, 9.);
    // // s1.setPoint("IT003", 1, 9.);
    // // s1.setPoint("IT002", 1, 9.);

    // // s1.setPoint("IE106", 2, 8.);
    // // s1.setPoint("IE104", 2, 8.);
    // // s1.setPoint("IE103", 2, 8.);
    // // cout << s1 << endl;

    // // cout << "Calculate CGPA by Semester's GPA: " << s1.calcCGPAbySemester() << endl;
    // // cout << "Calculate CGPA by Course: " << s1.calcCGPAbyCourse() << endl;

    // s1.addTakenCourse("IT005", 0, 9.5);
    // s1.addTakenCourse("IT004", 0, 8.8);
    // s1.addTakenCourse("IE005", 0, 8.3);
    // s1.addTakenCourse("IT001", 0, 8.6);
    // s1.addTakenCourse("IE101", 0, 7.3);
    // cout << s1 << endl;

    // cout << s1.cList.semester[0].calcSemesterGPA() << endl;
    // cout << s1.calcCGPAbySemester() << endl;
    // cout << s1.calcCGPAbyCourse() << endl;
    // cout << endl;
    return 0;
}