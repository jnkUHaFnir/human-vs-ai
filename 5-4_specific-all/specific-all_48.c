#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct journal {
    int day;
    int month;
    int year;
    char entry[1024];
} Diary;

int main() {
    FILE* file = fopen("struct.txt", "r");

    if (file == NULL) {
        perror("Error opening file.\n");
        return 1;
    }

    int size;
    fscanf(file, "%d", &size);
    Diary* res = malloc(size * sizeof(Diary));

    char line[1024];
    int i = 0;

    while (fgets(line, sizeof(line), file) != NULL && i < size) {
        char* token = strtok(line, "/");
        res[i].day = atoi(token);

        token = strtok(NULL, "/");
        res[i].month = atoi(token);

        token = strtok(NULL, "\n");
        res[i].year = atoi(token);

        fgets(line, sizeof(line), file); // Read the entry line
        line[strcspn(line, "\n")] = 0;   // Remove newline char

        strncpy(res[i].entry, line, sizeof(res[i].entry) - 1);
        res[i].entry[sizeof(res[i].entry) - 1] = '\0'; // Ensure null-terminated

        printf("%d/%d/%d - %s\n", res[i].day, res[i].month, res[i].year, res[i].entry);

        i++;
    }

    fclose(file);

    // Use the res array of Diary structs here

    // Don't forget to free the dynamically allocated memory after use
    free(res);

    return 0;
}
