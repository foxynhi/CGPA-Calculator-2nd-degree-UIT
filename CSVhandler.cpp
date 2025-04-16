#include "CSVhandler.h"
#include "Course.h"
#include "iostream"
#include "string"
#include "fstream"
#include "sstream"
#include "cstdio"
#include "stdio.h"
using namespace std;

void initDataManual2CSV()
{
    if (remove("/home/nhi/Practice/CGPA-calculator/course-data/courses.csv") == 0){
        cout << "Replacing data..." << endl;
    } else cout << "Creating csv file..." << endl;

    ofstream fout("/home/nhi/Practice/CGPA-calculator/course-data/courses.csv");
    if(!fout.is_open()){
        cerr << "Cannot open file." << endl;
        return;
    }
    fout << "id,name,totalCredit,lectureCredit,labCredit,point,semester\n";

    int n;
    cout << "number of courses to enter: ";
    cin >> n;
    Course c;
    for (int i = 0; i < n; i++){
        cin >> c;
        fout << c.id << "," 
            << c.name << "," 
            << c.tolCredit << "," 
            << c.lecCredit << "," 
            << c.labCredit << "," 
            << c.point << "," 
            << c.semester << '\n';
    }
    fout.close();
}

void initDataFromCSV2CSV(const string& csv)
{
    if (remove("/home/nhi/Practice/CGPA-calculator/course-data/courses.csv") == 0){
        cout << "Replacing data..." << endl;
    } else cout << "Creating csv file..." << endl;

    ofstream fout("/home/nhi/Practice/CGPA-calculator/course-data/courses.csv");
    if(!fout.is_open()){
        perror("Cannot open output file.");
        return;
    }
    fout << "id,name,totalCredit,lectureCredit,labCredit,point,semester\n";

    ifstream fin(csv);
    if (!fin.is_open()) {
        cerr << "Cannot open input file." << endl;
        fout.close();
        fin.close();
        return;
    }

    string line;
    getline(fin, line);
    while (getline(fin, line)){
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
        fout << c.toCSV() << '\n';
    }
    fout.close();
    fin.close();
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

    remove(file.c_str());
    rename("temp.csv", file.c_str());
}

void updateCourseData()
{

}

// Course findCourse()
// {

// }
