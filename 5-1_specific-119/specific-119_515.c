printf("filename:");
fgets(filename, FILENAME_MAX_SIZE, stdin);
// Remove the trailing newline character if present
filename[strcspn(filename, "\n")] = '\0';
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 10
#define FACTOR 2
#define FILENAME_MAX_SIZE 100

void openFile(FILE** file, char* filename) {
    int SIZE = INITIAL_SIZE;
    char* data;
    
    printf("filename:");
    fgets(filename, FILENAME_MAX_SIZE, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    if (!((*file) = fopen(filename, "r"))) {
        perror("Error:");
    } else {
        char c;
        int n = 0;

        if ((data = (char*)malloc(SIZE * sizeof(char))) == NULL) {
            perror("malloc:");
        }   

        while (fscanf((*file), " %c", &c) != EOF) {
            if (n < SIZE - 1) {
                data[n++] = c;
            } else {
                SIZE *= FACTOR;
                char* data2 = (char*)realloc(data, SIZE * sizeof(char));
                if (data2 != NULL) {
                    data = data2;
                    data[n++] = c;  
                } else {
                    free(data);
                    break;
                }
            }
        }

        data[n] = '\0'; // Add null terminator at the end of the string
        printf("Read data: %s\n", data);
        free(data);
    }
}

int main() {
    FILE* file;
    char filename[FILENAME_MAX_SIZE];
    openFile(&file, filename);
    fclose(file);
    return 0;
}
