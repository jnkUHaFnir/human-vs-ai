#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _SPerson {
    char *name;
    char *surname;
    char *id;
    char *telephone;
} SPerson;

void split(char *str, char *str_parts[]) {
    char *token = strtok(str, " ");
    int i = 0;
    
    while (token != NULL) {
        str_parts[i++] = token;
        token = strtok(NULL, " ");
    }
}

int Load(SPerson Archive[], unsigned int *ne) {
    int i = 0;
    char line[100];
    char *parts[4];
    FILE *f;

    f = fopen("archive.txt", "r");
    if (f == NULL) return 0;

    while (fgets(line, sizeof(line), f) != NULL) {
        line[strcspn(line, "\n")] = 0; // Remove newline character
        
        split(line, parts);

        Archive[i].id = strdup(parts[0]);
        Archive[i].name = strdup(parts[1]);
        Archive[i].surname = strdup(parts[2]);
        Archive[i].telephone = strdup(parts[3]);

        i++;
    }

    *ne = i;
    fclose(f);
    return 1;
}

int main(void) {
    unsigned int ne;
    SPerson Archive[1000];
    Load(Archive, &ne);

    // Test printing loaded data
    for (int i = 0; i < ne; i++) {
        printf("id: %s, name: %s, surname: %s, telephone: %s\n",
               Archive[i].id, Archive[i].name, Archive[i].surname, Archive[i].telephone);
    }

    // Don't forget to free dynamically allocated memory
    for (int i = 0; i < ne; i++) {
        free(Archive[i].id);
        free(Archive[i].name);
        free(Archive[i].surname);
        free(Archive[i].telephone);
    }

    return 0;
}
