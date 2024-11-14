#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

int authenticate(const char *filename, const char *username, const char *password);
void writeToFile(const char* filename, const char* data);
void readFromFile(const char* filename);
void updateFile(const char* filename, const char* id, const char* newData);
void deleteFromFile(const char* filename, const char* id);

#endif
