#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
    char entry[1024];
} Diary;

int main() {
    FILE *file = fopen("struct.txt", "r");
    if (file == NULL) {
        perror("Error opening file.");
        return 1;
    }

    int size;
    fscanf(file, "%d", &size);
    Diary *res = (Diary*)malloc(size * sizeof(Diary));

    char line[1024];
    char *token;

    // Consume the newline character after reading size
    fscanf(file, "%*[^\n]");
    fgetc(file);

    int i = 0;
    while (i < size && fgets(line, sizeof(line), file) != NULL) {
        token = strtok(line, "/");
        res[i].day = atoi(token);

        token = strtok(NULL, "/");
        res[i].month = atoi(token);

        token = strtok(NULL, "\n");
        res[i].year = atoi(token);

        fgets(line, sizeof(line), file); // Read the entry
        line[strcspn(line, "\n")] = 0; // Remove newline character
        strcpy(res[i].entry, line);

        i++;
    }

    // Other actions with the struct array

    // Free dynamically allocated memory
    free(res);

    // Close the file
    fclose(file);

    return 0;
}
