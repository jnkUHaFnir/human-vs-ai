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
    int i = 0, size;
    FILE* file = fopen("struct.txt", "r");
    
    if (file == NULL) {
        perror("Error opening file.\n");
        return 1;
    }

    fscanf(file, "%d", &size);
    Diary* res = (Diary*)malloc(size * sizeof(Diary));

    while (fscanf(file, "%d/%d/%d", &res[i].day, &res[i].month, &res[i].year) == 3) {
        fgetc(file); // Consume the space after the date
        fgets(res[i].entry, sizeof(res[i].entry), file);
        res[i].entry[strcspn(res[i].entry, "\n")] = '\0'; // remove the newline character
        i++;
    }

    fclose(file);

    // Print the entries to verify they are correctly stored
    for (int j = 0; j < size; j++) {
        printf("%d/%d/%d - %s\n", res[j].day, res[j].month, res[j].year, res[j].entry);
    }

    // Don't forget to free the dynamically allocated memory
    free(res);

    return 0;
}
