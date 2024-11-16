#include <stdio.h>
#include <string.h>
#include "student.h"
#include "file_operations.h"


#define STUDENT_FILE "student.csv"
#define RESULT_FILE "results.csv"


int studentLoggedIn = 0;

int studentAuthenticate(const char *filename, const char *id, const char *name) {
    char line[256];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    while (fgets(line, sizeof(line), file)) {
        char stored_id[50], stored_name[50];
        // Parse line: "id,name"
        sscanf(line, "%[^,],%[^,]", stored_id, stored_name);

        if (strcmp(id, stored_id) == 0 && strcmp(name, stored_name) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

void loginStudent() {
    char name[50], id[50];
    printf("Enter Student ID: ");
    scanf("%s", id);
    printf("Enter Student Name: ");
    scanf("%s", name);

    if (studentAuthenticate(STUDENT_FILE, id, name)) {
        printf("Login successful! Welcome, %s\n", name);
        printf("\n");
        studentLoggedIn = 1;
    } else {
        printf("Login failed. Invalid credentials.\n");
    }
}

void viewPersonalInfo() {
    // Logic for a student to view only their own info
   printf("=============== List of Student ===============\n");
    readFromFile(STUDENT_FILE);
    printf("\n");
}

void viewResult() {
    // Logic for a student to view only their own result
    printf("=============== List of Result ===============\n");
    readFromFile(RESULT_FILE);
    printf("\n");
}


/// Special Feature
void specialFeature() {
    printf("special Feature Coming soon...\n");
    // Reserved for future development
}

void studentPanel() {
    int choice;
    printf("\n====================== Student Panel ======================\n");
    do {
        if(!studentLoggedIn) {
            printf("1. Login\n");
            printf("2. Go Back\n");

            printf("=========================\n");
            printf("Select an option: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    loginStudent();
                break;
                case 2:
                    return;
                default:
                    printf("Invalid choice! Please try again.\n");
            }
        }
        else {
            printf("3. View Students Info\n");
            printf("4. View Result\n");
            printf("5. Special Feature\n");
            printf("6. Logout\n");

            printf("=========================\n");
            printf("Select an option: ");
            scanf("%d", &choice);

            switch (choice){
                case 3:
                    viewPersonalInfo();
                break;
                case 4:
                    viewResult();
                break;
                case 5:
                    specialFeature();
                break;
                case 6:

                    if (studentLoggedIn) {
                        printf("Student logging out successful\n\n");
                        studentLoggedIn = 0;
                    } else {
                        printf("You are not logged in.\n");
                    }
                return;
                default:
                    printf("Invalid choice! Please try again.\n");
            }
        }
    } while (choice != 6);
}
