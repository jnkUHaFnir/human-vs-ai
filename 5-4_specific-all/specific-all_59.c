#include <stdio.h>
#include <string.h>

int main() {
    char* name[2];
    char inputName[10];

    for (int i = 0; i < 2; i++) {
        fgets(inputName, sizeof(inputName), stdin);
        char* pos = strchr(inputName, '\n');
        if (pos != NULL)
            *pos = '\0';

        name[i] = malloc(strlen(inputName) + 1);
        if (name[i] != NULL) {
            strcpy(name[i], inputName);
        }
    }

    printf("%s\n", name[0]);
    printf("%s\n", name[1]);

    // Don't forget to free the dynamically allocated memory
    for (int i = 0; i < 2; i++) {
        free(name[i]);
    }

    return 0;
}
``` 

This code dynamically allocates memory for each string entered by the user and copies the content into those dynamically allocated buffers to ensure that each string has its own separate memory space.
