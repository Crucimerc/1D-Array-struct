#include <iostream>
using namespace std;

struct Student {
int id;
string firstName;
string lastName;
string course;
double gpa;
};

Student p[100];
int studentCount = 0;

void addStudent() {
cout << "Enter Student ID: ";
cin >> p[studentCount].id;

cout << "Enter First Name: ";
cin >> p[studentCount].firstName;

cout << "Enter Last Name: ";
cin >> p[studentCount].lastName;

cout << "Enter Course: ";
cin >> p[studentCount].course;

cout << "Enter GPA: ";
cin >> p[studentCount].gpa;

studentCount++;
cout << "Student added successfully!\n";
}

void editStudent() {
if (studentCount == 0) {
   cout << "No student records available.\n";
return;
}

int searchID;
cout << "Enter Student ID to edit: ";
cin >> searchID;

for (int i = 0; i < studentCount; i++) {
    if (p[i].id == searchID) {
     cout << "Editing student: " << p[i].firstName << " " << p[i].lastName << "\n";
     cout << "Enter New First Name: ";
     cin >> p[i].firstName;
     cout << "Enter New Last Name: ";
     cin >> p[i].lastName;
     cout << "Enter New Course: ";
     cin >> p[i].course;
     cout << "Enter New GPA: ";
     cin >> p[i].gpa;
     cout << "Student record updated successfully!\n";
     return;
     }
    }
cout << "Student ID not found.\n";
}

void deleteStudent() {
    if (studentCount == 0) {
     cout << "No student records available.\n";
     return;
    }

    int searchID;
    cout << "Enter Student ID to delete: ";
    cin >> searchID;

    for (int i = 0; i < studentCount; i++) {
    if (p[i].id == searchID) {
       for (int j = i; j < studentCount - 1; j++) {
            p[j] = p[j + 1]; 
       }
       studentCount--;
    cout << "Student deleted successfully!\n";
    return;
    }
    }
    cout << "Student ID not found.\n";
}

void sortAlphabetically() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = i + 1; j < studentCount; j++) {
            if (p[i].lastName > p[j].lastName) {
                Student temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    cout << "Students sorted alphabetically.\n" << endl;
}

void sortGPA() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = i + 1; j < studentCount; j++) {
            if (p[i].gpa > p[j].gpa) {
                Student temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    cout << "Students sorted by GPA in ascending order.\n" << endl;
}

void viewStudents() {
    if (studentCount == 0) {
        cout << "No student records available.\n";
        return;
    }

    int choice;
    cout << "View options:\n";
    cout << "[1] Alphabetically\n";
    cout << "[2] By GPA\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        sortAlphabetically();
    } else if (choice == 2) {
        sortGPA();
    } else {
        cout << "Invalid choice.\n";
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        cout << "ID: " << p[i].id;
        cout << ", Name: " << p[i].firstName << " " << p[i].lastName;
        cout << ", Course: " << p[i].course;
        cout << ", GPA: " << p[i].gpa << "\n";
    }
}
//Sir di ko ma system clear kase sa phone ko lng po ginawa
int main() {
int choice;
do {
cout << "\nMenu\n";
cout << "[1] Add Student\n";
cout << "[2] Edit Student\n";
cout << "[3] Delete Student\n";
cout << "[4] View Students\n";
cout << "[5] Exit Program\n";
cout << "Enter choice: ";
cin >> choice;
cout << endl;

switch (choice) {
case 1: addStudent(); break;
case 2: editStudent(); break;
case 3: deleteStudent(); break;
case 4: viewStudents(); break;
case 5: return 0;
default: cout << "Invalid choice. Try again.\n";
 }
 } while(choice != 5);
}
    