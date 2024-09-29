#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Structure for Student
struct Student {
    int id;
    string name;
    int age;
    float gpa;
};

// Structure for Teacher
struct Teacher {
    int id;
    string name;
    int age;
    string subject;
};

// Vectors to store students and teachers
vector<Student> students;
vector<Teacher> teachers;

// Function Prototypes
void showMenu();
void studentMenu();
void teacherMenu();
void addStudent();
void updateStudent();
void deleteStudent();
void viewStudents();
void addTeacher();
void updateTeacher();
void deleteTeacher();
void viewTeachers();
void login();
void homepage();

int main() {
    homepage();
    return 0;
}

// Home Page
void homepage() {
    cout << "**************************Welcome to School Management System***************************\n\n\n\n";
    cout << "1. Login\n";
    cout << "2. Exit\n";
    int choice;
    cin >> choice;
    if (choice == 1) {
        login();
    } else {
        cout << "Exiting...\n";
        exit(0);
    }
}

// Login Page
void login() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
   
    // Simple login check 
    if (username == "mahnoor" && password == "asd123") {
    	 cout << "\n\n\n\nLogged in Successfully!!!! \n\n\n\n ";
        showMenu();
    } else {
        cout << "Invalid credentials. Try again.\n";
        login();
    }
}

// Main Menu
void showMenu() {
    int choice;
    do {
        cout << "\nMain Menu\n";
        cout << "1. Student Module\n";
        cout << "2. Teacher Module\n";
        cout << "3. Logout\n";
        cin >> choice;

        switch (choice) {
            case 1:
                studentMenu();
                break;
            case 2:
                teacherMenu();
                break;
            case 3:
                homepage();
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
}

// Student Menu
void studentMenu() {
    int choice;
    do {
        cout << "\nStudent Module\n";
        cout << "1. Add Student\n";
        cout << "2. Update Student\n";
        cout << "3. Delete Student\n";
        cout << "4. View Students\n";
        cout << "5. Back to Main Menu\n";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                updateStudent();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                viewStudents();
                break;
            case 5:
                showMenu();
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
}

// Teacher Menu
void teacherMenu() {
    int choice;
    do {
        cout << "\nTeacher Module\n";
        cout << "1. Add Teacher\n";
        cout << "2. Update Teacher\n";
        cout << "3. Delete Teacher\n";
        cout << "4. View Teachers\n";
        cout << "5. Back to Main Menu\n";
        cin >> choice;

        switch (choice) {
            case 1:
                addTeacher();
                break;
            case 2:
                updateTeacher();
                break;
            case 3:
                deleteTeacher();
                break;
            case 4:
                viewTeachers();
                break;
            case 5:
                showMenu();
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
}

// Add Student
void addStudent() {
    Student newStudent;
    cout << "Enter Student ID: ";
    cin >> newStudent.id;
    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, newStudent.name);
    cout << "Enter Student Age: ";
    cin >> newStudent.age;
    cout << "Enter Student GPA: ";
    cin >> newStudent.gpa;
    students.push_back(newStudent);
    cout << "Student added successfully.\n";
}

// Update Student
void updateStudent() {
    int id;
    cout << "Enter Student ID to update: ";
    cin >> id;
    for (int i = 0; i < students.size(); ++i) {
        if (students[i].id == id) {
            cout << "Enter new Student Name: ";
            cin.ignore();
            getline(cin, students[i].name);
            cout << "Enter new Student Age: ";
            cin >> students[i].age;
            cout << "Enter new Student GPA: ";
            cin >> students[i].gpa;
            cout << "Student updated successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

// Delete Student
void deleteStudent() {
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;
    for (int i = 0; i < students.size(); ++i) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            cout << "Student deleted successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

// View Students
void viewStudents() {
    cout << "ID\tName\t\tAge\tGPA\n";
    for (int i = 0; i < students.size(); ++i) {
        cout << students[i].id << "\t" << students[i].name << "\t\t" << students[i].age << "\t" << students[i].gpa << "\n";
    }
}

// Add Teacher
void addTeacher() {
    Teacher newTeacher;
    cout << "Enter Teacher ID: ";
    cin >> newTeacher.id;
    cout << "Enter Teacher Name: ";
    cin.ignore();
    getline(cin, newTeacher.name);
    cout << "Enter Teacher Age: ";
    cin >> newTeacher.age;
    cout << "Enter Teacher Subject: ";
    cin.ignore();
    getline(cin, newTeacher.subject);
    teachers.push_back(newTeacher);
    cout << "Teacher added successfully.\n";
}

// Update Teacher
void updateTeacher() {
    int id;
    cout << "Enter Teacher ID to update: ";
    cin >> id;
    for (int i = 0; i < teachers.size(); ++i) {
        if (teachers[i].id == id) {
            cout << "Enter new Teacher Name: ";
            cin.ignore();
            getline(cin, teachers[i].name);
            cout << "Enter new Teacher Age: ";
            cin >> teachers[i].age;
            cout << "Enter new Teacher Subject: ";
            cin.ignore();
            getline(cin, teachers[i].subject);
            cout << "Teacher updated successfully.\n";
            return;
        }
    }
    cout << "Teacher not found.\n";
}

// Delete Teacher
void deleteTeacher() {
    int id;
    cout << "Enter Teacher ID to delete: ";
    cin >> id;
    for (int i = 0; i < teachers.size(); ++i) {
        if (teachers[i].id == id) {
            teachers.erase(teachers.begin() + i);
            cout << "Teacher deleted successfully.\n";
            return;
        }
    }
    cout << "Teacher not found.\n";
}

// View Teachers
void viewTeachers() {
    cout << "ID\tName\t\tAge\tSubject\n";
    for (int i = 0; i < teachers.size(); ++i) {
        cout << teachers[i].id << "\t" << teachers[i].name << "\t\t" << teachers[i].age << "\t" << teachers[i].subject << "\n";
    }
}

