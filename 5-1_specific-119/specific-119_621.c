#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _SPerson {
    char *name;
    char *surname;
    char *id;
    char *telephone;
} SPerson;

int Load(SPerson Archive[], unsigned int *ne) {
    int i = 0;
    char line[100]; // Adjust the size accordingly
    char *token;

    FILE *f = fopen("archive.txt", "r");
    if (f == NULL) return 0;

    while (fgets(line, sizeof(line), f) != NULL) {
        token = strtok(line, " ");
        if(token != NULL) {
            Archive[i].id = (char*)malloc(strlen(token) + 1);
            strcpy(Archive[i].id, token);
        }

        token = strtok(NULL, " ");
        if (token != NULL) {
            Archive[i].name = (char*)malloc(strlen(token) + 1);
            strcpy(Archive[i].name, token);
        }

        token = strtok(NULL, " ");
        if (token != NULL) {
            Archive[i].surname = (char*)malloc(strlen(token) + 1);
            strcpy(Archive[i].surname, token);
        }

        token = strtok(NULL, " ");
        if (token != NULL) {
            Archive[i].telephone = (char*)malloc(strlen(token) + 1);
            strcpy(Archive[i].telephone, token);
        }

        i++;
    }

    *ne = i;
    fclose(f);
    return 1;
}

int main(void) {
    unsigned int ne;
    SPerson Archive[1000];
    if (Load(Archive, &ne)) {
        printf("Data loaded successfully.\n");
    } else {
        printf("Error loading data from file.\n");
    }

    return 0;
}
