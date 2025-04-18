#include "string"
using namespace std;
#ifndef CSVHANDLER_H
#define CSVHANDLER_H
#pragma once

//Initialize Course data manually to courses.csv
void initDataManual2CSV();

//Initialize Course data from raw csv file to courses.csv
void initDataFromCSV2CSV(const string& file);


//Delete Course data from CSV with target id
void deleteCourseFromCSV(const string& file, string targetId);

#endif