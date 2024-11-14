#include <stdio.h>
#include "student.h"
#include "file_operations.h"

void loginStudent() {
    printf("login student...\n");
    // Logic to log in a student by checking students.csv
}

void viewPersonalInfo() {
    printf("view personal info...\n");
    // Logic for a student to view only their own info
}

void viewResult() {
    printf("view result...\n");
    // Logic for a student to view only their own result
}

void specialFeature() {
    printf("special Feature Coming soon...\n");
    // Reserved for future development
}

void studentPanel() {
    int choice;
    printf("\n====================== Student Panel ======================\n");
    do {
        printf("1. Login\n");
        printf("2. View Personal Info\n");
        printf("3. View Result\n");
        printf("4. Special Feature\n");
        printf("5. Logout\n");
        printf("=========================\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                loginStudent();
            break;
            case 2:
                viewPersonalInfo();
            break;
            case 3:
                viewResult();
            break;
            case 4:
                specialFeature();
            break;
            case 5:
                printf("Student Logging out...\n");
            return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}
