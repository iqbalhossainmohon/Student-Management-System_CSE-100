#include <stdio.h>
#include "teacher.h"
#include "file_operations.h"

void loginTeacher() {
    printf("login a new teacher...\n");
    // Logic to log in a teacher by checking teachers.csv
}

void viewAllStudents() {
    printf("view all students...\n");
    // Logic to view all students
}

void addStudentResult() {
    // Logic to add results for students
}

void viewAllResults() {
    printf("view all student results...\n");
    // Logic to view all results for students
}

void updateStudentResult() {
    printf("update student result...\n");
    // Logic to update student results
}

void teacherPanel() {
    int choice;
    printf("\n====================== Teacher Panel ======================\n");
    do {
        printf("1. Login\n");
        printf("2. View All Students\n");
        printf("3. Add Student Result\n");
        printf("4. View All Results\n");
        printf("5. Update Student Result\n");
        printf("6. Logout\n");
        printf("=========================\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                loginTeacher();
            break;
            case 2:
                viewAllStudents();
            break;
            case 3:
                addStudentResult();
            break;
            case 4:
                viewAllResults();
            break;
            case 5:
                updateStudentResult();
            break;
            case 6:
                printf("Teacher Logging out...\n");
            return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
}
