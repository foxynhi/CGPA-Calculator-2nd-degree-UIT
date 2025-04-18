cmake_minimum_required(VERSION 3.10)
project(cpp-repo)

set(CMAKE_CXX_STANDARD 17)

# Add source files
add_executable(cgpa
    main.cpp
    Course.cpp
    CourseList.cpp
    Node.cpp
    Semester.cpp
    Student.cpp
    dataHandler.cpp
)
