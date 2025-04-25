#include "dataHandler.h"
#include "Course.h"
#include "iostream"
#include "string"
#include "fstream"
#include "filesystem"
#include "sstream"
#include "cstdio"
#include "stdio.h"
#include "limits"
using namespace std;

void initDataManual2CSV()
{
    if (remove("./course-data/courses.csv") == 0){
        cout << "Replacing data..." << endl;
    } else cout << "Creating csv file..." << endl;

    ofstream out("./course-data/courses.csv");
    if(!out.is_open()){
        cerr << "Cannot open file." << endl;
        return;
    }
    out << "id,name,totalCredit,lectureCredit,labCredit,point,semester\n";

    int n;
    cout << "number of courses to enter: ";
    cin >> n;
    Course c;
    for (int i = 0; i < n; i++){
        cin >> c;
        out << c.id << "," 
            << c.name << "," 
            << c.tolCredit << "," 
            << c.lecCredit << "," 
            << c.labCredit << "," 
            << c.point << "," 
            << c.semester << '\n';
    }
    out.close();
}

void convertCSVFormat(const string& file)
{
    if (remove("./course-data/courses.csv") == 0){
        cout << "Replacing data..." << endl;
    } else cout << "Creating csv file..." << endl;

    ofstream out("./course-data/courses.csv");
    if(!out.is_open()){
        perror("Cannot open output file.");
        return;
    }
    out << "id,name,totalCredit,lectureCredit,labCredit,point,semester\n";

    ifstream in(file);
    if (!in.is_open()) {
        cerr << "Cannot open input file." << endl;
        out.close();
        in.close();
        return;
    }

    string line;
    getline(in, line);
    while (getline(in, line)){
        stringstream ss(line);
        string token;
        string id, name;
        int tolCre, lecCre, labCre, sem;

        getline(ss, token, ',');
        sem = stoi(token);

        getline(ss, id, ',');

        getline(ss, name, ',');

        getline(ss, token, ',');
        tolCre = stoi(token);

        getline(ss, token, ',');
        lecCre = stoi(token);

        getline(ss, token, ',');
        labCre = stoi(token);

        Course c(id,name,tolCre,lecCre,labCre,0,sem);
        out << c.toCSV() << '\n';
    }
    out.close();
    in.close();
    cout << "Done!" << endl;
}

void deleteCourseFromCSV(const string& file, string targetId)
{
    ifstream in(file);
    ofstream out("temp.csv");
    string line;
    getline(in, line);
    out << line <<'\n';

    while (getline(in, line)){
        stringstream s(line);
        string id;
        getline(s, id, ',');

        if (id != targetId){
            out << line << '\n';
        }
    }
    in.close();
    out.close();

    //c_str() to convert string to const char*
    remove(file.c_str());       // Delete old file  
    //rename() to move "temp.csv" to <file> name, replace if data exists
    rename("temp.csv", file.c_str());       // Rename temp to original name
}

void strUpper(string& s)
{
    for (char& x : s){
        x = (char)toupper(x);
    }
}

string validateIDInput()
{
    string id;
    while (true) {
        cout << "Enter course ID (IT001): ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (cin.fail()){
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (id.length() != 5 || !isalpha(id[0]) || !isalpha(id[1]) || !isdigit(id[2]) || !isdigit(id[3]) || !isdigit(id[4])){
            cout << "Invalid input. Course ID must be in the format IT001." << endl;
        }
        else break;        
    }
    strUpper(id);
    return id;
}

int validateSemesterInput()
{
    int sem;
    while (true){
        cout << "Enter semester (1-6): ";
        cin >> sem;
        if (cin.fail()){
            cout << "Invalid input. Semester must be a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (sem >= 1 && sem <= 6)
            break;
        cout << "Error: Semester must be in range [1-6]" << endl;
    }
    sem--;
    return sem;
}

int validateTolCreditInput()
{
    int tolCre;
    while (true){
        cout << "Enter total credit (0-8): ";
        cin >> tolCre;
        if (cin.fail()){
            cout << "Invalid input. Total credit must be a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (tolCre >= 0 && tolCre <= 8)
            break;
        else cout << "Error: Total credit must be in range [0-8]" << endl;
    }
    return tolCre;
}

int validateLecCreditInput(int labCre)
{
    int lecCre;
    while (true){
        cout << "Enter lecture credit (0-" << labCre <<"): ";
        cin >> lecCre;
        if (cin.fail()){
            cout << "Invalid input. Lecture credit must be a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (lecCre >= 0 && lecCre <= labCre)
            break;
        else cout << "Error: Lecture credit must be in range [0-" << labCre <<"]" << endl;
    }
    return lecCre;
}

float validatePointInput()
{
    float point;
    while (true){
        cout << "Enter point (0-10): ";
        cin >> point;
        if (cin.fail()){
            cout << "Invalid input. Point must be a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (point >= 0 && point <= 10)
            break;
        else cout << "Error: Point must be in scale of 10." << endl;
    }
    return point;
}