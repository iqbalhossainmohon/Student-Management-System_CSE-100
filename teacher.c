#include <stdio.h>
#include <string.h>
#include "teacher.h"
#include "file_operations.h"


#define TEACHER_FILE "teacher.csv"
#define STUDENT_FILE "student.csv"
#define RESULT_FILE "results.csv"

int teacherLoggedIn = 0;

int teacherAuthenticate(const char *filename, const char *id, const char *name) {
    char line[256];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    while (fgets(line, sizeof(line), file)) {
        char stored_id[50], stored_name[50];

        sscanf(line, "%[^,],%[^,]", stored_id, stored_name);

        if (strcmp(id, stored_id) == 0 && strcmp(name, stored_name) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void loginTeacher() {
    char name[50], id[50];
    printf("Enter Teacher ID: ");
    scanf("%s", id);
    printf("Enter Teacher Name: ");
    scanf("%s", name);

    if (teacherAuthenticate(TEACHER_FILE, id, name)) {
        printf("Login successful! Welcome, %s\n", name);
        printf("\n");
        teacherLoggedIn = 1;  // Mark teacher as logged in
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
    char id[50];
    float subject01, subject02, subject03, subject04, subject05;
    //float marks;

    printf("Enter Student ID: ");
    scanf("%s", id);
    printf("Marks of the 1st subject: ");
    scanf("%f", &subject01);
    printf("Marks of the 2nd subject: ");
    scanf("%f", &subject02);
    printf("Marks of the 3rd subject: ");
    scanf("%f", &subject03);
    printf("Marks of the 4th subject: ");
    scanf("%f", &subject04);
    printf("Marks of the 5th subject: ");
    scanf("%f", &subject05);

    FILE *file = fopen(RESULT_FILE, "a");
    if (file == NULL) {
        perror("Error opening results file");
        return;
    }

    fprintf(file, "%s,%.2f,%.2f,%.2f,%.2f,%.2f\n", id, subject01, subject02, subject03, subject04, subject05);
    fclose(file);

    printf("Result added successfully for Student ID %s.\n", id);
    printf("\n");
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
    printf("\n================= Teacher Panel =================\n");
    do {
        if(!teacherLoggedIn) {
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
                  //  updateStudentResult();
               // break;

                case 6:
                    if (teacherLoggedIn) {
                        printf("Teacher logging out successful\n\n");
                        teacherLoggedIn = 0;
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
    //while (choice != 7);
}
