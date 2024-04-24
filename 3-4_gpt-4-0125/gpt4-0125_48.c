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
    FILE *file = fopen("struct.txt", "r");
    int size, i;
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    fscanf(file, "%d\n", &size); // Read the number of entries.
    Diary *res = (Diary*)malloc(size * sizeof(Diary)); // Dynamically allocate array of structs.
    
    for (i = 0; i < size; i++) {
        int day, month, year;
        // Read the date.
        fscanf(file, "%d/%d/%d\n", &day, &month, &year);
        res[i].day = day;
        res[i].month = month;
        res[i].year = year;
        
        // Read the journal entry.
        // Using fgets to read until newline and storing directly into struct.
        if (fgets(res[i].entry, 1024, file) == NULL) {
            fprintf(stderr, "Error reading journal entry for date %02d/%02d/%d\n", day, month, year);
            // Free allocated memory and exit if read fails.
            free(res);
            fclose(file);
            return 1;
        }
        
        // Optionally, trim the newline character at the end of the entry, if present.
        res[i].entry[strcspn(res[i].entry, "\n")] = 0;
    }

    // Demo: Print the entire diary to verify.
    for (i = 0; i < size; i++) {
        printf("Date: %02d/%02d/%d\nEntry: %s\n\n", res[i].day, res[i].month, res[i].year, res[i].entry);
    }
    
    // Cleanup
    free(res);
    fclose(file);

    return 0;
}
