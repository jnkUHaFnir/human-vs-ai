#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _SPerson {
  char *name;
  char *surname;
  char *id;
  char *telephone;
} SPerson;

void splitString(char *input, char *output[], int size, const char *delimiter) {
    char *token = strtok(input, delimiter);
    int i = 0;
    while (token != NULL && i < size) {
        output[i++] = token;
        token = strtok(NULL, delimiter);
    }
}

int Load(SPerson Archive[], unsigned int *ne) {
    int i = 0;
    char line[256]; // Assuming a maximum line length of 255 characters
    FILE *f = fopen("archive.txt", "r");
    if (f == NULL) return 0;

    while (fgets(line, sizeof(line), f) != NULL) {
        char *tokens[4]; // Assuming each line has 4 tokens
        splitString(line, tokens, 4, " ");

        Archive[i].id = strdup(tokens[0]);
        Archive[i].name = strdup(tokens[1]);
        Archive[i].surname = strdup(tokens[2]);
        Archive[i].telephone = strdup(tokens[3]);

        i++;
    }

    *ne = i;
    fclose(f);
    return 1;
}

int main() {
    unsigned int ne;
    SPerson Archive[1000];
    int result = Load(Archive, &ne);

    if (result == 1) {
        for (int i = 0; i < ne; i++) {
            printf("ID: %s, Name: %s, Surname: %s, Telephone: %s\n", Archive[i].id, Archive[i].name, Archive[i].surname, Archive[i].telephone);
        }
    } else {
        printf("Error loading data from file.\n");
    }

    return 0;
}
