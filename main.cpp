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

    cout << "Option menu:\n1. Show model curriculum\n2. Show student information\n3. Add course manually\n4. Add course from curriculum\n5. Delete course\n6. Update course\n7. Set point for a course\n8. Calculate GPA of a semester\n9. Calculate CGPA by course\n10. Calculate CGPA by semester\n11. See menu\n12. Exit" << endl;
    cout << "--------------------------------------------------------------" << endl;

    CL cl;
    cl.initDataFromCSV("./course-data/courses.csv");
    
    int option = 0;
    while (true) {
        while (true) {
            cout << "\nEnter option (1-12) (11 to see menu): ";
            cin >> option;
            if (option >= 1 && option <= 12) break;
            cout << "Invalid option. Please try again." << endl;
        }
        
        switch (option)
        {                       
            case 1:
                //Show model curriculum by semester
                cout << cl << endl;
                break;
            case 2:
                //Show a student's information
                cout << s << endl;
                break;
            case 3:
            {
                //Add course from user
                Course course;
                cin >> course;      //Ensured to be valid
                cout << course << endl;
                s.cList.addCourse(course);
                s.n = s.cList.getCount();
                cout << "Course added successfully!" << endl << endl;
                break;
            }
            case 4:
            {
                //Add course from curriculum
                string id;
                int sem;                                                            //Need to validate
                cout << "Enter course ID to add (IT001): ";
                cin >> id;
                strUpper(id);
                Node* node = cl.findNode(id);
                if (!node){
                    cout << "Error: Course ID \"" << id << "\" not found!" << endl;
                    break;
                }

                while (true){
                    cout << "Enter semester taken that course (1-6): ";
                    cin >> sem;
                    if (sem >= 1 && sem <= 6)
                        break;
                }                
                sem--;

                if (s.addCourse(cl,id,sem))
                    cout << "Course added successfully!" << endl;
                else
                    cout << "Error adding course..." << endl;
                break;
            }
            case 5:
            {
                //Delete a course from student's course list
                string id;
                int sem;
                cout << "Enter course ID to delete: ";
                cin >> id;
                strUpper(id);
                while (true){
                    cout << "Enter semester taken that course (1-6): ";
                    cin >> sem;
                    if (sem >= 1 && sem <= 6)
                        break;
                }
                sem--;
                if (s.cList.deleteCourse(id, sem)){
                    cout << "Course deleted successfully!" << endl;
                    s.n = s.cList.getCount();
                }
                else
                    cout << "Error deleting course..." << endl;
                break;
            }
            case 6:
            {
                //Update a cousre
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
            {
                //Set point for a course
                string id;
                int sem;
                float poi;
                cout << "Enter course ID to set point (IT001): ";
                cin >> id;
                strUpper(id);
                while (true){
                    cout << "Enter semester taken that course (1-6): ";
                    cin >> sem;
                    if (sem >= 1 && sem <= 6)
                        break;
                }
                sem--;
                if (!s.cList.findNode(id,sem)){
                    cout << "Error: Course ID \"" << id << "\" not found!" << endl;
                    break;
                }
                cout << "Enter point (0-10): ";
                cin >> poi;
                if (poi < 0 || poi > 10){
                    cout << "Error: Point must be in scale of 10." << endl;
                    break;
                }
                if (s.setPoint(id,sem,poi)){
                    cout << "Set point for course \"" << id << "\" successfully!" << endl;
                } else
                    cout << "Error setting point..." << endl;
                break;
            }
            case 8:
            {   
                //Calcualate GPA of a semester
                int sem;
                while (true){
                    cout << "Enter semester to calculate GPA: ";
                    cin >> sem;
                    if (sem >= 1 && sem <= 6)
                        break;
                }
                sem--;
                float semGPA = s.calcSemesterGPA(sem);
                cout << "GPA of semester " << sem+1 << " = " << semGPA << endl;
                break;
            }
            case 9:
            {
                //Calcualate CGPA of a Student devided by course
                float CGPA = s.calcCGPAbyCourse();
                cout << "CGPA of student \"" << s.id << "\" = " << CGPA << endl;
                break;
            }
            case 10:
            {
                //Calcualate CGPA of a Student devided by semester
                float CGPA = s.calcCGPAbySemester();
                cout << "CGPA of student \"" << s.id << "\" = " << CGPA << endl;
                break;
            }
            case 11:
                cout << "Option menu:\n1. Show model curriculum\n2. Show student information\n3. Add course manually\n4. Add course from curriculum\n5. Delete course\n6. Update course\n7. Set point for a course\n8. Calculate GPA of a semester\n9. Calculate CGPA by course\n10. Calculate CGPA by semester\n11. See menu\n12. Exit" << endl;
                cout << "--------------------------------------------------------------" << endl;
                continue;
            case 12:
                exit(0);
                break;
        }
    }

    return 0;
}