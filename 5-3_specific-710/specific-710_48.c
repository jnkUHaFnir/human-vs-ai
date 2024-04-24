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
        perror("Error opening file\n");
        return 1;
    }

    int size;
    fscanf(file, "%d", &size);
    
    Diary* res = (Diary*)malloc(size * sizeof(Diary));
    if (res == NULL) {
        perror("Memory allocation failed\n");
        return 1;
    }

    char day[1024];
    char* token;
    int i = 0;

    // Skip the newline after reading the size
    fscanf(file, "%*[^\n]");

    while (fgets(day, 1024, file) != NULL) {
        token = strtok(day, "/");
        res[i].day = atoi(token);
        token = strtok(NULL, "/");
        res[i].month = atoi(token);
        token = strtok(NULL, "/");
        res[i].year = atoi(token);
        token = strtok(NULL, "\n");
        strcpy(res[i].entry, token);

        printf("%s", res[i].entry);
        i++;
    }

    // Print the stored entries
    for (int j = 0; j < size; j++) {
        printf("%d/%d/%d - %s\n", res[j].day, res[j].month, res[j].year, res[j].entry);
    }

    // Free dynamically allocated memory
    free(res);
    fclose(file);

    return 0;
}
