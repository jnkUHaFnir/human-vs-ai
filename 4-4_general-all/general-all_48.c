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
        perror("Error opening file.");
        return 1;
    }

    int size;
    fscanf(file, "%d", &size);
    Diary* res = (Diary*)malloc(size * sizeof(Diary));

    char line[1024]; // Buffer to read each line
    int i = 0;

    // Read the first line and discard it
    fscanf(file, "%*[^\n]");
    fscanf(file, "%*c");

    while (fgets(line, 1024, file) != NULL && i < size) {
        char* token = strtok(line, "/\n");
        res[i].day = atoi(token);
        token = strtok(NULL, "/");
        res[i].month = atoi(token);
        token = strtok(NULL, "/");
        res[i].year = atoi(token);

        // Read the rest of the line as the entry
        fgets(line, 1024, file);
        strcpy(res[i].entry, line);
        
        i++;
    }

    // Display the stored entries
    for (int j = 0; j < size; j++) {
        printf("%d/%d/%d - %s", res[j].day, res[j].month, res[j].year, res[j].entry);
    }

    fclose(file);
    free(res);

    return 0;
}
