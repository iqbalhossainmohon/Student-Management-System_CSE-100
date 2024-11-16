#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_operations.h"


int authenticate(const char *filename, const char *username, const char *password) {
    char line[256];
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }
    while (fgets(line, sizeof(line), file)) {
        char stored_email[50], stored_password[50];
        sscanf(line, "%*[^,],%*[^,],%[^,],%*[^,],%*[^,],%s", stored_email, stored_password);
        if (strcmp(username, stored_email) == 0 && strcmp(password, stored_password) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}


void writeToFile(const char* filename, const char* data) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(file, "%s\n", data);
    fflush(file);  // Ensure data is written immediately
    fclose(file);
}

void readFromFile(const char* filename) {
    char line[256];
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void updateFile(const char* filename, const char* id, const char* newData) {
    FILE* file = fopen(filename, "r");
    FILE* tempFile = fopen("temp.csv", "w");
    char line[256];
    int found = 0;

    if (file == NULL || tempFile == NULL) {
        perror("Error opening file");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        char lineId[10];
        sscanf(line, "%[^,]", lineId);
        if (strcmp(lineId, id) == 0) {
            fprintf(tempFile, "%s\n", newData);
            found = 1;
        } else {
            fprintf(tempFile, "%s", line);
        }
    }

    fclose(file);
    fclose(tempFile);
    remove(filename);
    rename("temp.csv", filename);

    if (found) {
        printf("Record updated successfully.\n\n");
    } else {
        printf("Record not found.\n\n");
    }
}

void deleteFromFile(const char* filename, const char* id) {
    FILE* file = fopen(filename, "r");
    FILE* tempFile = fopen("temp.csv", "w");
    char line[256];
    int found = 0;

    if (file == NULL || tempFile == NULL) {
        perror("Error opening file");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        char lineId[10];
        sscanf(line, "%[^,]", lineId);
        if (strcmp(lineId, id) != 0) {
            fprintf(tempFile, "%s", line);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);
    remove(filename);
    rename("temp.csv", filename);

    if (found) {
        printf("Record deleted successfully.\n");
        printf("\n");
    } else {
        printf("Record not found.\n");
        printf("\n");
    }
}
