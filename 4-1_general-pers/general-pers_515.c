#include <stdio.h>
#include <stdlib.h>

void openFile(FILE** file, char* filename) {
    int SIZE = 10;
    char *data = NULL, *data2;
    int n = 0;
    char c;
    
    printf("Enter filename: ");
    scanf("%s", filename);

    if (!(*file = fopen(filename, "r"))) {
        perror("Error opening file");
        return;
    }
    
    if (!(data = (char*)malloc(SIZE * sizeof(char)))) {
        perror("Error allocating memory");
        fclose(*file);
        return;
    }
    
    while (fscanf(*file, " %c", &c) != EOF) {
        if (n < SIZE) {
            data[n++] = c;
        } else {
            SIZE *= 2;
            if ((data2 = (char*)realloc(data, SIZE * sizeof(char))) != NULL) {
                data = data2;
                data[n++] = c;
            } else {
                perror("Error reallocating memory");
                free(data);
                fclose(*file);
                return;
            }
        }
    }
    
    // Process the data as needed
    
    free(data);
    fclose(*file);
}

int main() {
    FILE *file;
    char filename[255]; // Adjust the buffer size as needed

    openFile(&file, filename);
    
    return 0;
}
