#include <stdio.h>
#include <string.h>
#include "admin.h"
#include "file_operations.h"

// File paths
#define ADMIN_FILE "admin.csv"
#define TEACHER_FILE "teacher.csv"
#define STUDENT_FILE "student.csv"
#define COURSE_FILE "course.csv"

// Admin registration function
void registerAdmin() {
    char fname[50], lname[50], email[50], gender[10], username[50], password[50];
    printf("Enter First Name: ");
    scanf("%s", fname);
    printf("Enter Last Name: ");
    scanf("%s", lname);
    printf("Enter Email: ");
    scanf("%s", email);
    printf("Enter Gender: ");
    scanf("%s", gender);
    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);

    char data[256];
    snprintf(data, sizeof(data), "%s,%s,%s,%s,%s,%s", fname, lname, email, gender, username, password);
    writeToFile(ADMIN_FILE, data);
    printf("\nAdmin registered successfully!\n");
}

// Admin login function
int loginAdmin() {
    char email[50], password[50];
    printf("Enter Email: ");
    scanf("%s", email);
    printf("Enter Password: ");
    scanf("%s", password);

    if (authenticate(ADMIN_FILE, email, password)) {
        printf("\nLogin successful! ");
        printf("Well Come, %s\n", email);
        return 1;
    } else {
        printf("Login failed. Invalid credentials.\n");
        return 0;
    }
}

