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

    char day[1024];
    int i = 0;

    while (fgets(day, 1024, file) != NULL) {
        char* token = strtok(day, "/");
        res[i].day = atoi(token);
        token = strtok(NULL, "/");
        res[i].month = atoi(token);
        token = strtok(NULL, "\n");
        res[i].year = atoi(token);

        fgets(day, 1024, file);
        day[strcspn(day, "\n")] = '\0'; // Remove new line character
        
        strncpy(res[i].entry, day, sizeof(res[i].entry) - 1);
        res[i].entry[sizeof(res[i].entry) - 1] = '\0'; // Add null terminator

        i++;
    }

    // Print the stored entries for verification
    for (int j = 0; j < size; j++) {
        printf("%d/%d/%d - %s\n", res[j].day, res[j].month, res[j].year, res[j].entry);
    }

    fclose(file);
    free(res);

    return 0;
}
