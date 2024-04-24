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

    char line[1024];
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d/%d/%d", &res[i].day, &res[i].month, &res[i].year);
        fgets(line, sizeof(line), file);
        line[strcspn(line, "\n")] = 0; // Remove newline character
        strcpy(res[i].entry, line);
    }

    // Print the stored entries
    for (int i = 0; i < size; i++) {
        printf("%d/%02d/%d - %s\n", res[i].day, res[i].month, res[i].year, res[i].entry);
    }

    fclose(file);
    free(res);

    return 0;
}