// Manage teachers
void manageTeachers() {
    int choice;
    printf("===================== Manage Teachers =====================\n");
    do {
        printf("1. Add Teacher\n");
        printf("2. View Teachers\n");
        printf("3. Update Teacher\n");
        printf("4. Delete Teacher\n");
        printf("5. Go Back\n");
        printf("=========================\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                addTeacher();
                break;
            case 2:
                viewTeachers();
                break;
            case 3:
                updateTeacher();
                break;
            case 4:
                deleteTeacher();
                break;
            case 5:
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

// Manage students
void manageStudents() {
    int choice;
    printf("===================== Manage Students =====================\n");
    do {
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Go Back\n");
        printf("=========================\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

// Manage courses
void manageCourses() {
    int choice;
    printf("===================== Manage Courses =====================\n");
    do {
        printf("1. Assign Courses to Teacher\n");
        printf("2. View Assigned Courses\n");
        printf("3. Go Back\n");
        printf("=========================\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                assignCourse();
                break;
            case 2:
                viewAssignedCourses();
                break;
            case 3:
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);
}


void adminPanel() {
    int choice;
    int isLoggedIn = 0;

    printf("\n================= Admin Panel =================\n");
    do {
        if (!isLoggedIn) {
            printf("1. Register\n");
            printf("2. Login\n");
            printf("3. Exit\n");
            printf("=======================================\n");
            printf("Select an option: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    registerAdmin();
                break;
                case 2:
                    isLoggedIn = loginAdmin();
                break;
                case 3:
                    printf("Exiting admin panel...\n");
                return;
                default:
                    printf("Invalid choice! Please try again.\n");
            }
        } else {
            printf("1. Manage Teachers\n");
            printf("2. Manage Students\n");
            printf("3. Manage Courses\n");
            printf("4. Logout\n");
            printf("=======================\n");
            printf("Select an option: ");
            scanf("%d", &choice);
            printf("\n");

            switch (choice) {
                case 1:
                    manageTeachers();
                break;
                case 2:
                    manageStudents();
                break;
                case 3:
                    manageCourses();
                break;
                case 4:
                    printf("Logging out...\n");
                isLoggedIn = 0;
                break;
                default:
                    printf("Invalid choice! Please try again.\n");
            }
        }
    } while (choice != 4 || isLoggedIn);
}



/// Teacher
void addTeacher() {
    char id[50], name[50], department[50], phone[20], gender[15];
    printf("Enter Teacher ID: ");
    scanf("%s", id);
    printf("Enter Teacher Name: ");
    scanf("%s", name);
    printf("Enter Department: ");
    scanf("%s", department);

    printf("Enter Phone Number: ");
    scanf("%s", phone);
    printf("Enter Gender: ");
    scanf("%s", gender);

    char data[256];
    snprintf(data, sizeof(data), "%s,%s,%s,%s,%s", id, name, department, phone, gender);
    writeToFile(TEACHER_FILE, data);
    printf("Teacher added successfully!\n\n");
}

void viewTeachers() {
    printf("=============== List of Teachers ===============\n");
    readFromFile(TEACHER_FILE);
    printf("\n");
}

void updateTeacher() {
    char id[10];
    printf("Enter Teacher ID to Update: ");
    scanf("%s", id);

    char name[50], department[50], phone[20], gender[15];
    printf("Enter Update Name: ");
    scanf("%s", name);
    printf("Enter Update Department: ");
    scanf("%s", department);
    printf("Enter Update Phone: ");
    scanf("%s", phone);
    printf("Enter Update Gender: ");
    scanf("%s", gender);

    char newData[256];
    snprintf(newData, sizeof(newData), "%s,%s,%s,%s,%s", id, name, department, phone, gender);
    updateFile(TEACHER_FILE, id, newData);
    //printf("Teacher updated successfully!\n");
}

void deleteTeacher() {
    char id[10];
    printf("Enter Teacher ID to delete: ");
    scanf("%s", id);
    deleteFromFile(TEACHER_FILE, id);
    //printf("Teacher deleted successfully!\n");
}


/// Student
void addStudent() {
    char id[10], name[50], department[50], age[10], phone[20], gender[15];
    printf("Enter Student ID: ");
    scanf("%s", id);
    printf("Enter Student Name: ");
    scanf("%s", name);
    printf("Enter Department: ");
    scanf("%s", department);

    printf("Enter Age: ");
    scanf("%s", age);
    printf("Enter Phone Number: ");
    scanf("%s", phone);
    printf("Enter Gender: ");
    scanf("%s", gender);

    char data[256];
    snprintf(data, sizeof(data), "%s,%s,%s,%s,%s,%s", id, name, department,age, phone, gender);
    writeToFile(STUDENT_FILE, data);
    printf("\nStudent added successfully!\n");
}

void viewStudents() {
    printf("================ List of Students ================\n");
    readFromFile(STUDENT_FILE);
    printf("\n");
}

void updateStudent() {
    char id[10];
    printf("Enter Student ID to update: ");
    scanf("%s", id);

    char name[50], department[50], age[10], phone[20], gender[15];
    printf("Enter Update Name: ");
    scanf("%s", name);
    printf("Enter Update Department: ");
    scanf("%s", department);
    printf("Enter Update Age: ");
    scanf("%s", age);
    printf("Enter Update Phone: ");
    scanf("%s", phone);
    printf("Enter Update Gender: ");
    scanf("%s", gender);

    char newData[256];
    snprintf(newData, sizeof(newData), "%s,%s,%s,%s,%s,%s", id, name, department, age, phone, gender);
    updateFile(STUDENT_FILE, id, newData);
    //printf("Student updated successfully!\n");
}

void deleteStudent() {
    char id[10];
    printf("Enter Student ID to delete: ");
    scanf("%s", id);
    deleteFromFile(STUDENT_FILE, id);
    //printf("Student deleted successfully!\n");
}

/// Course
void assignCourse() {
    char teacherId[50], course01[50], course02[50], course03[50], course04[50], course05[50];
    printf("Enter Teacher ID: ");
    scanf("%s", teacherId);
    printf("Enter Course 01: ");
    scanf("%s", course01);
    printf("Enter Course 02: ");
    scanf("%s", course02);
    printf("Enter Course 03: ");
    scanf("%s", course03);
    printf("Enter Course 04: ");
    scanf("%s", course04);
    printf("Enter Course 05: ");
    scanf("%s", course05);

    char data[256];
    snprintf(data, sizeof(data), "%s,%s,%s,%s,%s,%s", teacherId, course01, course02, course03, course04, course05);
    writeToFile(COURSE_FILE, data);
    printf("Course assigned successfully!\n\n");
}

void viewAssignedCourses() {
    printf("============ List of Assigned Courses Teacher ============\n");
    readFromFile(COURSE_FILE);
    printf("\n");
}