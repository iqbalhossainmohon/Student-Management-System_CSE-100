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

// Student login
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
    printf("=============== List of Student Result ===============\n");
    readFromFile(RESULT_FILE);
    printf("\n");
}






/// Special Feature
void displayCampusMap(int start, int end) {
    char route[256] = ""; // To store the route
    int distance = 0;

    if (start == 1 && end == 2) {
        strcpy(route, "Anti Gate -> Admission Section");
        distance = 5;
    }
    else if (start == 1 && end == 3) {
        strcpy(route, "Anti Gate -> Admission Section -> Library");
        distance = 15;
    }
    else if (start == 1 && end == 4) {
        strcpy(route, "Anti Gate -> Admission Section -> Library -> Computer Lab");
        distance = 35;
    }
    else if (start == 1 && end == 5) {
        strcpy(route, "Anti Gate -> Admission Section -> Library -> Computer Lab -> Cafeteria");
        distance = 45;
    }
    else if (start == 1 && end == 6) {
        strcpy(route, "Anti Gate -> Admission Section -> Library -> Computer Lab -> Cafeteria -> CSC Department");
        distance = 57;
    }
    else if (start == 2 && end == 3) {
        strcpy(route, "Admission Section -> Library");
        distance = 10;
    }
    else if (start == 2 && end == 4) {
        strcpy(route, "Admission Section -> Library -> Computer Lab");
        distance = 25;
    }
    else if (start == 2 && end == 5) {
        strcpy(route, "Admission Section -> Library -> Computer Lab -> Cafeteria");
        distance = 35;
    }
    else if (start == 2 && end == 6) {
        strcpy(route, "Admission Section -> Library -> Computer Lab -> Cafeteria -> CSC Department");
        distance = 47;
    }
    else if (start == 3 && end == 4) {
        strcpy(route, "Library -> Computer Lab");
        distance = 15;
    }
    else if (start == 3 && end == 5) {
        strcpy(route, "Library -> Computer Lab -> Cafeteria");
        distance = 25;
    }
    else if (start == 3 && end == 6) {
        strcpy(route, "Library -> Computer Lab -> Cafeteria -> CSC Department");
        distance = 37;
    }
    else if (start == 4 && end == 5) {
        strcpy(route, "Computer Lab -> Cafeteria");
        distance = 8;
    }
    else if (start == 4 && end == 6) {
        strcpy(route, "Computer Lab -> Cafeteria -> CSC Department");
        distance = 20;
    }
    else if (start == 5 && end == 6) {
        strcpy(route, "Cafeteria -> CSC Department");
        distance = 12;
    }
    else {
        printf("Invalid route!\n");
        return;
    }

    // Displaying the route and distance
    printf("\nYou are at: ");
    switch (start) {
        case 1: printf("Anti Gate\n"); break;
        case 2: printf("Admission Section\n"); break;
        case 3: printf("Library\n"); break;
        case 4: printf("Computer Lab\n"); break;
        case 5: printf("Cafeteria\n"); break;
        case 6: printf("CSC Department\n"); break;
    }

    printf("You want to go to: ");
    switch (end) {
        case 1: printf("Anti Gate\n"); break;
        case 2: printf("Admission Section\n"); break;
        case 3: printf("Library\n"); break;
        case 4: printf("Computer Lab\n"); break;
        case 5: printf("Cafeteria\n"); break;
        case 6: printf("CSC Department\n"); break;
    }

    printf("\nRoute Map: %s\n", route);
    printf("Total Distance: %d meters\n\n", distance);
}


/// Special Feature Function
void specialFeature() {

    int start, end;

    printf("\n========== Campus Navigation System ==========\n\n");
    printf("Select your current location\n");
    printf("1. Anti Gate\n");
    printf("2. Admission Section\n");
    printf("3. Library\n");
    printf("4. Computer Lab\n");
    printf("5. Cafeteria\n");
    printf("6. CSC Department\n");
    printf("Enter your location (1-6): ");
    scanf("%d", &start);

    printf("\nSelect your destination\n");
    printf("1. Anti Gate\n");
    printf("2. Admission Section\n");
    printf("3. Library\n");
    printf("4. Computer Lab\n");
    printf("5. Cafeteria\n");
    printf("6. CSC Department\n");
    printf("Enter your destination (1-6): ");
    scanf("%d", &end);

    displayCampusMap(start, end);

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
            printf("1. View Students Info\n");
            printf("2. View Result\n");
            printf("3. Special Feature\n");
            printf("4. Logout\n");

            printf("=========================\n");
            printf("Select an option: ");
            scanf("%d", &choice);

            switch (choice){
                case 1:
                    viewPersonalInfo();
                break;
                case 2:
                    viewResult();
                break;
                case 3:
                    specialFeature();
                break;
                case 4:

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
    } while (choice != 4);
}
