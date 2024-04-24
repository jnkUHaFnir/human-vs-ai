#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _SPerson {
    char *name;
    char *surname;
    char *id;
    char *telephone;
} SPerson;

void Load(SPerson Archive[], unsigned int *ne);
char **splitString(const char *str, const char *delimiter, int *numTokens);

int main(void) {
    unsigned int ne;
    SPerson Archive[1000];
    Load(Archive, &ne);

    // Test: Print loaded data
    for (int i = 0; i < ne; i++) {
        printf("Person %d:\nID: %s\nName: %s\nSurname: %s\nTelephone: %s\n\n",
               i + 1, Archive[i].id, Archive[i].name, Archive[i].surname, Archive[i].telephone);
    }

    return 0;
}

void Load(SPerson Archive[], unsigned int *ne) {
    int i = 0;
    char line[256]; // Adjust this size as needed
    FILE *f = fopen("archive.txt", "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fgets(line, sizeof(line), f)) {
        int numTokens;
        char **tokens = splitString(line, " ", &numTokens);

        if (numTokens >= 4) {
            Archive[i].id = strdup(tokens[0]);
            Archive[i].name = strdup(tokens[1]);
            Archive[i].surname = strdup(tokens[2]);
            Archive[i].telephone = strdup(tokens[3]);
            i++;
        }

        // Free memory allocated for tokens
        for (int j = 0; j < numTokens; j++) {
            free(tokens[j]);
        }
        free(tokens);
    }

    *ne = i;
    fclose(f);
}

char **splitString(const char *str, const char *delimiter, int *numTokens) {
    char **tokens = NULL;
    *numTokens = 0;
    const char *token = strtok(str, delimiter);

    while (token) {
        tokens = (char **)realloc(tokens, sizeof(char *) * (*numTokens + 1));
        tokens[*numTokens] = strdup(token);
        (*numTokens)++;
        token = strtok(NULL, delimiter);
    }

    return tokens;
}
