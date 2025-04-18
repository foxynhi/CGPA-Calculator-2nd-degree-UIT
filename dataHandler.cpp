#include "dataHandler.h"
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

void initDataFromCSV2CSV(const string& file)
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