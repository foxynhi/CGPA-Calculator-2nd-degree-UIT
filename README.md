# CGPA Calculator

This project is a **Cumulative Grade Point Average (CGPA) Calculator** designed for students pursuing a 2nd Bachelor's Degree in Information Technology at UIT. The program allows users to manage course data, calculate GPA/CGPA, and optionally save or load data from files.
## Features

- **Student Management**: Each student has a unique ID, name, and a list of courses taken.
- **Course Management**: Add, update, delete, and retrieve course details.
- **Semester Management**: Organize courses into semesters and calculate GPA for each semester.
- **CGPA Calculation**: Calculate CGPA based on semester GPAs or individual course grades.
- **File Handling**: Load course data from CSV files and save results to files.
## Concepts Used

This project demonstrates the following programming concepts:

1. **Object-Oriented Programming (OOP)**:
   - Structures: `Student`, `Course`, `CourseList`, `Semester`, `Node`.
   - Constructors and Destructors: Used for initialization and cleanup.

2. **Data Structures**:
   - **Linked Lists**: Each semester is implemented as a linked list of courses (`Node`).
   - **Array of Linked Lists**: `CourseList` contains an array of `Semester` objects.

3. **File Handling**:
   - Reading and writing CSV files for course data.
   - Using `ifstream` and `ofstream` for file operations.

4. **Algorithms**:
   - Searching: Find courses by ID.
   - GPA/CGPA Calculation: Arithmetic operations to compute weighted averages.

5. **Standard Libraries**:
   - `iostream`: Input/output operations.
   - `fstream`: File handling.
   - `sstream`: String stream for parsing CSV data.
   - `cmath`: Mathematical operations (e.g., rounding).
   - `iomanip`: Formatting output for tables.

## What I Learned

By completing this project, I gained hands-on experience with:

1. **Input Validation**:
   - Handling invalid user input (e.g., non-integer values, invalid strings).
   - Using `cin.fail()`, `cin.clear()`, and `cin.ignore()` to manage input errors effectively.

2. **Data Formatting**:
   - Displaying data in a clean, tabular format using `std::setw`, `std::left`, and `std::right`.
   - Formatting floating-point numbers with `std::fixed` and `std::setprecision` for better readability.

3. **Error Handling**:
   - Using exception handling (`try-catch`) to ensure robust input validation.
   - Preventing runtime crashes by checking for null pointers and invalid data.

4. **Object-Oriented Design**:
   - Designing reusable and modular structures like `Student`, `Course`, and `CourseList`.
   - Implementing operator overloading (`>>` and `<<`) for custom input/output operations.

5. **File Operations**:
   - Reading and writing structured data (e.g., CSV files) using `ifstream` and `ofstream`.
   - Converting objects to CSV format for easy storage and retrieval.

6. **Linked Lists**:
   - Implementing and managing linked lists for dynamic data storage.
   - Traversing and manipulating linked lists for operations like adding, deleting, and updating nodes.

7. **GPA/CGPA Calculation**:
   - Applying arithmetic operations to calculate weighted averages.
   - Managing and aggregating data across multiple semesters to compute GPA and CGPA.

8. **Debugging and Testing**:
   - Identifying and fixing common issues like infinite loops, invalid input, and segmentation faults.
   - Writing test cases to validate the correctness of functions and ensure program reliability.

## How It Works

1. **Data Representation**:
   - Each `Student` contains a `CourseList` and other details like ID and name.
   - `CourseList` is an array of `Semester` objects.
   - Each `Semester` is a linked list of `Node` objects, where each `Node` represents a `Course`.

2. **Key Functionalities**:
   - **Add Course**: Add a course to a specific semester.
   - **Delete Course**: Remove a course by ID and semester.
   - **Update Course**: Modify course details.
   - **Calculate GPA**: Compute GPA for a semester.
   - **Calculate CGPA**: Compute CGPA across all semesters or all courses.

3. **File Handling**:
   - Load course data from a CSV file using `initDataFromCSV`.

## Build and Run

### Prerequisites:
- C++ compiler (e.g., `g++`)
- CMake (version 3.10 or higher)

### Steps:
1. Clone the repository:
   ```bash
   git clone https://github.com/foxynhi/CGPA-Calculator-2nd-degree-UIT
   cd CGPA-calculator
   ```
2. Build the project:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```
3. Run the program:
   ```bash
   ./cgpa
   ```

### Future Enhancements
   - Support for multiple students.
   - Sorting courses by name or grade.
   - Searching for students by name.
   - Enhanced file handling for saving/loading student data.