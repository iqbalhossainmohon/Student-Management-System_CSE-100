#include <stdio.h>
#include "admin.h"
#include "teacher.h"
#include "student.h"

void displayMainMenu() {
    printf("========= Student Management System =========\n");
    printf("1. Admin Panel\n");
    printf("2. Teachers Panel\n");
    printf("3. Students Panel\n");
    printf("4. Exit\n");
    printf("=============================================\n");
}

int main() {
    int choice;
    do {
        displayMainMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                adminPanel();
            break;
            case 2:
                teacherPanel();
            break;
            case 3:
                studentPanel();
            break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
            break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}
