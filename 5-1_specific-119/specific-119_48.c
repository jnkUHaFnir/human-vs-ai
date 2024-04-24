#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct journal{
    int day;
    int month;
    int year;
    char* entry;
} Diary;

int main() {
    FILE* file = fopen("struct.txt", "r");
    if (file == NULL) {
        perror("Error opening file.");
        return 1;
    }

    int size, i = 0;
    Diary* res;
    char day[1024];
    char* token;
    
    fscanf(file, "%d", &size);
    res = (Diary*)malloc(size * sizeof(Diary));
    fscanf(file, "%*[^\n]");
    
    while (fgets(day, 1024, file) != NULL) {
        token = strtok(day, "/");
        res[i].day = atoi(token);
        token = strtok(NULL, "/");
        res[i].month = atoi(token);
        token = strtok(NULL, "/");
        res[i].year = atoi(token);
        
        token = strtok(day, "\n");
        // Dynamically allocate memory for the entry field
        res[i].entry = (char*)malloc(strlen(token) + 1);
        strncpy(res[i].entry, token, strlen(token) + 1);
        
        printf("%s", res[i].entry);
        i++;
    }

    // Do something with res...

    // Free dynamically allocated memory
    for (int j = 0; j < size; j++) {
        free(res[j].entry);
    }
    free(res);
    
    fclose(file);
    
    return 0;
}
