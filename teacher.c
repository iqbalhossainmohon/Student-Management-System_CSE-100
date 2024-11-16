#include <stdio.h>
#include <string.h>
#include "teacher.h"
#include "file_operations.h"


#define TEACHER_FILE "teacher.csv"
#define STUDENT_FILE "student.csv"
#define RESULT_FILE "results.csv"

int loggedIn = 0;

int teacherAuthenticate(const char *filename, const char *id, const char *name) {
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
            return 1;  // Authentication successful
        }
    }

    fclose(file);
    return 0;  // Authentication failed if no match is found
}

void loginTeacher() {
    //printf("login a new teacher...\n");

    char name[50], id[50];
    printf("Enter Your ID: ");
    scanf("%s", id);
    printf("Enter Teacher Name: ");
    scanf("%s", name);

    // Authenticate using the teacher's name and ID
    if (teacherAuthenticate(TEACHER_FILE, id, name)) {
        printf("Login successful! Welcome, %s\n", name);
        printf("\n");
        loggedIn = 1;  // Mark teacher as logged in
    } else {
        printf("Login failed. Invalid credentials.\n");
    }
}

void viewAllStudents() {
    //printf("view all students...\n");
    printf("=============== List of Student ===============\n");
    readFromFile(STUDENT_FILE);
    printf("\n");
}

void addStudentResult() {
    //printf("Add students Result...\n");
    char id[50], subject[50];
    float marks;

    printf("Enter Student ID: ");
    scanf("%s", id);
    printf("Enter Subject: ");
    scanf("%s", subject);
    printf("Enter Marks: ");
    scanf("%f", &marks);

    FILE *file = fopen(RESULT_FILE, "a");
    if (file == NULL) {
        perror("Error opening results file");
        return;
    }

    fprintf(file, "%s,%s,%.2f\n", id, subject, marks); // Save result as "id,subject,marks"
    fclose(file);

    printf("Result added successfully for Student ID %s.\n", id);
}

void viewAllResults() {
    //printf("view all student results...\n");
    printf("=============== View Student Result ===============\n");
    readFromFile(RESULT_FILE);
    printf("\n");
}

/* void updateStudentResult() {
    printf("update student result...\n");
    // Logic to update student results
} */

void teacherPanel() {
    int choice;
    printf("\n====================== Teacher Panel ======================\n");
    do {
        if(!loggedIn) {
            printf("1. Login\n");
            printf("2. Go Back\n");

            printf("=========================\n");
            printf("Select an option: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    loginTeacher();
                break;
                case 2:
                    return;
                default:
                    printf("Invalid choice! Please try again.\n");
            }
        }
        else {
            printf("3. View All Students\n");
            printf("4. Add Student Result\n");
            printf("5. View All Results\n");
            //printf("6. Update Student Result\n");
            printf("6. Logout\n");

            printf("=========================\n");
            printf("Select an option: ");
            scanf("%d", &choice);

            switch (choice){
                case 3:
                    viewAllStudents();
                break;
                case 4:
                    addStudentResult();
                break;
                case 5:
                    viewAllResults();
                break;

                //case 6:
                    updateStudentResult();
                break;

                case 6:
                    if (loggedIn) {
                        printf("Teacher logging out successful\n");
                        loggedIn = 0;
                    } else {
                        printf("You are not logged in.\n");
                    }
                return;
                default:
                    printf("Invalid choice! Please try again.\n");
            }
        }
    }
    while (choice != 6);
}
