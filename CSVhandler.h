#include "string"
using namespace std;
#ifndef CSVHANDLER_H
#define CSVHANDLER_H
#pragma once

void initDataManual2CSV();
void initDataFromCSV2CSV(const string& csv);
void deleteCourseFromCSV(const string& file, std::string targetId);
void updateCourseData();
// Course findCourse();

#endif