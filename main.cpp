#include "iostream"
#include "stdio.h"
#include "cstdio"
#include "string"
#include "Course.h"
#include "CourseList.h"
#include "dataHandler.h"
#include "Student.h"
#include "cctype"
#include "limits"
using namespace std;


int main()
{
    cout << "---------- CUMULATIVE GRADE POINT AVERAGE CALCULATOR ---------\nThis CGPA calculator is for 2nd Bachelor Degree in Information Technology at UIT.\n" << endl;

    Student s;
    cin >> s;
    cout << endl;

    cout << "Option menu:\n1. Show model curriculum\n2. Show student information\n3. Add course manually\n4. Add course from curriculum\n5. Delete course\n6. Update course\n7. Set point for a course\n8. Calculate GPA of a semester\n9. Calculate CGPA by course\n10. Calculate CGPA by semester\n11. See menu\n12. Exit" << endl;
    cout << "--------------------------------------------------------------" << endl;

    CL cl;
    string path = string(PROJECT_ROOT) + "/course-data/courses.csv";
    cl.initDataFromCSV(path);
    
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
                string id = validateIDInput();
                int sem = validateSemesterInput();

                Node* node = cl.findNode(id);
                if (!node){
                    cout << "Error: Course ID \"" << id << "\" not found!" << endl;
                    break;
                }

                if (s.addCourse(cl,id,sem))
                    cout << "Course added successfully!" << endl;
                else
                    cout << "Error adding course..." << endl;
                break;
            }
            case 5:
            {
                //Delete a course from student's course list
                string id = validateIDInput();
                int sem = validateSemesterInput();        

                if (s.cList.deleteCourse(id, sem)){
                    cout << "Course deleted successfully!" << endl;
                    s.n = s.cList.getCount();
                }
                else
                    cout << "Error deleting course..." << endl;
                break;
            }
            case 6:                                                                 //DONE
            {
                //Update a cousre
                string id = validateIDInput();
                Node* node = s.cList.findNode(id);
                if (!node){
                    cout << "Error: Course ID \"" << id << "\" not found!" << endl;
                    break;
                }

                string name;
                cout << "Name (Enter if no change): ";
                getline(cin, name);
                if (!name.empty())
                    node->c.name = name;

                node->c.tolCredit = validateTolCreditInput();
                node->c.lecCredit = validateLecCreditInput(node->c.tolCredit);
                node->c.labCredit = node->c.tolCredit - node->c.lecCredit;
                node->c.point = validatePointInput();
                s.cList.changeSemester(node, validateSemesterInput());

                cout << "Course updated successfully!" << endl;
                break;
            }
            case 7:                                                                 //DONE
            {
                //Set point for a course
                string id = validateIDInput();
                int sem = validateSemesterInput();

                if (!s.cList.findNode(id,sem)){
                    cout << "Error: Course ID \"" << id << "\" not found!" << endl;
                    break;
                }
                
                float poi = validatePointInput();
                if (s.setPoint(id,sem,poi)){
                    cout << "Set point for course \"" << id << "\" successfully!" << endl;
                } else
                    cout << "Error setting point..." << endl;
                break;
            }
            case 8:
            {   
                //Calcualate GPA of a semester
                int sem = validateSemesterInput();
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
        }
    }

    return 0;
}